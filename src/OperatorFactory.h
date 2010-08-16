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
// OperatorFactory.h: interface for the OperatorFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORFACTORY_H__F969A0C6_1D37_41AA_9E7C_1DDE76336697__INCLUDED_)
#define AFX_OPERATORFACTORY_H__F969A0C6_1D37_41AA_9E7C_1DDE76336697__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <algorithm>
using std::find;

#include "Predicate.h"
#include "Term.h"
#include "Operator.h"

class OperatorFactory  
{
public:
	static Operator * newOperator(const string &sOperator, TermVector *dnvParams, PredicateVector *pvPreconds, PredicateVector *pvEffects);
	static bool checkOperator(const string &sOperator, TermVector *dnvParams, PredicateVector *pvPreconds, PredicateVector *pvEffects);
	OperatorFactory();
	virtual ~OperatorFactory();

};

#endif // !defined(AFX_OPERATORFACTORY_H__F969A0C6_1D37_41AA_9E7C_1DDE76336697__INCLUDED_)
