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
// Predicate.h: interface for the Predicate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined PREDICATE_H
#define PREDICATE_H

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <string>
using std::string;

#include "Term.h"
#include "Debug.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Predicate  
{
protected:
	Term *dnPredicate;
	TermMap *dnmVariables;
	bool bNot;
public:
	Predicate();
	Predicate(Predicate *p, TermMap *dnmVariables);
	Predicate(Term *dnPredicate, bool bNot=false);
	Predicate(Term *dnPredicate, TermMap *dnmVariables, bool bNot=false);

	bool isNegative();
	Term * getTerm();
	virtual ~Predicate();

	const Predicate &operator =(const Predicate &pRight);
	const bool operator ==(const Predicate &pRight);

	void flip();

	const TermVector getTerms();
	int getArity();
	string getName();

	TermMap *getVariables();

	virtual string toString();

	void unbind();
};

typedef vector<Predicate *> PredicateVector;
typedef PredicateVector::iterator PredicateVectorIterator;

#endif // !defined(PREDICATE_H)
