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
// CommandLineOptions.cpp: implementation of the CommandLineOptions class.
//
//////////////////////////////////////////////////////////////////////

#include "CommandLineOptions.h"

//////////////////////////////////////////////////////////////////////
// Constants
//////////////////////////////////////////////////////////////////////

const int CommandLineOptions::GRAPHPLAN=1;
const int CommandLineOptions::POP=2;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CommandLineOptions::CommandLineOptions()
{
	this->setDefaults();
}

CommandLineOptions::~CommandLineOptions()
{

}

CommandLineOptions::CommandLineOptions(int iArgc, char *sArgv[])
{
	this->setDefaults();
	this->bParseSuccessfull=parseOptions(iArgc, sArgv);
}

//////////////////////////////////////////////////////////////////////
// Parses the parameters given in the 
//////////////////////////////////////////////////////////////////////
bool CommandLineOptions::parseOptions(int argc, char *argv[])
{
	bool bRes=true;

	if((argc > 1) && (argv[1][0] != '-'))
	{
		sInputFile=argv[1];
	}else
		bRes=false;

	for(int i=2; bRes && i<argc; i++)
	{
		string sPar=argv[i];
		if(sPar == "-plan")
		{
			bWritePlan=true;
			if((argc > i+1) && (argv[i+1][0] != '-'))
			{
				i++;
				sOutputFile=argv[i];
			}
		}else if(sPar == "-grounds")
		{
			bWriteGrounds=true;
			if((argc > i+1) && (argv[i+1][0]!='-'))
			{
				i++;
				sGrounds=argv[i];
			}
		}else if(sPar == "-stats")
		{
			bWriteStats=true;
			if((argc > i+1) && (argv[i+1][0]!='-'))
			{
				i++;
				sStatistics=argv[i];
			}
		}else if(sPar == "-draw")
		{
			bDrawGraph=true;
			if((argc > i+1) && (argv[i+1][0]!='-'))
			{
				i++;
				sDrawGraphFile=argv[i];
			}
		}else if(sPar == "-nomemo")
		{
			bUseMemoization=false;
		}else if(sPar == "-noscreen")
		{
			bScreenPlan=false;
		}else if(sPar == "-runs")
		{
			if((argc > i+1) && (argv[i+1][0]!='-'))
			{
				i++;
				int iRuns=atoi(argv[i]);
				if(iRuns>0)
					iPlanRuns=iRuns;
				
				if((argc > i+1) && (argv[i+1][0]!='-'))
				{
					i++;
					bWriteRuns=true;
					sPlanRunsFile=argv[i];
				}
			}
		}else if(sPar == "-planner")
		{
			if((argc > i+1) && (argv[i+1][0]!='-'))
			{
				i++;
				string sPlanner=argv[i];
				iPlanner=selectPlanner(sPlanner);
				if(iPlanner==-1)
				{
					bRes=false;
					string sError = sPlanner+" is not a valid planner.";
					printCommandLineError(sError);
				}
			}else
			{
				bRes=false;
				string sError = "The -planner option requires a planner name.";
				printCommandLineError(sError);
			}
		}else
		{
			bRes=false;
			string sError=argv[i];
			sError+=" is not a valid option.";
			printCommandLineError(sError);
		}
			
	}
	return bRes;
}

int CommandLineOptions::selectPlanner(string sPlanner)
{
	if(sPlanner == "graphplan")
	{
		return this->GRAPHPLAN;
	}else if(sPlanner == "pop")
	{
		return this->POP;
	}else
	{
		return -1;
	}
}

void CommandLineOptions::setDefaults()
{
	sInputFile="operators.txt";
	bWritePlan=false;
	sOutputFile="plan.txt";
	bScreenPlan=true;
	bWriteGrounds=false;
	sGrounds="grounds.txt";
	bWriteStats=false;
	sStatistics="stats.txt";
	bDrawGraph=false;
	sDrawGraphFile="graph.txt";
	bUseMemoization=true;
	//The number of times to run the same planning problem to gather time statistics
	iPlanRuns=1;
	//Whether or not to write final run times to a file
	bWriteRuns=false;
	//The filename where these times should be written to
	sPlanRunsFile="runstats.txt";

	//The planner selected for execution
	iPlanner=this->GRAPHPLAN;
}

bool CommandLineOptions::parseSuccessfull()
{
	return this->bParseSuccessfull;
}

void CommandLineOptions::printCommandLineOptions(string sProgname)
{
	cout << "Usage:" << endl;
	cout << "\t" << sProgname << " <operators file> [options]" << endl;
	cout << "\tOptions are: " << endl;

	cout << "\t\t-planner <planner_name> - Uses planner_name as the planner algorithm." << endl;
	cout << "\t\tPossible planners are:" << endl;
	cout << "\t\t\tgraphplan" << endl;
	cout << "\t\t\tpop" << endl;
	cout << "\t\t-plan [plan_file] - Writes the plan to plan_file." << endl;
	
	cout << "\t\t-noscreen - Does not print the plan to the screen." << endl;
	cout << "\t\t-grounds [grounds_file] - Writes the ground instances to grounds_file." << endl;
	cout << "\t\t-stats [stats_file] - Writes the statistics to stats_file." << endl;
	cout << "\t\t-runs <number of runs> [runs_file]- Runs the planner a number of times and average them." << endl;
	
	cout << "\t\t-draw [draw_file] - Draws the graph to draw_file." << endl;
	cout << "\t\t-nomemo - Does not use memoization." << endl;
}

void CommandLineOptions::printCommandLineError(string sError)
{
	cerr << sError << endl;
}

CommandLineOptions &CommandLineOptions::operator=(CommandLineOptions &cloRight)
{
	if(&cloRight != this)
	{
		this->sInputFile=cloRight.sInputFile;
		this->bWritePlan=cloRight.bWritePlan;
		this->sOutputFile=cloRight.sOutputFile;
		this->bScreenPlan=cloRight.bScreenPlan;
		this->bWriteGrounds=cloRight.bWriteGrounds;
		this->sGrounds=cloRight.sGrounds;
		this->bWriteStats=cloRight.bWriteStats;
		this->sStatistics=cloRight.sStatistics;
		this->bDrawGraph=cloRight.bDrawGraph;
		this->sDrawGraphFile=cloRight.sDrawGraphFile;
		this->bUseMemoization=cloRight.bUseMemoization;
		this->iPlanRuns=cloRight.iPlanRuns;
		this->bWriteRuns=cloRight.bWriteRuns;
		this->sPlanRunsFile=cloRight.sPlanRunsFile;
		this->iPlanner=cloRight.iPlanner;
	}

	return *this;
}
