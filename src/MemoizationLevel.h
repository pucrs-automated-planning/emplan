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
// MemoizationLevel.h: interface for the MemoizationLevel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMOIZATIONLEVEL_H__AFD51A47_01BE_45EC_8F6E_81ACA5F26C33__INCLUDED_)
#define AFX_MEMOIZATIONLEVEL_H__AFD51A47_01BE_45EC_8F6E_81ACA5F26C33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
using std::map;
using std::less;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <algorithm>
using std::sort;

typedef vector<int> IntVector;
typedef map<string, bool, less<string> > IntVectorMap;

class MemoizationLevel
{
protected:
	IntVectorMap ivmNoGoods;

	string makeKey(IntVector &iv);
	string intToKey(int i);
public:
	MemoizationLevel();
	virtual ~MemoizationLevel();

	bool isNoGood(IntVector &ivGoals);
	void addNoGood(IntVector &ivGoals);

	int size();

	string toString();
};

#endif // !defined(AFX_MEMOIZATIONLEVEL_H__AFD51A47_01BE_45EC_8F6E_81ACA5F26C33__INCLUDED_)
