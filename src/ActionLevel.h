//---------------------------------------------------------------------------
//Copyright (C) 2010  Felipe Meneguzzi
//JavaGP is distributed under LGPL. See file LGPL.txt in this directory.
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
 * ActionLevel.h: interface for the ActionLevel class.
 */

#if !defined(AFX_ACTIONLEVEL_H__D3D6BA2B_9D45_4E79_958B_95943B7B34D1__INCLUDED_)
#define AFX_ACTIONLEVEL_H__D3D6BA2B_9D45_4E79_958B_95943B7B34D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;
using std::ostringstream;

#include "Debug.h"

#include "ActionNode.h"

class ActionLevel  
{
protected:
	ActionNodeVector anvActions;

public:
	ActionLevel();
	virtual ~ActionLevel();

	void addActions(OperatorInstanceVector &oiv);
	int addAction(OperatorInstance *oi);
	ActionNode &operator[](int iRef);
	int size();
	bool isMutex(int i1, int i2);
	void addMutex(int i1, int i2);
	int countMutexes();
	int countPreconditionEdges();
	int countEffectEdges();

	bool operator==(ActionLevel &alRight);

	string toString();
};

typedef vector<ActionLevel> ActionLevelVector;

#endif // !defined(AFX_ACTIONLEVEL_H__D3D6BA2B_9D45_4E79_958B_95943B7B34D1__INCLUDED_)
