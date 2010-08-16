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
 * ActionLevel.cpp: implementation of the ActionLevel class.
 *
 *  Created on: Aug 15, 2010
 *      Author: meneguzzi
 */

#include "ActionLevel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ActionLevel::ActionLevel()
{

}

ActionLevel::~ActionLevel()
{

}

void ActionLevel::addActions(OperatorInstanceVector &oiv)
{
	for(OperatorInstanceVector::iterator i=oiv.begin(); i!=oiv.end(); i++)
	{
		this->addAction(*i);
	}
}

int ActionLevel::addAction(OperatorInstance *oi)
{
	ActionNode on(oi);

	//if(pnvPredicates.find(pn)!=pnvPredicates.end())
	anvActions.push_back(on);

	return 0;
}

ActionNode &ActionLevel::operator[](int iRef)
{
	return this->anvActions[iRef];
}

int ActionLevel::size()
{
	return this->anvActions.size();
}

bool ActionLevel::isMutex(int i1, int i2)
{
	return anvActions[i1].isMutex(i2);
}

void ActionLevel::addMutex(int i1, int i2)
{
	anvActions[i1].addMutex(i2);
	anvActions[i2].addMutex(i1);
}

int ActionLevel::countMutexes()
{
	int iRes=0;

	for(ActionNodeVector::iterator i=anvActions.begin(); i!=anvActions.end(); i++)
	{
		iRes+=i->countMutexes();
	}

	return iRes;
}

int ActionLevel::countPreconditionEdges()
{
	int iRes=0;
	for(int i=0; i<anvActions.size(); i++)
	{
		iRes+=anvActions[i].getPreconditionLinks().size();
	}
	return iRes;
}

int ActionLevel::countEffectEdges()
{
	int iRes=0;
	for(int i=0; i<anvActions.size(); i++)
	{
		iRes+=anvActions[i].getEffectLinks().size();
	}
	return iRes;
}

bool ActionLevel::operator==(ActionLevel &alRight)
{
	bool bRes=true;

	if(this!=&alRight)
	{
		bRes &= ((this->size() == alRight.size()) && (this->countMutexes() == alRight.countMutexes()));

		for(int i=0; bRes && (i<this->size()); i++)
		{
			bRes &= (anvActions[i]==alRight[i]);
		}
	}else
		bRes=true;

	return bRes;
}

string ActionLevel::toString()
{
	ostringstream sRes;
	sRes << "ActionLevel\n";

	for(int i=0; i!=anvActions.size(); i++)
	{
		sRes << " * " << i << "-" << anvActions[i].toString();
	}

	return sRes.str();
}
