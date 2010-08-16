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
// PlanningGraph.h: interface for the PlanningGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANNINGGRAPH_H__375F03F6_B7A3_4BDE_A2FD_A67C1F026725__INCLUDED_)
#define AFX_PLANNINGGRAPH_H__375F03F6_B7A3_4BDE_A2FD_A67C1F026725__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;
using std::remove;

#include "Debug.h"
#include "Consoleout.h"

#include "ActionLevel.h"
#include "PredicateLevel.h"

#include "ActionNode.h"
#include "PredicateNode.h"

#include "OperatorInstance.h"
#include "PredicateInstance.h"

#include "PlanLevel.h"
#include "PlanLevelSet.h"

#include "ParallelPlan.h"
#include "PlanSet.h"

#include "MemoizationTable.h"
#include "MemoizationLevel.h"

#include "PlanningGraphStatistics.h"

typedef vector<int> IntVector;

class PlanningGraph
{
protected:
	//Vector representing the action levels of the graph
	ActionLevelVector alvActions;
	//Vector representing the predicate levels of the graph
	PredicateLevelVector plvPredicates;

	//Flag that denotes whether the algorithm should use or not memoization
	bool bUseMemoization;
	MemoizationTable mtMemo;

	//Flag denoting whether the graph has levelled off
	bool bGraphLevelledoff;
	//Integer denoting the graph level where the levelling off has occurred
	int iGraphLevelledIndex;
	
	//A list of all the plans found in the graph
	PlanSet psPlans;

	//Adds an action level and returns its index in the action vector
	int addActionLevel(OperatorInstanceVector &oivActions);
	//Adds a predicate level and returns its index in the predicate vector
	int addPredicateLevel(PredicateInstanceVector &pivPredicates);

	//Determines the possible actions to be inserted in the new action level given the set of predicates in the previous predicate level
	OperatorInstanceVector determineActions(int iPredicateLevel, OperatorInstanceVector &oivActions);
	//Determines the set of effects resulting from the referred action level
	PredicateInstanceVector determineEffects(int iActionLevel);

	//Adds the mutexes for the given action level
	void checkActionMutexes(int iActionLevel);
	//Adds the mutexes for the given predicate level
	void checkPredicateMutexes(int iPredicateLevel);

	//Adds the precondition edges between the referred precondition level and the referred action level
	void addPreconditionEdges(int iPredicateLevel, int iActionLevel);
	//Adds the precondition edges between the referred action level and the referred precondition level
	void addEffectEdges(int iActionLevel, int iPredicateLevel);

	int getPredicateIndex(int iPredicateLevel, PredicateInstance *pi);
	bool extractSolution(int iPredicateLevel, IntVector &ivGoal, IntVector::iterator iGoal, PlanLevelSet &plsPlan);
	bool isMinimalActionSet(int iPlanLevel, IntVector &ivGoal, PlanLevelSet &plsPlan);
	IntVector determineSubGoals(int iActionLevel, PlanLevel &pl);

	ParallelPlan makeParallelPlan(PlanLevelSet &plsPlan);

public:
	PlanningGraph();
	PlanningGraph(PredicateInstanceVector &pivStart, bool bUseMemoization=true);
	virtual ~PlanningGraph();

	void expand(OperatorInstanceVector &oivOperators);
	bool goalsPossible(PredicateInstanceVector &pivGoals, int iLevel);
	bool inline goalsPossible(PredicateInstanceVector &pivGoals){return goalsPossible(pivGoals, plvPredicates.size()-1);}
	bool graphLevelledOff();
	bool planPossible();

	bool extractSolution(PredicateInstanceVector pivGoal);

	int size();

	inline bool isActionLevel(int iIndex){return ((iIndex%2)!=0);}
	inline bool isPredicateLevel(int iIndex){return ((iIndex%2)==0);}

	inline int actionLevel(int iIndex){return (iIndex/2);}
	inline int predicateLevel(int iIndex){return (iIndex/2);}

	inline PredicateLevelVector &getPredicateLevels(){return this->plvPredicates;}
	inline ActionLevelVector &getActionLevels(){return this->alvActions;}

	PlanningGraphStatistics getStatistics();

	ParallelPlan getPlan();

	PlanningGraph &operator=(PlanningGraph &pgRight);
	string toString();
};

#endif // !defined(AFX_PLANNINGGRAPH_H__375F03F6_B7A3_4BDE_A2FD_A67C1F026725__INCLUDED_)
