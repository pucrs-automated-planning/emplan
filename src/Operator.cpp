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
// Operator.cpp: implementation of the Operator class.
//
//////////////////////////////////////////////////////////////////////

#include "Operator.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Operator::Operator()
{
	this->sName="";
	this->dnmVariables=NULL;
}

Operator::~Operator()
{
	for(PredicateVector::iterator i=pvPreconds.begin(); i!=pvPreconds.end(); i++)
	{
		//PRINTL((*i)->toString())
		delete *i;
	}

	for(PredicateVector::iterator i2=pvEffects.begin(); i2!=pvEffects.end(); i2++)
	{
		delete *i2;
	}

	for(TermVector::iterator i3=dnvParams.begin();
		i3!=dnvParams.end(); i3++)
	{
		delete *i3;
	}

	delete dnmVariables;
}

//////////////////////////////////////////////////////////////////////
// Constructor that takes makes an operator out of its components
// The bPruneOld parameter states that the pointers given as input
// are to be delete while they are being put into the new operator
//////////////////////////////////////////////////////////////////////
Operator::Operator(const string &sName, TermVector dnvParams, PredicateVector pvPreconds, PredicateVector pvEffects, bool bMapVariables, bool bPruneOld)
{
	this->init(sName, dnvParams, pvPreconds, pvEffects, bMapVariables, bPruneOld);
}

//////////////////////////////////////////////////////////////////////
// Constructor that copies another operator into it and possibly
// deletes the operator given as input depending on the bPruneOlb
// parameter
//////////////////////////////////////////////////////////////////////
Operator::Operator(Operator *o, bool bPruneOld)
{
	this->init(o->sName, o->dnvParams, o->pvPreconds, o->pvEffects, (o->dnmVariables!=NULL), bPruneOld);
}

void Operator::init(const string &sName, TermVector dnvParams, PredicateVector pvPreconds, PredicateVector pvEffects, bool bMapVariables, bool bPruneOld)
{
	this->sName=sName;

	if(bMapVariables)
	{
		this->dnmVariables=new TermMap();

		for(TermVector::iterator i=dnvParams.begin(); i!=dnvParams.end(); i++)
		{
			Term *dnOld=*i;
			Term *dn;
			if(dnOld->isVariable())
				dn=getVariable(dnOld);
			else
				dn=new Term(dnOld, this->dnmVariables);
			
			this->dnvParams.push_back(dn);
			if(bPruneOld)
				delete dnOld;
		}
			
		for(PredicateVector::iterator i2=pvPreconds.begin(); i2!=pvPreconds.end(); i2++)
		{
			Predicate *pOld=*i2;
			Term *dnOld=pOld->getTerm();
			
			Term *dn=new Term(dnOld, this->dnmVariables);
			Predicate *p=new Predicate(dn, this->dnmVariables,pOld->isNegative());

			this->pvPreconds.push_back(p);
			if(bPruneOld)
				delete pOld;
		}

		for(PredicateVector::iterator i3=pvEffects.begin(); i3!=pvEffects.end(); i3++)
		{
			Predicate *pOld=*i3;
			Term *dnOld=pOld->getTerm();
				
			Term *dn=new Term(dnOld, this->dnmVariables);
			Predicate *p=new Predicate(dn, this->dnmVariables,pOld->isNegative());

			this->pvEffects.push_back(p);
			if(bPruneOld)
				delete pOld;
		}

	}else
	{
		this->dnvParams=dnvParams;
		this->pvPreconds=pvPreconds;
		this->pvEffects=pvEffects;
		this->dnmVariables=NULL;
	}
}


Term *Operator::getVariable(Term *dgVar)
{
	if(!dgVar->isVariable())
		return NULL;
	string sVarName=dgVar->getName();

	if(dnmVariables!=NULL)//If there is a variable mapping
	{
		//Try to find a pointer to the specific variable
		if(dnmVariables->find(sVarName) != dnmVariables->end())//if the pointer is found
			return (*dnmVariables)[sVarName];//return it
		else
		{
			//Create a new free Variable
			Term *dgNew=new Term(dgVar, this->dnmVariables);
			//Insert it into the map
			(*dnmVariables)[sVarName]=dgNew;
			return dgNew;//return NULL;
		}
	}else//if not return any variable
		return new Term(sVarName, true);
	return NULL;
}

