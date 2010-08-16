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
// SymbolTable.cpp: implementation of the SymbolTable class.
//
//////////////////////////////////////////////////////////////////////

#include "SymbolTable.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SymbolTable::SymbolTable()
{

}

SymbolTable::~SymbolTable()
{
	for(TermSignatureMap::iterator i=tsmTerms.begin(); i!=tsmTerms.end(); i++)
	{
		delete i->second;
	}

	for(PredicateSignatureMap::iterator j=psmPredicates.begin(); j!=psmPredicates.end(); j++)
	{
		delete j->second;
	}

	for(OperatorSignatureMap::iterator k=osmOperators.begin(); k!=osmOperators.end(); k++)
	{
		delete k->second;
	}
}

//////////////////////////////////////////////////////////////////////
// Returns a string representation of the Table
//////////////////////////////////////////////////////////////////////
string SymbolTable::toString()
{
	string sRes="**** SymbolTable ****";
	
	sRes+="\n\tTerms:";
	for(TermSignatureMap::iterator i=tsmTerms.begin(); i!=tsmTerms.end(); i++)
	{
		sRes+="\n\t\t"+i->first;
		//sRes+="\n\t\t"+i->second->toString();
	}

	sRes+="\n\n\tPredicates:";
	for(PredicateSignatureMap::iterator j=psmPredicates.begin(); j!=psmPredicates.end(); j++)
	{
		sRes+="\n\t\t"+j->first;
	}

	sRes+="\n\n\tOperators:";
	for(OperatorSignatureMap::iterator k=osmOperators.begin(); k!=osmOperators.end(); k++)
	{
		sRes+="\n\t\t"+k->first;
	}

	return sRes;
}

//////////////////////////////////////////////////////////////////////
// Registers a term into the Table if it has not yet been registered
//////////////////////////////////////////////////////////////////////
void SymbolTable::registerTerm(Term *t)
{
	string sKey=TermSignature::getSignature(t);
	if( (!t->isVariable()) && tsmTerms.find(sKey)==tsmTerms.end())
	{
		TermSignature *ts=new TermSignature(t);
		tsmTerms[sKey]=ts;
	}
}

//////////////////////////////////////////////////////////////////////
// Registers a Predicate into the Table if it has not yet been 
// registered
//////////////////////////////////////////////////////////////////////
void SymbolTable::registerPredicate(Predicate *p)
{
	string sKey=PredicateSignature::getSignature(p);
	if(psmPredicates.find(sKey)==psmPredicates.end())
	{
		PredicateSignature *ps=new PredicateSignature(p);
		psmPredicates[sKey]=ps;
	}
}

//////////////////////////////////////////////////////////////////////
// Registers an Operator into the Table if it has not yet been 
// registered
//////////////////////////////////////////////////////////////////////
void SymbolTable::registerOperator(Operator *o)
{
	string sKey=OperatorSignature::getSignature(o);
	if(osmOperators.find(sKey)==osmOperators.end())
	{
		OperatorSignature *os= new OperatorSignature(o);
		osmOperators[sKey]=os;
	}
}

//////////////////////////////////////////////////////////////////////
// Returns all the Terms that have been registered in the table 
//////////////////////////////////////////////////////////////////////
TermSignatureMap SymbolTable::getTermSignatures()
{
	return this->tsmTerms;
}

//////////////////////////////////////////////////////////////////////
// Returns all the Predicates that have been registered in the table 
//////////////////////////////////////////////////////////////////////
PredicateSignatureMap SymbolTable::getPredicateSignatures()
{
	return this->psmPredicates;
}

//////////////////////////////////////////////////////////////////////
// Returns all the Operators that have been registered in the table 
//////////////////////////////////////////////////////////////////////
OperatorSignatureMap SymbolTable::getOperatorSignatures()
{
	return this->osmOperators;
}
