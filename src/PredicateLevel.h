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
// PredicateLevel.h: interface for the PredicateLevel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREDICATELEVEL_H__8CA05E38_22D4_4A75_8FF1_8868DDA80A92__INCLUDED_)
#define AFX_PREDICATELEVEL_H__8CA05E38_22D4_4A75_8FF1_8868DDA80A92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include "Debug.h"

#include "PredicateNode.h"

class PredicateLevel  
{
protected:
	PredicateNodeVector pnvPredicates;
public:
	PredicateLevel();
	virtual ~PredicateLevel();
	
	void addPredicates(PredicateInstanceVector &piv);
	int addPredicate(PredicateInstance *pi);
	PredicateNode &operator[](int iRef);
	int size();
	bool isMutex(int i1, int i2);
	void addMutex(int i1, int i2);
	int countMutexes();

	bool operator==(PredicateLevel &plRight);

	string toString();
};

typedef vector<PredicateLevel> PredicateLevelVector;

#endif // !defined(AFX_PREDICATELEVEL_H__8CA05E38_22D4_4A75_8FF1_8868DDA80A92__INCLUDED_)
