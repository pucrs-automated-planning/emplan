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
// ParallelPlan.h: interface for the ParallelPlan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARALLELPLAN_H__76B7B1EC_DF7F_4175_B4CE_54C676593DC9__INCLUDED_)
#define AFX_PARALLELPLAN_H__76B7B1EC_DF7F_4175_B4CE_54C676593DC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;

#include "GroundPlan.h"
#include "OperatorInstance.h"

typedef vector<OperatorInstance *> ParallelPlanLevel;
typedef vector<ParallelPlanLevel> ParallelPlanLevelVector;

class ParallelPlan: public GroundPlan
{
protected:
	ParallelPlanLevelVector pplv;
public:
	ParallelPlan();
	ParallelPlan(int iSize);
	virtual ~ParallelPlan();

	void addAction(int iLevel, OperatorInstance *oiAction);
	ParallelPlanLevel &operator[](int iLevel);

	virtual OperatorInstanceVector toVector();

	virtual string toString(OperatorInstanceVector &oiv);
	virtual string toString();
};

#endif // !defined(AFX_PARALLELPLAN_H__76B7B1EC_DF7F_4175_B4CE_54C676593DC9__INCLUDED_)
