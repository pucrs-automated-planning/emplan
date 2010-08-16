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
// Starter.h: interface for the Starter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTER_H__46AD0FEE_F352_4DAC_AF3A_84BF07495859__INCLUDED_)
#define AFX_STARTER_H__46AD0FEE_F352_4DAC_AF3A_84BF07495859__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Debug.h"
#include "Consoleout.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "CommandLineOptions.h"
#include "OperatorParserProxy.h"
#include "GroundDataTable.h"
#include "GraphplanPlanner.h"
#include "PopPlanner.h"

#include "TimeTracker.h"

class Starter  
{
protected:
	CommandLineOptions options;

	bool runGraphplan(PredicateInstanceVector &pivStart, 
				  PredicateInstanceVector &pivGoal, 
				  OperatorInstanceVector &oivOperators);
	bool runPopPlanner(PredicateVector &pvStart,
					PredicateVector &pvGoal,
					OperatorVector &ovOperators);
public:
	Starter();
	Starter(CommandLineOptions &options);
	virtual ~Starter();

	virtual int start();

	virtual Starter &operator=(Starter &sRight);
};

#endif // !defined(AFX_STARTER_H__46AD0FEE_F352_4DAC_AF3A_84BF07495859__INCLUDED_)
