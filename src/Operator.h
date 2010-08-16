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
// Operator.h: interface for the Operator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined OPERATOR_H
#define OPERATOR_H

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <string>
using std::string;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Predicate.h"
#include "Debug.h"

class Operator  
{
protected:
	TermVector dnvParams;
	PredicateVector pvEffects;
	PredicateVector pvPreconds;
	string sName;
	TermMap *dnmVariables;

	Term *getVariable(Term *dgVar);
public:
	Operator(Operator *o, bool bPruneOld=false);
	Operator(const string &sName, TermVector dnvParams, PredicateVector pvPreconds, PredicateVector pvEffects, bool bMapVariables=true, bool bPrune=true);
	Operator();
	TermVector getParameters();
	PredicateVector getEffects();
	PredicateVector getPreconds();
	virtual string toString();
	virtual string toHeaderString();
	virtual ~Operator();
	const Operator &operator=(const Operator &oRight);
	bool isFullyInstantiated();
	bool isNotInstantiated();
	bool threatened(Predicate *pThreat);
	string getName();
	int getArity();
	void unbind();
private:
	void init(const string &sName, TermVector dnvParams, PredicateVector pvPreconds, PredicateVector pvEffects, bool bMapVariables, bool bPruneOld);
};

typedef vector<Operator*> OperatorVector;
typedef OperatorVector::iterator OperatorVectorIterator;

#endif // !defined(OPERATOR_H)