const Operator &Operator::operator=(const Operator &oRight)
{
	if(this!=&oRight)
	{
		this->sName=oRight.sName;
		this->dnvParams=oRight.dnvParams;
		this->pvPreconds=oRight.pvPreconds;
		this->pvEffects=oRight.pvEffects;
		this->dnmVariables=oRight.dnmVariables;
	}

	return *this;
}

string Operator::toString()
{
	string sRes="[(Operator)";

	sRes+=this->sName;

	sRes+="(";
	for(TermVector::iterator i=dnvParams.begin(); i!=dnvParams.end(); i++)
	{
		if(i!=dnvParams.begin())
			sRes+=", ";
		sRes+=(*i)->toString();
	}
	sRes+=")";

	sRes+="\n\tpreconds(";

	for(PredicateVectorIterator i2=pvPreconds.begin(); i2!=pvPreconds.end(); i2++)
	{
		if(i2!=pvPreconds.begin())
			sRes+=", \n\t\t";
		sRes+=(*i2)->toString();
	}

	sRes+=")\n\teffects(";

	for(PredicateVectorIterator i3=pvEffects.begin(); i3!=pvEffects.end(); i3++)
	{
		if(i3!=pvEffects.begin())
			sRes+=", \n\t\t";
		sRes+=(*i3)->toString();
	}

	sRes+=")";

	if(this->dnmVariables!=NULL)
	{
		sRes+="\n\tVariable Mapping {";
		for(TermMap::iterator i=dnmVariables->begin(); i!=dnmVariables->end(); i++)
		{
			if(i!=dnmVariables->begin())
				sRes+=", ";
			sRes+=i->second->toString();
		}
		sRes+="}";
	}

	return sRes;
}

string Operator::toHeaderString()
{
	string sRes;
	sRes=this->sName;

	sRes+="(";
	for(TermVector::iterator i=dnvParams.begin(); i!=dnvParams.end(); i++)
	{
		if(i!=dnvParams.begin())
			sRes+=", ";
		sRes+=(*i)->toString();
	}
	sRes+=")";

	return sRes;
}

TermVector Operator::getParameters()
{
	return this->dnvParams;
}

PredicateVector Operator::getPreconds()
{
	return this->pvPreconds;
}

PredicateVector Operator::getEffects()
{
	return this->pvEffects;
}

bool Operator::isFullyInstantiated()
{
	bool bRes=true;

	//Iterate through the map
	for(TermMap::iterator i=dnmVariables->begin(); (i!=dnmVariables->end() && bRes); i++)
	{
		//The actual entry is the "second" field in the iterator
		//If its binding is NULL then it is not instantiated
		//So the loop will end through the bRes state in the "&& bRes" condition above
		bRes &= (i->second->getBinding()!=NULL);
	}

	return bRes;
}

//Determines if the Operator has no variable bindings
bool Operator::isNotInstantiated()
{
	bool bRes=true;
	
	for(TermMap::iterator i=dnmVariables->begin(); (i!=dnmVariables->end() && bRes); i++)
	{
		//The actual entry is the "second" field in the iterator
		//If its binding is NULL then it is not instantiated
		//So the loop will end through the bRes state in the "&& bRes" condition above
		bRes &= (i->second->getBinding()==NULL);
	}

	return bRes;
}

//Determines if the referred predicate threatens this step of the plan
bool Operator::threatened(Predicate *pThreat)
{
	if(!this->isFullyInstantiated())
		return false;

	for(PredicateVector::iterator i=pvPreconds.begin(); i!=pvPreconds.end(); i++)
	{
		Predicate *p=*i;
		if(pThreat->isNegative()!=p->isNegative() && ( (*pThreat)==(*p) ))
			return true;
	}

	return false;
}

string Operator::getName()
{
	return sName;
}

int Operator::getArity()
{
	return this->dnvParams.size();
}

void Operator::unbind()
{
	for(TermMap::iterator i=dnmVariables->begin(); i!=dnmVariables->end(); i++)
	{
		i->second->unbind();
	}
}
