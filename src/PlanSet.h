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
// PlanSet.h: interface for the PlanSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANSET_H__B64647A1_6482_4F14_BC1C_52299F9CB23A__INCLUDED_)
#define AFX_PLANSET_H__B64647A1_6482_4F14_BC1C_52299F9CB23A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include "OperatorInstance.h"
#include "ParallelPlan.h"

//////////////////////////////////////////////////////////////////////
// Server only as a holder for multiple plans
//////////////////////////////////////////////////////////////////////
class PlanSet  
{
	typedef vector<ParallelPlan> PlanVector;
protected:
	PlanVector pvPlans;
public:
	PlanSet();
	virtual ~PlanSet();

	ParallelPlan &operator[](int i);
	void addPlan(ParallelPlan &pp);
	int size();
};

#endif // !defined(AFX_PLANSET_H__B64647A1_6482_4F14_BC1C_52299F9CB23A__INCLUDED_)
