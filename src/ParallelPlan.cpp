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
// ParallelPlan.cpp: implementation of the ParallelPlan class.
//
//////////////////////////////////////////////////////////////////////

#include "ParallelPlan.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ParallelPlan::ParallelPlan()
{

}

ParallelPlan::ParallelPlan(int iSize)
{
	pplv.resize(iSize);
}

ParallelPlan::~ParallelPlan()
{

}

void ParallelPlan::addAction(int iLevel, OperatorInstance *oiAction)
{
	if(pplv.size()<=iLevel)
	{
		pplv.resize(iLevel+1);
	}

	if(find(pplv[iLevel].begin(), pplv[iLevel].end(), oiAction)==pplv[iLevel].end())
	{
		pplv[iLevel].push_back(oiAction);
	}
}

ParallelPlanLevel &ParallelPlan::operator[](int iLevel)
{
	return pplv[iLevel];
}

OperatorInstanceVector ParallelPlan::toVector()
{
	OperatorInstanceVector oivRes;

	for(ParallelPlanLevelVector::iterator i=pplv.begin(); i!=pplv.end() ;i++)
	{
		for(ParallelPlanLevel::iterator j=i->begin(); j!=i->end(); j++)
		{
			oivRes.push_back(*j);
		}
	}
	
	return oivRes;
}

string ParallelPlan::toString(OperatorInstanceVector &oiv)
{
	ostringstream out;

	for(OperatorInstanceVector::iterator i=oiv.begin(); i!=oiv.end(); i++)
	{
		OperatorInstance *oi=*i;
		out << oi->getKey() << ".\n";
	}

	return out.str();
}

string ParallelPlan::toString()
{
	ostringstream out;

	for(int i=0; i<pplv.size(); i++)
	{
		out << "Level " << i << ":\n";
		for(int j=0; j<pplv[i].size(); j++)
		{
			out << "\t" << pplv[i][j]->getKey() << "\n";
		}
	}

	return out.str();
}
