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
// PredicateSignature.h: interface for the PredicateSignature class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREDICATESIGNATURE_H__54B7622D_F986_4EAC_979B_42489E092C34__INCLUDED_)
#define AFX_PREDICATESIGNATURE_H__54B7622D_F986_4EAC_979B_42489E092C34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Signature.h"
#include "Predicate.h"

#include <sstream>
using std::ostringstream;

class PredicateSignature : public Signature  
{
protected:
	Predicate *pSignature;

	Predicate *makeSignaturePredicate(string sName, int iArity);
public:
	PredicateSignature();
	PredicateSignature(Predicate *p);
	virtual ~PredicateSignature();

	Predicate *getPredicate();
	virtual string toString();

	static string getSignature(Predicate *p);

	PredicateSignature &operator=(PredicateSignature &pRight);
};

#endif // !defined(AFX_PREDICATESIGNATURE_H__54B7622D_F986_4EAC_979B_42489E092C34__INCLUDED_)
