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
// PlanLevelSet.cpp: implementation of the PlanLevelSet class.
//
//////////////////////////////////////////////////////////////////////

#include "PlanLevelSet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PlanLevelSet::PlanLevelSet()
{

}

PlanLevelSet::PlanLevelSet(int iSize)
{
	plvLevels.resize(iSize);
}

PlanLevelSet::~PlanLevelSet()
{

}

//////////////////////////////////////////////////////////////////////
//Returns the plan level at the specified index
//////////////////////////////////////////////////////////////////////
PlanLevel &PlanLevelSet::operator[](int iIndex)
{
	return plvLevels[iIndex];
}

//////////////////////////////////////////////////////////////////////
//Clears the planlevel specified by the index
//////////////////////////////////////////////////////////////////////
void PlanLevelSet::clearLevel(int iLevel)
{
	plvLevels[iLevel].clearLevel();
}

//////////////////////////////////////////////////////////////////////
//Returns the number of levels this set has
//////////////////////////////////////////////////////////////////////
int PlanLevelSet::size()
{
	return plvLevels.size();
}

//////////////////////////////////////////////////////////////////////
//Returns a string representation of the plan
//////////////////////////////////////////////////////////////////////
string PlanLevelSet::toString()
{
	ostringstream sRes;

	for(int i=0; i<plvLevels.size(); i++)
	{
		sRes << "ActionLevel " <<  i << "\n";
		sRes << plvLevels[i].toString() << "\n";
	}

	return sRes.str();
}
