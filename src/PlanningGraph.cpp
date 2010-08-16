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
// PlanningGraph.cpp: implementation of the PlanningGraph class.
//
//////////////////////////////////////////////////////////////////////

#include "PlanningGraph.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PlanningGraph::PlanningGraph()
{
	this->bUseMemoization=true;
	this->bGraphLevelledoff=false;
	this->iGraphLevelledIndex=-1;
}

PlanningGraph::PlanningGraph(PredicateInstanceVector &pivStart, bool bUseMemoization)
{
	this->addPredicateLevel(pivStart);
	this->bUseMemoization=bUseMemoization;
	this->bGraphLevelledoff=false;
	this->iGraphLevelledIndex=-1;
	//this->checkPredicateMutexes(0); //I don't really know if it is necessary to check predicate mutexes in the first level
}

PlanningGraph::~PlanningGraph()
{

}

//////////////////////////////////////////////////////////////////////
//Expands the planning graph one extra action level and its
//consquent effects
//////////////////////////////////////////////////////////////////////
void PlanningGraph::expand(OperatorInstanceVector &oivOperators)
{
	//Add the actions
	//The reference preconditions are the last level in the graph
	int iPreconditionLevel=plvPredicates.size()-1;
	
	//Determine possible actions
	PRINTL("Determining actions for predicate level "<< iPreconditionLevel)
	OperatorInstanceVector oiv=this->determineActions(iPreconditionLevel, oivOperators);
	//Add an action level based on the selected actions
	PRINT("Adding action level -> ")
	int iActionLevel=this->addActionLevel(oiv);
	PRINTL("Action level "<< iActionLevel << " added")
	
	//Connect the new graph level with its preconditions
	PRINTL("Adding precondition edges between predicate level "<< iPreconditionLevel << " and action level "<<iActionLevel)
	this->addPreconditionEdges(iPreconditionLevel,iActionLevel);
	//Verify action mutexes
	PRINTL("Checking action mutexes")
	this->checkActionMutexes(iActionLevel);

	//Now add the predicates
	//Determine possible outcomes (i.e. predicate effects)
	PRINTL("Determining effects for action level "<<iActionLevel)
	PredicateInstanceVector piv=this->determineEffects(iActionLevel);
	//Add a predicate level
	PRINT("Adding predicate level -> ")
	int iPredicateLevel=this->addPredicateLevel(piv);
	PRINTL("Predicate level "<< iPredicateLevel << " added")
	
	//Connect the new graph level with its generating actions
	PRINTL("Adding effect edges between action level "<< iActionLevel << " and predicate level "<<iPredicateLevel)
	this->addEffectEdges(iActionLevel, iPredicateLevel);
	//Verify predicate mutexes
	PRINTL("Checking predicate mutexes")
	this->checkPredicateMutexes(iPredicateLevel);
}

//////////////////////////////////////////////////////////////////////
//Determine if the predicates given as a parameter are a possible
//set of goals in the specified predicate level
//////////////////////////////////////////////////////////////////////
bool PlanningGraph::goalsPossible(PredicateInstanceVector &pivGoals, int iLevel)
{
	bool bRes=true;
	//Essentially search the level for every goal given as parameter, and then match
	//them with the others to see if they are mutex
	for(PredicateInstanceVector::iterator i=pivGoals.begin(); bRes && i!=pivGoals.end(); i++)
	{
		PredicateInstance *pi1=*i;
		//Tries to find the predicate as an index in the level
		int iPred=this->getPredicateIndex(iLevel, pi1);
		if(iPred==-1)//If the predicate was not false then teh goals are obviously not possible
			bRes = false;
		//If not try to find the other operators and check for mutual exclusion
		for(PredicateInstanceVector::iterator j=i+1; bRes && j!=pivGoals.end(); j++)
		{
			PredicateInstance *pi2=*j;
			int iPred2=this->getPredicateIndex(iLevel, pi2);
			if(iPred2==-1)
				bRes=false;
			else
				bRes=!plvPredicates[iLevel][iPred].isMutex(iPred2);
		}
	}

	return bRes;
}

