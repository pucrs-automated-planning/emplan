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
// MemoizationTable.h: interface for the MemoizationTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMOIZATIONTABLE_H__ADFBD32D_15D7_4369_9312_47ADCAE0FF1E__INCLUDED_)
#define AFX_MEMOIZATIONTABLE_H__ADFBD32D_15D7_4369_9312_47ADCAE0FF1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::less;

#include "Debug.h"

#include "MemoizationLevel.h"

typedef vector<MemoizationLevel> MemoizationLevels;

class MemoizationTable
{
protected:
	MemoizationLevels mlNoGoods;
public:
	MemoizationTable();
	virtual ~MemoizationTable();

	bool isNoGood(int iPredicateLevel, IntVector &ivGoals);
	void addNoGood(int iPredicateLevel, IntVector &ivGoals);

	MemoizationLevel &operator[](int iPredicateLevel);

	bool planPossible(int iPredicateLevel);

	string toString();
};

#endif // !defined(AFX_MEMOIZATIONTABLE_H__ADFBD32D_15D7_4369_9312_47ADCAE0FF1E__INCLUDED_)
