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
// TimeTracker.cpp: implementation of the TimeTracker class.
//
//////////////////////////////////////////////////////////////////////

#include "TimeTracker.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TimeTracker::TimeTracker()
{

}

TimeTracker::~TimeTracker()
{

}

void TimeTracker::startTracker()
{
#ifdef WIN32
	_ftime(&startTime);
#else
	ftime(&startTime);
#endif
}

void TimeTracker::stopTracker()
{
#ifdef WIN32
	_ftime(&endTime);
#else
	ftime(&endTime);
#endif

	this->lSeconds=endTime.time - startTime.time;
	if(lSeconds!=0)
	{
		if(endTime.millitm >= startTime.millitm)
		{
			this->lMilli=endTime.millitm - startTime.millitm;
		}else
		{
			lSeconds--;
			this->lMilli=endTime.millitm + startTime.millitm;
			if(lMilli >= 1000)
			{
				lSeconds++;
				lMilli-=1000;
			}
		}
	}else
	{
		this->lMilli=endTime.millitm - startTime.millitm;
	}
}

long TimeTracker::getElapsedSeconds()
{
	return this->lSeconds;
}

long TimeTracker::getElapsedMilliseconds()
{
	return this->lMilli;
}

double TimeTracker::getElapsedTime()
{
	double dTime=this->lSeconds;
	dTime+=(this->lMilli/1000.0);

	return dTime;
}

string TimeTracker::toString()
{
	ostringstream sRes;

	sRes << this->lSeconds << ".";
	if(lMilli < 100)
		sRes << "0";
	if(lMilli < 10)
		sRes << "0";
	
	sRes << this->lMilli;
	sRes << "s";

	return sRes.str();
}