//////////////////////////////////////////////////////////////////////
//Determines if the planning graph has reached an expansion fixed-point
//That is, the resulting of successive applications of the expand
//operator will always result in the same levels
// Once the graph has levelled off there is no need to make the full
//check again, so it is stored in a variable 
//////////////////////////////////////////////////////////////////////
bool PlanningGraph::graphLevelledOff()
{
	//If the graph has already levelled off, then we don't have to check that
	//again
	if(this->bGraphLevelledoff)
		return true;

	int iLastActionLevel=alvActions.size()-1;

	int iLastPredicateLevel=plvPredicates.size()-1;
	
	//Good thing that optimized C does not check all the conditions in a conjunction if one of them
	//is false
	this->bGraphLevelledoff =((alvActions.size()>1)
		 && (alvActions[iLastActionLevel].size() == alvActions[iLastActionLevel-1].size())
		 && (alvActions[iLastActionLevel].countMutexes() == alvActions[iLastActionLevel-1].countMutexes())
		 && (plvPredicates[iLastPredicateLevel].size() == plvPredicates[iLastPredicateLevel-1].size())
		 && (plvPredicates[iLastPredicateLevel].countMutexes() == plvPredicates[iLastPredicateLevel-1].countMutexes()));

	//If the graph has levelled off, store the index where it happened to check for 
	//the memoization stop condition
	if(bGraphLevelledoff)
	{
		WRITELN("L");
		this->iGraphLevelledIndex=iLastPredicateLevel;
	}

	return bGraphLevelledoff;

	//The piece of code below is better expressed above
	/*
	bool bRes=(alvActions.size()>1);
	if(!bRes)
		return false;

	int iLastActionLevel=alvActions.size()-1;
	bRes &= alvActions[iLastActionLevel].size() == alvActions[iLastActionLevel-1].size();
	if(!bRes)
		return false;

	bRes &= alvActions[iLastActionLevel].countMutexes() == alvActions[iLastActionLevel-1].countMutexes();
	if(!bRes)
		return false;

	int iLastPredicateLevel=plvPredicates.size()-1;
	bRes &= plvPredicates[iLastPredicateLevel].size() == plvPredicates[iLastPredicateLevel-1].size();
	if(!bRes)
		return false;

	bRes &= plvPredicates[iLastPredicateLevel].countMutexes() == plvPredicates[iLastPredicateLevel-1].countMutexes();

	return bRes;*/
}

//////////////////////////////////////////////////////////////////////
//Determines if the planning graph has reached an expansion fixed-point
//That is, the resulting of successive applications of the expand
//operator will always result in the same levels
// This method is more complex than the one right above the code
// I'm still not sure if that condition above is sufficient
// but it has worked for the problems so far, so...
//////////////////////////////////////////////////////////////////////
/*bool PlanningGraph::graphLevelledOff()
{
	bool bRes=(alvActions.size()>1);

	if(!bRes)
		return false;

	int iLastActionLevel=alvActions.size()-1;
	int iLastPredicateLevel=plvPredicates.size()-1;

	bRes &= ((plvPredicates[iLastPredicateLevel] == plvPredicates[iLastPredicateLevel-1]) &&
			 (alvActions[iLastActionLevel] == alvActions[iLastActionLevel-1]));

	return bRes;
}*/

//////////////////////////////////////////////////////////////////////
//Determines if the plan is still possible, given the current graph status
//By the definition in Blum and Furst's paper, if the number of memoized
//goals between two levels is the same, then no plan is possible
//This condition is not checked properly as of now, so I ought to change
//this as soon as possible
//////////////////////////////////////////////////////////////////////
bool PlanningGraph::planPossible()
{
	if(!bUseMemoization)
		return true;
	//The memoization table check is only valid after the graph has levelled off
	if(!graphLevelledOff())
		return true;
	else
	{
		return mtMemo.planPossible(this->iGraphLevelledIndex);
	}
	
	//The code below has been removed because the condition set in Blum's paper regards the
	//level where the algorithm levelled off, and not the last level.
	//If the number of no-good goal sets stored in two consecutive levels of the memoization table
	//are the same, then the problem is unsolvable
	/*int iLastPredicateLevel=plvPredicates.size()-1;
	bool bRes=mtMemo.planPossible(iLastPredicateLevel);
	return bRes;*/
}

