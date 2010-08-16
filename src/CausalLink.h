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
/**
 * CausalLink.h: interface for the CausalLink class.
 *
 *  Created on: Aug 15, 2002
 *      Author: meneguzzi
 */

#if !defined(AFX_CAUSALLINK_H__F5C249CB_9B1B_4EE6_90D3_F6DF043309B0__INCLUDED_)
#define AFX_CAUSALLINK_H__F5C249CB_9B1B_4EE6_90D3_F6DF043309B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Debug.h"

#include "Operator.h"
#include "Predicate.h"

class CausalLink  
{
protected:
	Operator *oFulfills;
	Predicate *pCauses;
public:
	CausalLink();
	CausalLink(Operator *oFulfills, Predicate *pCauses);
	virtual ~CausalLink();

	bool fulfills(Operator *o);
	bool fulfilled(Predicate *p);

	CausalLink &operator=(CausalLink &clRight);
	string toString();
};

typedef vector<CausalLink> CausalLinkVector;

#endif // !defined(AFX_CAUSALLINK_H__F5C249CB_9B1B_4EE6_90D3_F6DF043309B0__INCLUDED_)
