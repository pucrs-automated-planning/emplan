//---------------------------------------------------------------------------
//Copyright (C) 2010 Felipe Meneguzzi
//EmPlan is distributed under LGPL. See file LGPL.txt in this directory.
//
//This library is free software; you can redistribute it and/or
//modify it under the terms of the GNU Lesser General Public
//License as published by the Free Software Foundation; either
//version 2.1 of the License, or (at your option) any later version.
//
//This library is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//Lesser General Public License for more details.
//
//You should have received a copy of the GNU Lesser General Public
//License along with this library; if not, write to the Free Software
//Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//To contact the author:
//http://www.meneguzzi.eu/felipe/contact.html
//---------------------------------------------------------------------------
// GroundDataTable.cpp: implementation of the GroundDataTable class.
//
//////////////////////////////////////////////////////////////////////

#include "GroundDataTable.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GroundDataTable::GroundDataTable()
{

}

//////////////////////////////////////////////////////////////////////
// Creates the Ground Data based on Signatures collected in the parse
// process
//////////////////////////////////////////////////////////////////////
GroundDataTable::GroundDataTable(TermSignatureMap &tsm, PredicateSignatureMap &psm, OperatorSignatureMap &osm)
{
	this->createTermInstances(tsm);
	//PRINTL(this->toString())
	this->createPredicateInstances(tsm, psm);
	//PRINTL(this->toString())
	this->createOperatorInstances(tsm, osm);
	this->createMaintenanceOperators();
}

GroundDataTable::~GroundDataTable()
{
	for(TermInstanceMap::iterator i=timTerms.begin(); i!=timTerms.end(); i++)
	{
		delete i->second;
	}

	for(PredicateInstanceMap::iterator j=pimPredicates.begin(); j!=pimPredicates.end(); j++)
	{
		delete j->second;
	}

	for(OperatorInstanceMap::iterator k=oimOperators.begin(); k!=oimOperators.end(); k++)
	{
		delete k->second;
	}
}

//////////////////////////////////////////////////////////////////////
// Creates the term instances given a set of signatures
//////////////////////////////////////////////////////////////////////
void GroundDataTable::createTermInstances(TermSignatureMap &tsm)
{
	for(TermSignatureMap::iterator i=tsm.begin(); i!=tsm.end(); i++)
	{
		TermSignature *ts=i->second;
		Term *t=ts->getTerm();
		//PRINTL(t->toString())
		this->addTermInstance(t);
	}
}

