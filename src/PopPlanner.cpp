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
// PopPlanner.cpp: implementation of the PopPlanner class.
//
//////////////////////////////////////////////////////////////////////

#include "PopPlanner.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PopPlanner::PopPlanner(PredicateVector &pvStart, PredicateVector &pvGoal, OperatorVector &ovOpers):Planner(pvStart, pvGoal, ovOpers)
{

}

PopPlanner::~PopPlanner()
{

}

bool PopPlanner::plan()
{
	bool bRes=true;

	this->popPlan=new PartialOrderPlan(this->pvStart, this->pvGoal);;
	
	while(!popPlan->isSolution())
	{
		//(S-need, c) = select-subgoal(plan) ; // choose an unsolved goal
		Predicate *pCause=popPlan->selectSubgoal();
		Operator *oCause=popPlan->getOperatorFromGoal(pCause);

		//choose-operator(plan, operators, S-need, c);
		if(!popPlan->chooseOperator(pCause, oCause, ovOpers))
			return false;
		// select an operator to solve that goal and revise plan
		//resolve-threats(plan);  // fix any threats created

		if(!popPlan->resolveThreats())
			return false;

		//PRINTL(pPlan->toString())
	}
	
	return bRes;
}

PartialOrderPlan *PopPlanner::getPopPlan()
{
	popPlan->toVector();
	return popPlan;
}

Plan *PopPlanner::getPlan()
{
	return popPlan;
}
