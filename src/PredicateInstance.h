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
// PredicateInstance.h: interface for the PredicateInstance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREDICATEINSTANCE_H__A89BC83E_C458_4503_A44D_45BB31F1F5DE__INCLUDED_)
#define AFX_PREDICATEINSTANCE_H__A89BC83E_C458_4503_A44D_45BB31F1F5DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "TermInstance.h"
#include "Predicate.h"

class PredicateInstance  
{
protected:
	string sName;//Holds the name of the Predicate
	string sKey;//Holds the unique id key for the predicate instance
	string sPredicate;//Holds the Non-negated name of the predicate instance
	bool bNot;
	TermInstanceVector tivTerms;

	string makePredicate();
public:
	PredicateInstance();
	PredicateInstance(string sName, TermInstanceVector &tivTerms, bool bNot=false);
	virtual ~PredicateInstance();

	bool operator==(PredicateInstance &piRight);
	PredicateInstance &operator=(PredicateInstance &piRight);
	bool isMutex(PredicateInstance *pi);

	string getKey();
	string toString();

	static string getKey(Predicate *p);
};

typedef vector<PredicateInstance *> PredicateInstanceVector;

#endif // !defined(AFX_PREDICATEINSTANCE_H__A89BC83E_C458_4503_A44D_45BB31F1F5DE__INCLUDED_)
