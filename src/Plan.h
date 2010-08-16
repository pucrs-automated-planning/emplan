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
// Plan.h: interface for the Plan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAN_H__D00E23DC_49FB_487B_AB21_886A1BDB9C36__INCLUDED_)
#define AFX_PLAN_H__D00E23DC_49FB_487B_AB21_886A1BDB9C36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include "Operator.h"

class Plan  
{
public:
	Plan();
	virtual ~Plan();

	virtual OperatorVector toVector();

	virtual string toString();
};

#endif // !defined(AFX_PLAN_H__D00E23DC_49FB_487B_AB21_886A1BDB9C36__INCLUDED_)
