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
// OperatorSignature.h: interface for the OperatorSignature class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORSIGNATURE_H__7E865286_1846_4564_8BA0_D747DD8DC345__INCLUDED_)
#define AFX_OPERATORSIGNATURE_H__7E865286_1846_4564_8BA0_D747DD8DC345__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Signature.h"
#include "Operator.h"
#include "Predicate.h"
#include "Term.h"

#include <sstream>
using std::ostringstream;

class OperatorSignature : public Signature  
{
protected:
	Operator *oSignature;
public:
	OperatorSignature();
	OperatorSignature(Operator *o);
	virtual ~OperatorSignature();
	
	static string getSignature(Operator *o);

	OperatorSignature & operator=(OperatorSignature &oRight);

	Operator *getOperator();

	virtual string toString();
};

#endif // !defined(AFX_OPERATORSIGNATURE_H__7E865286_1846_4564_8BA0_D747DD8DC345__INCLUDED_)
