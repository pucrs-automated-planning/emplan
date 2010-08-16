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
#include "Debug.h"
#include "Consoleout.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "Starter.h"
#include "TimeTracker.h"

int main(int argc, char *argv[])
{
	cout << "Embedded Planner version 1.0\n";

	//Parse the command line arguments
	CommandLineOptions options(argc, argv);
	
	if(!options.parseSuccessfull())
	{
		string sProgname=argv[0];
		options.printCommandLineOptions(sProgname);
		exit(1);
	}

	
	Starter s(options);
	int iRes=s.start();

	WRITELN("");

	return iRes;
}
