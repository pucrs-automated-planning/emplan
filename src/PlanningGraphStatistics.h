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
// PlanningGraphStatistics.h: interface for the PlanningGraphStatistics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANNINGGRAPHSTATISTICS_H__767FFF9F_542A_413F_BCD9_F31CB0AA769D__INCLUDED_)
#define AFX_PLANNINGGRAPHSTATISTICS_H__767FFF9F_542A_413F_BCD9_F31CB0AA769D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

typedef vector<int> IntVector;

class PlanningGraphStatistics  
{
protected:
	IntVector ivActionNodes;
	IntVector ivPredicateNodes;
	IntVector ivPreconditionEdges;
	IntVector ivEffectEdges;

	IntVector ivActionMutexes;
	IntVector ivPredicateMutexes;
public:
	PlanningGraphStatistics();
	virtual ~PlanningGraphStatistics();

	void setActionNodes(int iActionLevel, int iNodes);
	void setPredicateNodes(int iPredicateLevel, int iNodes);
	void setPreconditionEdges(int iActionLevel, int iEdges);
	void setEffectEdges(int iActionLevel, int iEdges);
	void setActionMutexes(int iActionLevel, int iMutexes);
	void setPredicateMutexes(int iPredicateLevel, int iMutexes);

	int getActionNodes(int iActionLevel);
	int getPredicateNodes(int iPredicateLevel);
	int getPreconditionEdges(int iActionLevel);
	int getEffectEdges(int iActionLevel);
	int getActionMutexes(int iActionLevel);
	int getPredicateMutexes(int iPredicateLevel);

	int totalActionNodes();
	int totalPredicateNodes();
	int totalPreconditionEdges();
	int totalEffectEdges();
	int totalActionMutexes();
	int totalPredicateMutexes();

	PlanningGraphStatistics &operator=(PlanningGraphStatistics &pgsRight);

	string toString();
};

#endif // !defined(AFX_PLANNINGGRAPHSTATISTICS_H__767FFF9F_542A_413F_BCD9_F31CB0AA769D__INCLUDED_)
