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
// GraphplanPlanner.cpp: implementation of the GraphplanPlanner class.
//
//////////////////////////////////////////////////////////////////////

#include "GraphplanPlanner.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//Initializes the planner using the code inherited from the GroundPlanner class
GraphplanPlanner::GraphplanPlanner(PredicateInstanceVector &pivStart, PredicateInstanceVector &pivGoal, OperatorInstanceVector &oivOperators, bool bUseMemoization):GroundPlanner(pivStart, pivGoal, oivOperators)
{
	this->bUseMemoization=bUseMemoization;
	this->bPlanPossible=true;
	this->bWritePartial=false;
}

GraphplanPlanner::~GraphplanPlanner()
{

}

//////////////////////////////////////////////////////////////////////
// Performs the extract solution in the planning graph and checks
//for the termination conditions
//////////////////////////////////////////////////////////////////////
bool GraphplanPlanner::extractSolution(PlanningGraph &pg)
{
	bool bRes=false;

	int iLastLevel=pg.size()-1;
	if(pg.goalsPossible(pivGoal))
	{
		PRINTL("Goals are possible at level "<<iLastLevel<<" trying to extract solution")
		WRITE("S");
		bRes=pg.extractSolution(pivGoal);
		//PAUSE
		if(bRes)
		{
			PRINTL("Solution extraction sucessfull")
			this->ppPlan=pg.getPlan();
		}else
		{
			PRINTL("Solution extraction failed")
			//If it happens that the memoization table stabilizes,
			//then break planning
			bPlanPossible=pg.planPossible();
			if(!bPlanPossible)
			{
				PRINTL("Memoization table stop condition reached.")
				PRINTL("No plan is possible for this domain.")
			}
		}
	}else
	{
		//If the goals are not possible and the graph has levelled off, then
		//No goal is possible
		bPlanPossible=!pg.graphLevelledOff();
	}
	return bRes;
}

//////////////////////////////////////////////////////////////////////
// Collects the statistics about the planning process that have been
//stored in the planning graph
//////////////////////////////////////////////////////////////////////
void GraphplanPlanner::gatherStats(PlanningGraph &pg)
{
	sStats=pg.getStatistics().toString();
}

//////////////////////////////////////////////////////////////////////
// Method responsible for the actual planning, this method implements 
//the Graphplan algorithm
//////////////////////////////////////////////////////////////////////
bool GraphplanPlanner::plan()
{
	bool bRes=false;

	//Initialize the planning graph
	PlanningGraph pg(pivStart, bUseMemoization);

	//Just to check if the initial state are not the goals
	bRes=pg.goalsPossible(pivGoal,0);

	//While the plan is still possible and the goals have not been reached
	while(bPlanPossible && !bRes)
	{
		PRINTL("Expanding graph")
		WRITE("X");
		pg.expand(oivOperators);
		WRITE("M");
		
		PRINTL("Resulting graph:")
		PRINTL(pg.toString());

		//If the writing of partial graphs is enabled, then write it at every expansion
		if(this->bWritePartial)
		{
			ostringstream ossfile;
			ossfile << sWritePartial << (pg.size()/2) << ".txt";
			this->pg=pg;
			
			ofstream outfile(ossfile.str().c_str());
			this->drawGraph(0, outfile);
			ossfile.flush();
			outfile.flush();
		}
		
		bRes=this->extractSolution(pg);
		
		WRITE("*");
	}

	this->pg=pg;

	return bRes;
}

//////////////////////////////////////////////////////////////////////
// If a plan was found using the plan method, it is returned as a
//vector of actions, else the vector contains nothing
//////////////////////////////////////////////////////////////////////
OperatorInstanceVector GraphplanPlanner::getPlanVector()
{
	return ppPlan.toVector();
}

//////////////////////////////////////////////////////////////////////
// Returns a Ground plan, conforming to the general interface for the
//ground planner
//////////////////////////////////////////////////////////////////////
GroundPlan *GraphplanPlanner::getPlan()
{
	return &ppPlan;
}

//////////////////////////////////////////////////////////////////////
// Returns a parallel plan, that is, a plan which allows the plan 
//levels to be seen
//////////////////////////////////////////////////////////////////////
ParallelPlan &GraphplanPlanner::getParallelPlan()
{
	return ppPlan;
}

//////////////////////////////////////////////////////////////////////
// Sets the memoization on and off
//A warning though, if memoization is not set, there is no guarantee
//that the planner algorithm will ever stop
//////////////////////////////////////////////////////////////////////
void GraphplanPlanner::setMemoization(bool bUseMemoization)
{
	this->bUseMemoization=bUseMemoization;
}

//////////////////////////////////////////////////////////////////////
// Sets the partial Writing of the graph on and off
//////////////////////////////////////////////////////////////////////
void GraphplanPlanner::setWritePartial(bool bWritePartial, string sWritePartial)
{
	this->bWritePartial=bWritePartial;
	this->sWritePartial=sWritePartial;
}

//////////////////////////////////////////////////////////////////////
// Uses a graph drawing algorithm to draw the graph and store it into
//the output stream given as parameter
//////////////////////////////////////////////////////////////////////
ostream &GraphplanPlanner::drawGraph(int iFormat, ostream &out)
{
	FigPlanningGraphDrawer fgpd;

	return fgpd.drawGraph(pg.getPredicateLevels(), pg.getActionLevels(), out);
}

//////////////////////////////////////////////////////////////////////
// Collects the statistics in the planning graph and return them
string GraphplanPlanner::getStats()
{
	gatherStats(pg);
	return sStats;
}

//Creates a string representation of the planner, whatever it may be
string GraphplanPlanner::toString()
{
	ostringstream sRes;

	sRes << sStats;

	return sRes.str();
}
