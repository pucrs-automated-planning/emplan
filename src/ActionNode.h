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
 * ActionNode.h: interface for the ActionNode class.
 *
 *  Created on: Aug 15, 2002
 *      Author: meneguzzi
 */

#if !defined(AFX_ACTIONNODE_H__80786CC8_8706_471D_9F75_8DEA2B8F1C81__INCLUDED_)
#define AFX_ACTIONNODE_H__80786CC8_8706_471D_9F75_8DEA2B8F1C81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <sstream>
using std::ostringstream;

#include <algorithm>
using std::find;

#include "Debug.h"

#include "OperatorInstance.h"

typedef vector<int> IntVector;

class ActionNode  
{
protected:
	OperatorInstance *oiAction;
	IntVector ivMutexes;
	IntVector ivCondMutexes;

	IntVector ivPreconditionLinks;
	IntVector ivEffectLinks;
public:
	ActionNode();
	ActionNode(OperatorInstance *oiAction);
	virtual ~ActionNode();

	void addMutex(int iMutex);
	void addCondMutex(int iMutex);
	bool isMutex(int iMutex);
	int countMutexes();
	IntVector &getMutexes();
	OperatorInstance *getAction();

	void linkPrecondition(int iPreconditionIndex);
	IntVector &getPreconditionLinks();
	void linkEffect(int iEffectIndex);
	IntVector &getEffectLinks();
	
	ActionNode &operator=(const ActionNode &anRight);
	bool operator==(ActionNode &anRight);

	string toString();
};

typedef vector<ActionNode> ActionNodeVector;

#endif // !defined(AFX_ACTIONNODE_H__80786CC8_8706_471D_9F75_8DEA2B8F1C81__INCLUDED_)
