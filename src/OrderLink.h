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
// OrderLink.h: interface for the OrderLink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORDERLINK_H__EDEADAD8_0DD8_4A98_AF72_C29ED70823A1__INCLUDED_)
#define AFX_ORDERLINK_H__EDEADAD8_0DD8_4A98_AF72_C29ED70823A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

#include "Operator.h"

class OrderLink  
{
protected:
	Operator *oBefore;
	Operator *oAfter;
public:
	OrderLink();
	OrderLink(Operator *oBefore, Operator *oAfter);
	virtual ~OrderLink();

	bool before(Operator *oBefore, Operator *oAfter);
	OrderLink &operator=(OrderLink &olRight);

	string toString();
};

typedef vector<OrderLink> OrderLinkVector;

#endif // !defined(AFX_ORDERLINK_H__EDEADAD8_0DD8_4A98_AF72_C29ED70823A1__INCLUDED_)
