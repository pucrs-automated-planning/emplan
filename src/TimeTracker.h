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
// TimeTracker.h: interface for the TimeTracker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMETRACKER_H__A96E0C6D_5FCC_4EE0_9424_C1EC8ABF5398__INCLUDED_)
#define AFX_TIMETRACKER_H__A96E0C6D_5FCC_4EE0_9424_C1EC8ABF5398__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern "C"{
	#include <time.h>
	#include <sys/timeb.h>
	#include <sys/types.h>
};

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

class TimeTracker  
{
protected:
#ifdef WIN32
	struct _timeb startTime;
	struct _timeb endTime;
#else
	struct timeb startTime;
	struct timeb endTime;
#endif

	long lSeconds;
	long lMilli;
public:
	TimeTracker();
	virtual ~TimeTracker();

	void stopTracker();
	void startTracker();

	long getElapsedSeconds();
	long getElapsedMilliseconds();
	double getElapsedTime();

	string toString();
};

#endif // !defined(AFX_TIMETRACKER_H__A96E0C6D_5FCC_4EE0_9424_C1EC8ABF5398__INCLUDED_)