//////////////////////////////////////////////////////////////////////
//Tries to extract a solution in the current graph, given the goals
//////////////////////////////////////////////////////////////////////
bool PlanningGraph::extractSolution(PredicateInstanceVector pivGoal)
{
	int iPredicateLevel=plvPredicates.size()-1;
	//First, convert the goals into indexes in the last graph level
	IntVector ivGoal;
	for(int i=0; i<plvPredicates[iPredicateLevel].size(); i++)
	{
		if(find(pivGoal.begin(), pivGoal.end(), plvPredicates[iPredicateLevel][i].getPredicate())!=pivGoal.end())
			ivGoal.push_back(i);
	}

	//then start solution extraction

	PlanLevelSet plsPlan(alvActions.size());
	bool bRes=extractSolution(iPredicateLevel, ivGoal, ivGoal.begin(), plsPlan);

	//If solution extraction was sucessfull, serialize the plan for later return.
	if(bRes)
	{
		ParallelPlan pp=this->makeParallelPlan(plsPlan);
		this->psPlans.addPlan(pp);
	}
	

	PRINTL("Plan found:")
	PRINTL(plsPlan.toString())
	

	return bRes;
}

//////////////////////////////////////////////////////////////////////
//Adds an action level considering the operator instances given as 
// parameter
//////////////////////////////////////////////////////////////////////
int PlanningGraph::addActionLevel(OperatorInstanceVector &oivOperators)
{
	alvActions.resize(alvActions.size()+1);
	int iIndex=alvActions.size()-1;
	alvActions[iIndex].addActions(oivOperators);

	return iIndex;
}

//////////////////////////////////////////////////////////////////////
//Adds a predicate level considering the predicate instances given as 
// parameter
//////////////////////////////////////////////////////////////////////
int PlanningGraph::addPredicateLevel(PredicateInstanceVector &pivPredicates)
{
	plvPredicates.resize(plvPredicates.size()+1);
	int iIndex=plvPredicates.size()-1;
	plvPredicates[iIndex].addPredicates(pivPredicates);

	return iIndex;
}

//////////////////////////////////////////////////////////////////////
//Determine the actions to be taken regarding the predicate level
//given as parameter
//////////////////////////////////////////////////////////////////////
OperatorInstanceVector PlanningGraph::determineActions(int iPredicateLevel, OperatorInstanceVector &oivActions)
{
	OperatorInstanceVector oivRes;
	
	//Check every possible operator
	for(OperatorInstanceVector::iterator i=oivActions.begin(); i!=oivActions.end(); i++)
	{
		OperatorInstance *oi=*i;

		bool bRequirementsSatisfied=true;

		PredicateInstanceVector pivPreconds=oi->getPreconditions();
		//For each precondition in the operator
		for(PredicateInstanceVector::iterator i=pivPreconds.begin(); bRequirementsSatisfied && i!=pivPreconds.end(); i++)
		{
			PredicateInstance *pi1=*i;
			bRequirementsSatisfied=false;
			//check if it is contained in the current predicate level
			for(int j=0; !bRequirementsSatisfied && j<plvPredicates[iPredicateLevel].size(); j++)
			{
				PredicateInstance *pi2=plvPredicates[iPredicateLevel][j].getPredicate();
				if(pi1==pi2)
					bRequirementsSatisfied=true;
			}
		}

		if(bRequirementsSatisfied)
		{
			oivRes.push_back(oi);
		}
	}
		
	return oivRes;
}

//////////////////////////////////////////////////////////////////////
//This method checks every action in an action level and puts all the
// predicates listed as effects of those actions in a list
//////////////////////////////////////////////////////////////////////
PredicateInstanceVector PlanningGraph::determineEffects(int iActionLevel)
{
	PredicateInstanceVector pivRes;
	//for every action node in the referred action level
	for(int i=0; i<alvActions[iActionLevel].size(); i++)
	{
		OperatorInstance *oi=alvActions[iActionLevel][i].getAction();
		//PRINTL("Checking effects for: "<<oi->toString())
		PredicateInstanceVector pivEffects=oi->getEffects();
		//Check every consequence of it
		for(PredicateInstanceVector::iterator j=pivEffects.begin(); j!=pivEffects.end(); j++)
		{
			PredicateInstance *pi=*j;
			//If the referred predicate is not already in the list
			if(find(pivRes.begin(), pivRes.end(), pi) == pivRes.end())
			{
				//Insert it in the effects list
				pivRes.push_back(pi);
			}
		}
	}
	return pivRes;
}