//////////////////////////////////////////////////////////////////////
// Creates the predicate instances based on the signatures given
// as parameter
//////////////////////////////////////////////////////////////////////
void GroundDataTable::createPredicateInstances(TermSignatureMap &tsm, PredicateSignatureMap &psm)
{
	//For every predicate siganture given, we create every possible
	//instantiation of it given the terms in the Herbrand universe
	for(PredicateSignatureMap::iterator i=psm.begin(); i!=psm.end(); i++)
	{
		Predicate *p=i->second->getPredicate();
		TermVector tv=p->getTerms();

		//If the predicate has fluents but there is no object in the
		//Herbrand universe to unify with those fluents, then we should
		//not create that predicate instance
		if(tv.size()>0 && tsm.size() <=0)
			continue;
		
		TSMIterator iv(tv.size());
	
		//The "for" loop below was dropped due to problems
		//in the function detecting a full cicle in the 
		//iterators, the advancement function was used to
		//detect the cicle instead

		//for(initializeIterators(tsm, iv); 
		//	!iteratorsFinished(tsm, iv); 
		//	advanceIterators(tsm, iv))
		
		bool bEnd=false;

		//Start the iterators with the begining of the map containing every possible term
		for(initializeIterators(tsm, iv);//Initialize a vector of Signature iterators
			!bEnd;//And increment them until they complete a cicle
			bEnd=advanceIterators(tsm, iv))
		{
			//Bind the variables in the predicate signature with the objects selected
			bindVariables(tv, iv);
			//PRINTL(p->toString())
			//Add the predicate
			this->addPredicateInstance(p);
			//PRINTL("Added predicate:\"" << this->getPredicateInstance(PredicateInstance::getKey(p))->toString() <<"\"\n")
			//And its opposite through the flip method
			p->flip();
			this->addPredicateInstance(p);
			//PRINTL("Added predicate:\"" << this->getPredicateInstance(PredicateInstance::getKey(p))->toString() <<"\"\n")
			p->unbind();
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Creates the operator instances based on the signatures given
// as parameter
//////////////////////////////////////////////////////////////////////
void GroundDataTable::createOperatorInstances(TermSignatureMap &tsm, OperatorSignatureMap &osm)
{
	//For every operator signature given, instantiate it with every possible
	//object in the herbrand base
	for(OperatorSignatureMap::iterator i=osm.begin(); i!=osm.end(); i++)
	{
		Operator *o=i->second->getOperator();
		TermVector tv=o->getParameters();

		//If the operator has parameters but there is no object in the
		//Herbrand universe to unify with those parameters, then we should
		//not create that operator instance
		if(tv.size()>0 && tsm.size() <= 0)
			continue;

		TSMIterator iv(tv.size());

		bool bEnd=false;
		//Start the iterators with the begining of the map containing every possible term
		for(initializeIterators(tsm, iv);//Initialize a vector of Signature iterators
			!bEnd;//And increment them until they complete a cicle
			bEnd=advanceIterators(tsm, iv))
		{
			//Bind the variables in the operator signature with the objects selected
			bindVariables(tv, iv);
			
			//PRINTL("I'm going to print the table")
			//PRINTL(this->toString())
			
			//Put the self consistency check here
			this->addOperatorInstance(o);
			o->unbind();
			
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Creates the no-op operators, that is operators that has
// the same term as the only precondition and effect
//////////////////////////////////////////////////////////////////////
void GroundDataTable::createMaintenanceOperators()
{
	for(PredicateInstanceMap::iterator i=pimPredicates.begin(); i!=pimPredicates.end(); i++)
	{
		//PRINTL(this->toString())
		PredicateInstance *pi=i->second;
		string sName="_nop"+pi->getKey();
		
		PredicateInstanceVector piv(1);
		piv[0]=pi;

		TermInstanceVector tiv;

		OperatorInstance *oi=new OperatorInstance(sName, tiv, piv, piv, true);

		//God willing there will be no name conflict with these operators
		string sKey=oi->getKey();
		oimOperators[sKey]=oi;
	}
}

//////////////////////////////////////////////////////////////////////
// This method initializes the iterators that represent the 
// possibilities of instantiation for a given set of variables
//////////////////////////////////////////////////////////////////////
void GroundDataTable::initializeIterators(TermSignatureMap &tsm, TSMIterator &iv)
{
	for(int i=0; i<iv.size(); i++)
	{
		iv[i]=tsm.begin();
	}
}

//////////////////////////////////////////////////////////////////////
// This was initially used to detect the round trip among the iterators, 
//but it was dropped since the advanceIterators method would never 
//make all the iterators reach the end due to its resetting of the 
//iterators in the end. The solution was to detect the round trip in 
//the advancement method itself.
//////////////////////////////////////////////////////////////////////
bool GroundDataTable::iteratorsFinished(TermSignatureMap &tsm, TSMIterator &iv)
{
	bool bRes=true;

	for(TSMIterator::iterator i=iv.begin(); (bRes && i!=iv.end()); i++)
	{
		bRes &= (*i)==tsm.end();
	}

	return bRes;
}

//////////////////////////////////////////////////////////////////////
//Advances the iterators in the same manner an arabic number is increased,
//that is, when a given algarism reaches its final position, the subsequent
//algarisms are increased and the previous algarisms are reset,
//returns true when the iterators have done a complete cycle among all the iterators.
//////////////////////////////////////////////////////////////////////
bool GroundDataTable::advanceIterators(TermSignatureMap &tsm, TSMIterator &iv)
{
	bool bAdvanceNext=true;
	bool bRes=(iv.size()==0);//If the referred parameter list is empty, then no
							//initialization is necessary
	for(TSMIterator::iterator i=iv.begin(); (bAdvanceNext && i!=iv.end()); i++)
	{
		(*i)++;//Increment the iterator pointed to by the iterator
		if((*i)==tsm.end())
		{
			(*i)=tsm.begin();
			if((i+1)==iv.end())
				bRes=true;
		}else
			bAdvanceNext=false;
	}

	return bRes;
}

//////////////////////////////////////////////////////////////////////
//Binds the variables stored in the TermVector argument to the terms
//pointed to by the iterators contained in the vector "iv"
//////////////////////////////////////////////////////////////////////
void GroundDataTable::bindVariables(TermVector &tv, TSMIterator &iv)
{
	for(int i=0; i<tv.size(); i++)
	{
		Term *tObject=iv[i]->second->getTerm();
		tv[i]->bind(tObject);
	}
}

//////////////////////////////////////////////////////////////////////
//Converts a Term in the non-ground format to its corresponding
//ground instance and adds it to the ground instances table
//////////////////////////////////////////////////////////////////////
TermInstance *GroundDataTable::addTermInstance(Term *t)
{
	string sKey=TermInstance::getKey(t);

	TermInstance *ti;

	if(timTerms.find(sKey)==timTerms.end())
	{
		ti=new TermInstance(t->getName());
		timTerms[sKey]=ti;
	}else
	{
		ti=timTerms[sKey];
	}

	return ti;
}

//////////////////////////////////////////////////////////////////////
//Converts a Predicate in the non-ground format to its corresponding
//ground instance and adds it to the ground instances table
//////////////////////////////////////////////////////////////////////
PredicateInstance *GroundDataTable::addPredicateInstance(Predicate *p)
{
	string sKey=PredicateInstance::getKey(p);

	//PRINTL("Original Key\"" << sKey <<"\"")

	PredicateInstance *pi;

	if(pimPredicates.find(sKey)==pimPredicates.end())
	{
		TermVector tv=p->getTerms();
		TermInstanceVector tiv;
		tiv.resize(tv.size());

		for(int i=0; i<tv.size(); i++)
		{
			Term *t=tv[i];
			TermInstance *ti=this->getTermInstance(TermInstance::getKey(t));
			tiv[i]=ti;
		}

		pi=new PredicateInstance(p->getName(), tiv, p->isNegative());
		//PRINTL("Generated Key\"" << pi->getKey() <<"\"")
		pimPredicates[sKey]=pi;
	}else
		pi=pimPredicates[sKey];

	//PRINTL("Added:\"" << pimPredicates[sKey]->toString() << "\"\n")

	return pi;
}

//////////////////////////////////////////////////////////////////////
//Converts an Operator in the non-ground format to its corresponding
//ground instance and adds it to the ground instances table
//////////////////////////////////////////////////////////////////////
OperatorInstance *GroundDataTable::addOperatorInstance(Operator *o)
{
	string sKey=OperatorInstance::getKey(o);

	OperatorInstance *oi;

	if(oimOperators.find(sKey)==oimOperators.end())
	{
		TermVector tvParameters=o->getParameters();
		TermInstanceVector tivParameters;
		tivParameters.resize(tvParameters.size());

		for(int i=0; i<tvParameters.size(); i++)
		{
			Term *t=tvParameters[i];
			TermInstance *ti=this->getTermInstance(TermInstance::getKey(t));
			tivParameters[i]=ti;
		}

		PredicateVector pvPreconditions=o->getPreconds();
		PredicateInstanceVector pivPreconditions;
		pivPreconditions.resize(pvPreconditions.size());

		for(int i=0; i<pvPreconditions.size(); i++)
		{
			Predicate *p=pvPreconditions[i];
			PredicateInstance *pi=this->getPredicateInstance(PredicateInstance::getKey(p));
			pivPreconditions[i]=pi;
		}
		
		PredicateVector pvEffects=o->getEffects();
		PredicateInstanceVector pivEffects;
		pivEffects.resize(pvEffects.size());

		for(int i=0; i<pvEffects.size(); i++)
		{
			Predicate *p=pvEffects[i];
			//PRINTL(this->toString())
			PredicateInstance *pi=this->getPredicateInstance(PredicateInstance::getKey(p));
			pivEffects[i]=pi;
		}

		oi=new OperatorInstance(o->getName(), tivParameters, pivPreconditions, pivEffects);
		if(oi->selfConsistent())
			oimOperators[sKey]=oi;
		else
			delete oi;
	}else
		oi=oimOperators[sKey];

	return oi;
}

//////////////////////////////////////////////////////////////////////
//Returns the ground instance corresponding to the key passed
//in the parameter
//////////////////////////////////////////////////////////////////////
TermInstance *GroundDataTable::getTermInstance(string sKey)
{
	TermInstanceMap::iterator i=timTerms.find(sKey);
	if(i!=timTerms.end())
		return i->second;
	else
	{
		PRINTL("Problems finding the ground instance for: " << sKey)
		return NULL;
	}
}

//////////////////////////////////////////////////////////////////////
//Returns the ground instance corresponding to the key passed
//in the parameter
//////////////////////////////////////////////////////////////////////
PredicateInstance *GroundDataTable::getPredicateInstance(string sKey)
{
	PredicateInstanceMap::iterator i=pimPredicates.find(sKey);
	if(i!=pimPredicates.end())
		return i->second;
	else
	{
		PRINTL("Problems finding the ground instance for: " << sKey)
		return NULL;
	}
}

//////////////////////////////////////////////////////////////////////
//Returns the ground instance corresponding to the key passed
//in the parameter
//////////////////////////////////////////////////////////////////////
OperatorInstance *GroundDataTable::getOperatorInstance(string sKey)
{
	OperatorInstanceMap::iterator i=oimOperators.find(sKey);
	if(i!=oimOperators.end())
		return i->second;
	else
	{
		PRINTL("Problems finding the ground instance for: " << sKey)
		return NULL;
	}
}


//////////////////////////////////////////////////////////////////////
//Converts a vector of Predicates in the Non-ground format to its corresponding
//Ground Instances
//////////////////////////////////////////////////////////////////////
PredicateInstanceVector GroundDataTable::convertPredicates(PredicateVector pv)
{
	PredicateInstanceVector pivRes(pv.size());

	for(int i=0; i<pv.size(); i++)
	{
		PredicateInstance *pi=this->getPredicateInstance(PredicateInstance::getKey(pv[i]));
		pivRes[i]=pi;
	}

	return pivRes;
}

//////////////////////////////////////////////////////////////////////
//Returns all the operators stored in the table as a vector
//////////////////////////////////////////////////////////////////////
OperatorInstanceVector GroundDataTable::getOperators()
{
	OperatorInstanceVector oivRes;

	for(OperatorInstanceMap::iterator i=oimOperators.begin(); i!=oimOperators.end(); i++)
	{
		oivRes.push_back(i->second);
	}

	return oivRes;
}

//////////////////////////////////////////////////////////////////////
//Creates a string representation of the Ground Data Table, containing all the
//ground Terms, Predicates and Operators
//////////////////////////////////////////////////////////////////////
string GroundDataTable::toString()
{
	ostringstream out;
	
	out << "Ground Data:";

	out << "\n\tTerms:";
	for(TermInstanceMap::iterator i=timTerms.begin(); i!=timTerms.end(); i++)
	{
		//sRes+="\n\t\t"+i->first;
		out << "\n\t\t"+i->second->toString();
	}

	out << "\n\tPredicates:";
	for(PredicateInstanceMap::iterator j=pimPredicates.begin(); j!=pimPredicates.end(); j++)
	{
		//sRes+="\n\t\t"+j->first;
		out << "\n\t\t"+j->second->toString();
	}

	out << "\n\tOperators:";
	for(OperatorInstanceMap::iterator k=oimOperators.begin(); k!=oimOperators.end(); k++)
	{
		//sRes+="\n\t\t"+k->first;
		out << "\n\t"+k->second->toString() << "\n";
	}

	out << "Number of Terms in Herbrand Universe: " << timTerms.size() << "\n";
	out << "Number of Predicates in Herbrand Universe: " << pimPredicates.size() << "\n";
	out << "Number of actions in Herbrand Universe: " << oimOperators.size() << "\n";

	return out.str();
}
