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
// OperatorInstance.h: interface for the OperatorInstance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORINSTANCE_H__2A19C883_7D57_4D53_8E87_93BFDF2F3AA0__INCLUDED_)
#define AFX_OPERATORINSTANCE_H__2A19C883_7D57_4D53_8E87_93BFDF2F3AA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Operator.h"
#include "TermInstance.h"
#include "PredicateInstance.h"

class OperatorInstance  
{
protected:
	bool bNoop;
	string sName;
	string sKey;
	
	TermInstanceVector tivParameters;
	PredicateInstanceVector pivPreconditions;
	PredicateInstanceVector pivEffects;

	string makeKey();
public:
	OperatorInstance();
	OperatorInstance(string sName, 
					TermInstanceVector &tivParameters, 
					PredicateInstanceVector &pivPreconditions, 
					PredicateInstanceVector &pivEffects,
					bool bNoop=false);

	virtual ~OperatorInstance();
	
	bool operator==(OperatorInstance &oiRight);
	OperatorInstance & operator=(OperatorInstance &oiRight);
	bool isMutex(OperatorInstance *oi);

	PredicateInstanceVector getPreconditions();
	PredicateInstanceVector getEffects();

	bool fulfills(PredicateInstance *piEffect);
	bool requires(PredicateInstance *piPrecondition);
	bool requiresNothing();
	bool selfConsistent();

	bool isNoop();

	string getKey();
	string toString();

	static string getKey(Operator *o);
};

typedef vector<OperatorInstance *> OperatorInstanceVector;

#endif // !defined(AFX_OPERATORINSTANCE_H__2A19C883_7D57_4D53_8E87_93BFDF2F3AA0__INCLUDED_)
