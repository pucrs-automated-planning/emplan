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
// Starter.cpp: implementation of the Starter class.
//
//////////////////////////////////////////////////////////////////////

#include "Starter.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Starter::Starter()
{

}

//////////////////////////////////////////////////////////////////////
// Starts up the EmPlanner Starter with the options
//////////////////////////////////////////////////////////////////////
Starter::Starter(CommandLineOptions &options)
{
	this->options=options;
}

Starter::~Starter()
{

}

//////////////////////////////////////////////////////////////////////
// Runs the Graphplan algorithm
//////////////////////////////////////////////////////////////////////
bool Starter::runGraphplan(PredicateInstanceVector &pivStart, 
				  PredicateInstanceVector &pivGoal, 
				  OperatorInstanceVector &oivOperators)
{
	TimeTracker tt;
	
	GraphplanPlanner *gp=NULL;
	bool bPlanSuccessfull;

	//And then start the planner keeping track of the time taken to do this
	if(options.iPlanRuns>1)
	{
		int iRuns=options.iPlanRuns;
		float fTotalTime=0;
		while((iRuns--)>=0)
		{
			delete gp;
			gp = new GraphplanPlanner(pivStart, pivGoal, oivOperators, options.bUseMemoization);
			tt.startTracker();
			bPlanSuccessfull=gp->plan();
			tt.stopTracker();
			fTotalTime+=tt.getElapsedTime();
		}
		float fAverageTime=fTotalTime/(1.0*options.iPlanRuns);
		WRITELN("Average running time: "<<fAverageTime<<"s");
		if(options.bWriteRuns)
		{
			WRITELN("Writing average time to: "<<options.sPlanRunsFile);
			ofstream oRuns(options.sPlanRunsFile.c_str());
			oRuns << "Average "<<fAverageTime;
			oRuns.close();
		}
	}else
	{
		gp = new GraphplanPlanner(pivStart, pivGoal, oivOperators, options.bUseMemoization);
		tt.startTracker();
		bPlanSuccessfull=gp->plan();
		tt.stopTracker();
	}
		
	//If the planning was sucessfull we should go on and write the plan wherever the options
	//tell us to
	if(bPlanSuccessfull)
	{
		WRITELN("Planning successful");

		//ParallelPlan pp=gp.getParallelPlan();
		GroundPlan *pp=gp->getPlan();
		if(options.bScreenPlan)
		{
			WRITELN("Plan:");
			WRITELN(pp->toString());
		}
		if(options.bWritePlan)
		{
			WRITELN("Writing plan to \""<< options.sOutputFile << "\"");
			ofstream out(options.sOutputFile.c_str());
			OperatorInstanceVector oiv=pp->toVector();
			string sOut=pp->toString(oiv);
			out << sOut;
		}
	}else
	{
		//If not, just inform the user
		WRITELN("No plan was found for the goals proposed.");
	}
	
	string sPlanTime="Planning took "+tt.toString();
	WRITELN(sPlanTime);

	//After everything has been completed, get the statistics and print them
	if(options.bWriteStats)
	{
		WRITELN("Writing statistics to " << options.sStatistics);
		ofstream outStats(options.sStatistics.c_str());
		outStats << gp->getStats();
		//outStats << sParseTime << endl;
		//outStats << sGroundTime << endl;
		outStats << sPlanTime << endl;
	}

	if(options.bDrawGraph)
	{
		WRITELN("Drawing graph to " << options.sDrawGraphFile);
		ofstream outDraw(options.sDrawGraphFile.c_str());
		gp->drawGraph(1, outDraw);
		outDraw.flush();
	}

	delete gp;

	return bPlanSuccessfull;
}

