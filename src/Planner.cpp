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
// Planner.cpp: implementation of the Planner class.
//
//////////////////////////////////////////////////////////////////////

#include "Planner.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Planner::Planner(PredicateVector &pvStart, PredicateVector &pvGoal, OperatorVector &ovOpers)
{
	this->pvStart=pvStart;
	this->pvGoal=pvGoal;
	this->ovOpers=ovOpers;
}

Planner::~Planner()
{

}

Planner &Planner::operator=(Planner &pRight)
{
	if(this != &pRight)
	{
		this->pvStart=pRight.pvStart;
		this->pvGoal=pRight.pvGoal;
		this->ovOpers=pRight.ovOpers;
	}

	return *this;
}