//////////////////////////////////////////////////////////////////////
//This method verifies an action level for the mutexes between its actions
//This includes both static mutexes and dynamic mutexes
//////////////////////////////////////////////////////////////////////
void PlanningGraph::checkActionMutexes(int iActionLevel)
{
	//for every action in the action level
	for(int i=0; i<alvActions[iActionLevel].size(); i++)
	{
		OperatorInstance *oi1=alvActions[iActionLevel][i].getAction();
		//Check every other action for...
		for(int j=i+1; j<alvActions[iActionLevel].size(); j++)
		{
			OperatorInstance *oi2=alvActions[iActionLevel][j].getAction();

			//static mutexes
			if(oi1->isMutex(oi2))
			{
				alvActions[iActionLevel][i].addMutex(j);
				alvActions[iActionLevel][j].addMutex(i);
				continue;//If a mutex between two operatos has been found, there's no need
				//to look further
			}
			//And dynamic mutexes
			//Get each action's links to its preconditions
			IntVector ivPreconditionsI=alvActions[iActionLevel][i].getPreconditionLinks();
			IntVector ivPreconditionsJ=alvActions[iActionLevel][j].getPreconditionLinks();

			//Get the predicate index to verify mutex relations
			int iPredicateLevel=iActionLevel;
			//for every precondition edge which points to the first action
			for(IntVector::iterator k=ivPreconditionsI.begin(); k!=ivPreconditionsI.end(); k++)
			{
				int iPreK=*k;
				for(IntVector::iterator l=ivPreconditionsJ.begin(); l!=ivPreconditionsJ.end(); l++)
				{
					int iPreL=*l;

					if(plvPredicates[iPredicateLevel][iPreK].isMutex(iPreL))
					{
						alvActions[iActionLevel][i].addMutex(j);
						alvActions[iActionLevel][j].addMutex(i);
						continue;//If a mutex between two operatos has been found, there's no need
						//to look further
					}
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
//This method verifies a predicate level for the mutexes between its components
//This includes both static mutexes and dynamic mutexes
//////////////////////////////////////////////////////////////////////
void PlanningGraph::checkPredicateMutexes(int iPredicateLevel)
{
	//for every predicate in the predicate level
	for(int i=0; i<plvPredicates[iPredicateLevel].size(); i++)
	{
		PredicateInstance *pi1=plvPredicates[iPredicateLevel][i].getPredicate();
		//Check every other predicate for...
		for(int j=i+1; j<plvPredicates[iPredicateLevel].size(); j++)
		{
			PredicateInstance *pi2=plvPredicates[iPredicateLevel][j].getPredicate();

			//static mutexes
			if(pi1->isMutex(pi2))
			{
				plvPredicates[iPredicateLevel][i].addMutex(j);
				plvPredicates[iPredicateLevel][j].addMutex(i);
				//PRINTL(this->printPredicateMutexes(iPredicateLevel))
				continue;//If a mutex between two predicates has been found, there's no need
				//to look further
			}

			//And dynamic mutexes
			//Get each predicate's links to its supporting actions
			IntVector ivPreconditionsI=plvPredicates[iPredicateLevel][i].getPreconditionLinks();
			IntVector ivPreconditionsJ=plvPredicates[iPredicateLevel][j].getPreconditionLinks();

			//The action level referred to is in the preconditions side
			int iActionLevel=iPredicateLevel-1;
			bool bSimultaneousAction=false;
			//for every precondition edge that links a predicate to an action
			for(IntVector::iterator k=ivPreconditionsI.begin(); !bSimultaneousAction && k!=ivPreconditionsI.end(); k++)
			{
				int iPreK=*k;
				for(IntVector::iterator l=ivPreconditionsJ.begin(); !bSimultaneousAction && l!=ivPreconditionsJ.end(); l++)
				{
					int iPreL=*l;
					//Check if the actions referred to by the selected edges
					//are mutex
					if(!alvActions[iActionLevel][iPreK].isMutex(iPreL))
					{
						//If there is at least one pair of actions that can be executed
						//Simultaneously, then the predicates are not mutex
						bSimultaneousAction=true;
					}
				}
			}
			
			if(!bSimultaneousAction)
			{
				plvPredicates[iPredicateLevel][i].addMutex(j);
				plvPredicates[iPredicateLevel][j].addMutex(i);
				continue;//If a mutex between two predicates has been found, there's no need
				//to look further
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
//This method adds the edges between a predicate level and the action
//preconditions of the next action level
//////////////////////////////////////////////////////////////////////
void PlanningGraph::addPreconditionEdges(int iPredicateLevel, int iActionLevel)
{
	for(int i=0; i<plvPredicates[iPredicateLevel].size(); i++)
	{
		for(int j=0; j<alvActions[iActionLevel].size(); j++)
		{
			PredicateInstance *pi=plvPredicates[iPredicateLevel][i].getPredicate();
			OperatorInstance *oi=alvActions[iActionLevel][j].getAction();
			
			if(oi->requires(pi))
			{
				plvPredicates[iPredicateLevel][i].linkEffect(j);
				alvActions[iActionLevel][j].linkPrecondition(i);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
//This method adds the edges between an action level effects to the next 
//predicate level
//////////////////////////////////////////////////////////////////////
void PlanningGraph::addEffectEdges(int iActionLevel, int iPredicateLevel)
{
	for(int i=0; i<plvPredicates[iPredicateLevel].size(); i++)
	{
		for(int j=0; j<alvActions[iActionLevel].size(); j++)
		{
			PredicateInstance *pi=plvPredicates[iPredicateLevel][i].getPredicate();
			OperatorInstance *oi=alvActions[iActionLevel][j].getAction();

			if(oi->fulfills(pi))
			{
				plvPredicates[iPredicateLevel][i].linkPrecondition(j);
				alvActions[iActionLevel][j].linkEffect(i);
			}
		}
	}

}

//////////////////////////////////////////////////////////////////////
//Searches a predicate level for a given predicate instance
//returns -1 if the predicate requested was not in the level
//////////////////////////////////////////////////////////////////////
int PlanningGraph::getPredicateIndex(int iPredicateLevel, PredicateInstance *pi)
{
	for(int i=0; i<plvPredicates[iPredicateLevel].size(); i++)
	{
		if(plvPredicates[iPredicateLevel][i].getPredicate() == pi)
			return i;
	}

	return -1;
}

//////////////////////////////////////////////////////////////////////
//Tries to recursively extract a solution for the predicate set 
// supplied as parameter
//////////////////////////////////////////////////////////////////////
bool PlanningGraph::extractSolution(int iPredicateLevel, IntVector &ivGoal, IntVector::iterator iGoal, PlanLevelSet &plsPlan)
{
	//If we reached the zeroth level, then we have found a plan
	if(iPredicateLevel==0)
		return true;

	//Let's try memoization here
	//If the goal being analysed is the first, analyse it against the no goods table
	//PRINTL("Checking against memoized goals")
	if(bUseMemoization && iGoal==ivGoal.begin() && mtMemo.isNoGood(iPredicateLevel, ivGoal))
	{
		//PRINTL("Goals are no good")
		return false;
	}else
	{
		//PRINTL("Goals are good")
	}

	int iActionLevel=iPredicateLevel-1;
	//If there are no more predicates to find a solution for, determine the next goals and go on
	//to the previous level
	if(iGoal==ivGoal.end())
	{
		//If the goals chosen for this level are not minimal, force failure
		if(!isMinimalActionSet(iActionLevel, ivGoal, plsPlan))
		{
			//PRINTL("Action set: " << plsPlan[iActionLevel].toString() << " at level "<< iActionLevel<< " is not minimal.")
			return false;
		}
		IntVector ivNewGoals=determineSubGoals(iActionLevel, plsPlan[iActionLevel]);
		int iNewPredicateLevel=iPredicateLevel-1;
		bool bRes=extractSolution(iNewPredicateLevel, ivNewGoals, ivNewGoals.begin(), plsPlan);

		//If the solution extraction for the previous level has failed, then add the goal set to
		//the no goods table
		if(bUseMemoization && !bRes)
		{
			//PRINTL("Memoizing goals as no good")
			mtMemo.addNoGood(iNewPredicateLevel, ivNewGoals);
			//PRINTL("Goals memoized")
		}

		return bRes;
	}

	int iGoalIndex=*iGoal;

	//Bug fixed, did not check if the goal has not already been cleared by an existing operator!!

	IntVector ivPreconditions=plvPredicates[iPredicateLevel][iGoalIndex].getPreconditionLinks();

	//Iterate through the goal's supporting actions
	for(IntVector::iterator i=ivPreconditions.begin(); i!=ivPreconditions.end(); i++)
	{
		//Get the support point
		int iActionIndex=*i;
		//Check if the action has not already been selected
		bool bAddOper=!plsPlan[iActionLevel].hasAction(iActionIndex);
		if(bAddOper)
		{
			//If the selected action is not already in the plan
			//Test it against the other chosen operators
			bool bMutexFound=false;
			for(int j=0; !bMutexFound && j!=plsPlan[iActionLevel].size(); j++)
			{
				int iAc=plsPlan[iActionLevel][j];
				//if the new operator is mutex with any other already added to the list
				if(alvActions[iActionLevel][iAc].isMutex(iActionIndex))
					bMutexFound=true;//switch the flag
			}// and go no
			if(bMutexFound)
				continue;
			//If no mutex was found the operator should be added
			plsPlan[iActionLevel].addAction(iActionIndex);//Only if it is not already in the list
		}
		//If the operator has passed the tests, then search deeper into the operators
		bool bPlanFound=extractSolution(iPredicateLevel, ivGoal, iGoal+1, plsPlan);
			
		if(!bPlanFound && bAddOper)
			plsPlan[iActionLevel].removeAction(iActionIndex);
		
		if(bPlanFound)
			return true;
	}

	//If all the possible supporting actions have been tried and no plan was found, no plan exists for now
	return false;
}

//////////////////////////////////////////////////////////////////////
//Determines if the action set contained in the referred plan level 
//is minimal, given the set of goals supplied
//////////////////////////////////////////////////////////////////////
bool PlanningGraph::isMinimalActionSet(int iPlanLevel, IntVector &ivGoal, PlanLevelSet &plsPlan)
{
	bool bRes=true;

	//Select one action and check if the goals can be achieved without it
	//the "i" variable represents an action that is being "taken-out" to
	//check if the goals are reachable without it
	for(int i=0; bRes && i<plsPlan[iPlanLevel].size(); i++)
	{
		int iActionOut = plsPlan[iPlanLevel][i];
		//Bug fixed, if the partial goals achieved size was set in the constructor,
		//it would give false in cases where the goals were different
		//IntVector ivGoalsAchieved(ivGoal.size());
		IntVector ivGoalsAchieved;
		for(int j=0; bRes && j<plsPlan[iPlanLevel].size(); j++)
		{
			int iAction=plsPlan[iPlanLevel][j];
			if(iAction == iActionOut)
				continue;

			//Get the action's effects
			IntVector ivEffects=alvActions[iPlanLevel][iAction].getEffectLinks();
			//And add the new ones in the achieved vector
			for(IntVector::iterator k=ivEffects.begin(); k!=ivEffects.end(); k++)
			{
				int iEffect=*k;
				//If the given effect is in the goals being checked for minimality and not
				//in the goals currently in the temporary list, then add it to the temp list
				if(find(ivGoal.begin(), ivGoal.end(), iEffect)!=ivGoal.end() &&
					find(ivGoalsAchieved.begin(), ivGoalsAchieved.end(), iEffect)==ivGoalsAchieved.end())
					ivGoalsAchieved.push_back(iEffect);
			}
		}

		//If the goals achievable with the removal of the action "i", are different
		//than the goals achievable otherwise, then the goal vectors will have different sizes
		int iGoalsAchievedSize=ivGoalsAchieved.size();
		int iGoalsSize=ivGoal.size();
		bRes = ivGoalsAchieved.size() != ivGoal.size();
	}

	return bRes;
}

//////////////////////////////////////////////////////////////////////
// Gets the preconditions for the actions contained in the plan level
//given as parameter
//////////////////////////////////////////////////////////////////////
IntVector PlanningGraph::determineSubGoals(int iActionLevel, PlanLevel &pl)
{
	IntVector ivGoals;

	for(int i=0; i<pl.size(); i++)
	{
		int iAction=pl[i];
		//Get the preconditions for the selected action
		IntVector ivActionPreconds=alvActions[iActionLevel][iAction].getPreconditionLinks();
		
		//And add them to the answer set
		for(IntVector::iterator j=ivActionPreconds.begin(); j!=ivActionPreconds.end(); j++)
		{
			int iGoal=*j;
			//if the precondition is not already in the goals
			if(find(ivGoals.begin(), ivGoals.end(), iGoal)==ivGoals.end())
			{
				//PRINT(iGoal << " ")
				ivGoals.push_back(iGoal);
			}
		}		
	}
	//PRINT("\n")

	return ivGoals;
}

//////////////////////////////////////////////////////////////////////
//Converts a bunch of internal indexes into an externally usefull
//Set of OperatorInstances, representing a parallel plan
//////////////////////////////////////////////////////////////////////
ParallelPlan PlanningGraph::makeParallelPlan(PlanLevelSet &plsPlan)
{
	ParallelPlan ppPlan(plsPlan.size());
	for(int i=0; i<plsPlan.size(); i++)
	{
		for(int j=0; j<plsPlan[i].size(); j++)
		{
			int iAction=plsPlan[i][j];
			OperatorInstance *oi=alvActions[i][iAction].getAction();
			if(!oi->isNoop())
				ppPlan.addAction(i,oi);
		}
	}
	return ppPlan;
}

//////////////////////////////////////////////////////////////////////
//Returns the size of the planning graph considering predicate
//and action levels.
//////////////////////////////////////////////////////////////////////
int PlanningGraph::size()
{
	return alvActions.size()+plvPredicates.size();
}

//////////////////////////////////////////////////////////////////////
//Returns the plan obtained in the last solution extraction phase
//////////////////////////////////////////////////////////////////////
ParallelPlan PlanningGraph::getPlan()
{
	if(psPlans.size()>0)
		return psPlans[0];
	else
	{
		ParallelPlan ppDummy;
		return ppDummy;
	}
}

//////////////////////////////////////////////////////////////////////
//Computes the statistics for the planning graph
//////////////////////////////////////////////////////////////////////
PlanningGraphStatistics PlanningGraph::getStatistics()
{
	PlanningGraphStatistics pgsRes;

	//First, get Action statistics
	for(int i=0; i<alvActions.size(); i++)
	{
		pgsRes.setActionNodes(i, alvActions[i].size());
		pgsRes.setPreconditionEdges(i, alvActions[i].countPreconditionEdges());
		pgsRes.setEffectEdges(i, alvActions[i].countEffectEdges());
		pgsRes.setActionMutexes(i, alvActions[i].countMutexes()/2);
	}

	//Then, get the predicate statistics
	for(int i=0; i<plvPredicates.size(); i++)
	{
		pgsRes.setPredicateNodes(i, plvPredicates[i].size());
		pgsRes.setPredicateMutexes(i, plvPredicates[i].countMutexes()/2);
	}

	return pgsRes;
}

//////////////////////////////////////////////////////////////////////
//Computes the statistics for the planning graph
//////////////////////////////////////////////////////////////////////
PlanningGraph &PlanningGraph::operator=(PlanningGraph &pgRight)
{
	if(this!=&pgRight)
	{
		this->alvActions=pgRight.alvActions;
		this->plvPredicates=pgRight.plvPredicates;
		this->mtMemo=pgRight.mtMemo;
		this->psPlans=pgRight.psPlans;
		this->bUseMemoization=pgRight.bUseMemoization;
		this->bGraphLevelledoff=pgRight.bUseMemoization;
		this->iGraphLevelledIndex=pgRight.iGraphLevelledIndex;
	}

	return *this;
}

//////////////////////////////////////////////////////////////////////
//Returns a string representation of the planning graph
//This representation states the propositions and the actions
//along with its links both mutex and edges
//////////////////////////////////////////////////////////////////////
string PlanningGraph::toString()
{
	ostringstream sRes;

	int iSize=this->size();

	sRes << "************************************************************\nPlanning Graph - size: " << iSize << "\n";

	for(int i=0; i<iSize; i++)
	{
		sRes << "Level: "<< i << "\n";
		if(i!=0)
			sRes << "############################################################\n";
		if((i%2)!=0)
		{
			int iActionLevel=actionLevel(i);
			sRes << alvActions[iActionLevel].toString() << "\n";
		}
		else
		{
			int iPredicateLevel=predicateLevel(i);
			sRes << plvPredicates[iPredicateLevel].toString() << "\n";
		}
	}

	sRes << "************************************************************\n";

	return sRes.str();
}