//////////////////////////////////////////////////////////////////////
// Runs the Pop algorithm
//////////////////////////////////////////////////////////////////////
bool Starter::runPopPlanner(PredicateVector &pvStart, PredicateVector &pvGoal, OperatorVector &ovOpers)
{
	TimeTracker tt;
	
	PopPlanner *pp=NULL;
	bool bPlanSuccessfull;

	//And then start the planner keeping track of the time taken to do this
	if(options.iPlanRuns>1)
	{
		int iRuns=options.iPlanRuns;
		float fTotalTime=0;
		while((iRuns--)>=0)
		{
			delete pp;
			pp = new PopPlanner(pvStart, pvGoal, ovOpers);
			tt.startTracker();
			bPlanSuccessfull=pp->plan();
			tt.stopTracker();
			fTotalTime+=tt.getElapsedTime();
		}
		
		float fAverageTime=fTotalTime/(1.0*options.iPlanRuns);
		WRITELN("Average running time: "<<fAverageTime<<"s");
		if(options.bWriteRuns)
		{
			WRITELN("Writing average time to: "<<options.sPlanRunsFile);
			ofstream oRuns(options.sPlanRunsFile.c_str());
			oRuns << "Average "<<fAverageTime;
			oRuns.close();
		}
	}else
	{
		pp = new PopPlanner(pvStart, pvGoal, ovOpers);
		tt.startTracker();
		bPlanSuccessfull=pp->plan();
		tt.stopTracker();
	}
		
	//If the planning was sucessfull we should go on and write the plan wherever the options
	//tell us to
	if(bPlanSuccessfull)
	{
		WRITELN("Planning successful");

		//ParallelPlan pp=gp.getParallelPlan();
		PartialOrderPlan *p=pp->getPopPlan();
		if(options.bScreenPlan)
		{
			WRITELN("Plan:");
			WRITELN(p->toString());
		}

		if(options.bWritePlan)
		{
			ofstream out(options.sOutputFile.c_str());
			OperatorVector oiv=p->toVector();
			string sOut=p->toString();
			out << sOut;
		}
	}else
	{
		//If not, just inform the user
		WRITELN("No plan was found for the goals proposed.");
	}
	
	string sPlanTime="Planning took "+tt.toString();
	WRITELN(sPlanTime);

	
	delete pp;

	return bPlanSuccessfull;
}

int Starter::start()
{
	//If everything went ok until here, create the parser
	OperatorParserProxy parser;
	//And parse the input files while keeping track of the required time.
	WRITELN(parser.toString());
	WRITELN("Parsing " << options.sInputFile);
	TimeTracker tt;
	tt.startTracker();
	bool bParseSuccessful=parser.parse(options.sInputFile);
	tt.stopTracker();
	string sParseTime="Parsing took " + tt.toString();
	WRITELN(sParseTime);

	//If the parser worked ok, then go on and start the planner
	if(bParseSuccessful)
	{
		//If we are running a ground planner then we should create the entire Herbrand Universe
		//from the non-ground Operator definitions
		tt.startTracker();

		SymbolTable *st=parser.getSymbolTable();
		TermSignatureMap tsm = st->getTermSignatures();
		PredicateSignatureMap psm = st->getPredicateSignatures();
		OperatorSignatureMap osm = st->getOperatorSignatures();
		GroundDataTable gdTable(tsm, psm, osm);
		tt.stopTracker();
		string sGroundTime="Creating ground instances took " + tt.toString();
		WRITELN(sGroundTime);
		if(options.bWriteGrounds)
		{
			string s=gdTable.toString();
			WRITELN("Writing ground instances to "<< options.sGrounds);
			ofstream outGrounds(options.sGrounds.c_str());
			outGrounds << s;
			outGrounds.flush();
		}

		//After that we should go on and convert the start conditions and the goals
		//into the Ground references
		PredicateInstanceVector pivStart=gdTable.convertPredicates(parser.getStart());
		PredicateInstanceVector pivGoal=gdTable.convertPredicates(parser.getGoal());
		OperatorInstanceVector oivOperators=gdTable.getOperators();

		bool bPlanSuccessfull;

		switch(options.iPlanner)
		{
			case 1:
				bPlanSuccessfull=runGraphplan(pivStart, pivGoal, oivOperators);
				break;
			case 2:
			{
				PredicateVector pvStart = parser.getStart();
				PredicateVector pvGoal = parser.getGoal();
				OperatorVector opOps = parser.getOperators();
				bPlanSuccessfull=runPopPlanner(pvStart, pvGoal, opOps);
			}
				break;
			default:
				bPlanSuccessfull=false;
				break;

		}

		return !bPlanSuccessfull;
	}else
	{
		return 1;
	}
}

Starter &Starter::operator =(Starter &sRight)
{
	if(&sRight != this)
	{
		this->options=sRight.options;
	}

	return *this;
}
