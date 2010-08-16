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
// PlanLevel.cpp: implementation of the PlanLevel class.
//
//////////////////////////////////////////////////////////////////////

#include "PlanLevel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PlanLevel::PlanLevel()
{

}

PlanLevel::~PlanLevel()
{

}

//////////////////////////////////////////////////////////////////////
//Adds an action to the plan level, return true if the action was new 
//to the level
//////////////////////////////////////////////////////////////////////
bool PlanLevel::addAction(int iAction)
{
	bool bRes;
	if(!hasAction(iAction))
	{
		bRes=true;
		ivActions.push_back(iAction);
	}else
		bRes=false;

	return bRes;
}

//////////////////////////////////////////////////////////////////////
//Removes an action from the plan
//////////////////////////////////////////////////////////////////////
void PlanLevel::removeAction(int iAction)
{
	remove(ivActions.begin(), ivActions.end(), iAction);
	ivActions.resize(ivActions.size()-1);
}

//////////////////////////////////////////////////////////////////////
//Check if the referred action is not already in the plan
//////////////////////////////////////////////////////////////////////
bool PlanLevel::hasAction(int iAction)
{
	return (find(ivActions.begin(), ivActions.end(), iAction)!=ivActions.end());
}

//////////////////////////////////////////////////////////////////////
//Returns the action stored in the referred action level
//////////////////////////////////////////////////////////////////////
int PlanLevel::operator[](int iIndex)
{
	return ivActions[iIndex];
}

//////////////////////////////////////////////////////////////////////
//Returns the size (i.e. the number of actions chosen for the current level)
//////////////////////////////////////////////////////////////////////
int PlanLevel::size()
{
	return ivActions.size();
}

//////////////////////////////////////////////////////////////////////
//Clears all the actions in the current level
//////////////////////////////////////////////////////////////////////
void PlanLevel::clearLevel()
{
	ivActions.clear();
}

//////////////////////////////////////////////////////////////////////
//Returns a string representation of the current level
//////////////////////////////////////////////////////////////////////
string PlanLevel::toString()
{
	ostringstream sRes;

	for(int i=0; i<ivActions.size(); i++)
	{
		sRes << " * " << i << "-" << ivActions[i];
	}

	return sRes.str();
}
