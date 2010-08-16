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
// PlanningGraphStatistics.cpp: implementation of the PlanningGraphStatistics class.
//
//////////////////////////////////////////////////////////////////////

#include "PlanningGraphStatistics.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PlanningGraphStatistics::PlanningGraphStatistics()
{

}

PlanningGraphStatistics::~PlanningGraphStatistics()
{

}

void PlanningGraphStatistics::setActionNodes(int iActionLevel, int iNodes)
{
	if(iActionLevel >= ivActionNodes.size())
	{
		ivActionNodes.resize(iActionLevel+1);
	}

	ivActionNodes[iActionLevel]=iNodes;
}

void PlanningGraphStatistics::setPredicateNodes(int iPredicateLevel, int iNodes)
{
	if(iPredicateLevel >= ivPredicateNodes.size())
	{
		ivPredicateNodes.resize(iPredicateLevel+1);
	}

	ivPredicateNodes[iPredicateLevel]=iNodes;
}

void PlanningGraphStatistics::setPreconditionEdges(int iActionLevel, int iEdges)
{
	if(iActionLevel >= ivPreconditionEdges.size())
	{
		ivPreconditionEdges.resize(iActionLevel+1);
	}

	ivPreconditionEdges[iActionLevel]=iEdges;
}

void PlanningGraphStatistics::setEffectEdges(int iActionLevel, int iEdges)
{
	if(iActionLevel >= ivEffectEdges.size())
	{
		ivEffectEdges.resize(iActionLevel+1);
	}

	ivEffectEdges[iActionLevel]=iEdges;
}

void PlanningGraphStatistics::setActionMutexes(int iActionLevel, int iMutexes)
{
	if(iActionLevel >= ivActionMutexes.size())
	{
		ivActionMutexes.resize(iActionLevel+1);
	}

	ivActionMutexes[iActionLevel]=iMutexes;
}

void PlanningGraphStatistics::setPredicateMutexes(int iPredicateLevel, int iMutexes)
{
	if(iPredicateLevel >= ivPredicateMutexes.size())
	{
		ivPredicateMutexes.resize(iPredicateLevel+1);
	}

	ivPredicateMutexes[iPredicateLevel]=iMutexes;
}

int PlanningGraphStatistics::getActionNodes(int iActionLevel)
{
	if(iActionLevel >= ivActionNodes.size())
	{
		return 0;
	}else
		return ivActionNodes[iActionLevel];
}

int PlanningGraphStatistics::getPredicateNodes(int iPredicateLevel)
{
	if(iPredicateLevel >= ivPredicateNodes.size())
	{
		return 0;
	}else
		return ivPredicateNodes[iPredicateLevel];
}

int PlanningGraphStatistics::getPreconditionEdges(int iActionLevel)
{
	if(iActionLevel >= ivPreconditionEdges.size())
	{
		return 0;
	}else
		return ivPreconditionEdges[iActionLevel];
}

int PlanningGraphStatistics::getEffectEdges(int iActionLevel)
{
	if(iActionLevel >= ivEffectEdges.size())
	{
		return 0;
	}else
		return ivEffectEdges[iActionLevel];
}

int PlanningGraphStatistics::getActionMutexes(int iActionLevel)
{
	if(iActionLevel >= ivActionMutexes.size())
	{
		return 0;
	}else
		return ivActionMutexes[iActionLevel];
}

int PlanningGraphStatistics::getPredicateMutexes(int iPredicateLevel)
{
	if(iPredicateLevel >= ivPredicateMutexes.size())
	{
		return 0;
	}else
		return ivPredicateMutexes[iPredicateLevel];
}

int PlanningGraphStatistics::totalActionNodes()
{
	int iRes=0;

	for(IntVector::iterator i=ivActionNodes.begin(); i!=ivActionNodes.end(); i++)
	{
		iRes += (*i);
	}

	return iRes;
}

int PlanningGraphStatistics::totalPredicateNodes()
{
	int iRes=0;

	for(IntVector::iterator i=ivPredicateNodes.begin(); i!=ivPredicateNodes.end(); i++)
	{
		iRes += (*i);
	}

	return iRes;
}

int PlanningGraphStatistics::totalPreconditionEdges()
{
	int iRes=0;

	for(IntVector::iterator i=ivPreconditionEdges.begin(); i!=ivPreconditionEdges.end(); i++)
	{
		iRes += (*i);
	}

	return iRes;
}

int PlanningGraphStatistics::totalEffectEdges()
{
	int iRes=0;

	for(IntVector::iterator i=ivEffectEdges.begin(); i!=ivEffectEdges.end(); i++)
	{
		iRes += (*i);
	}

	return iRes;
}

int PlanningGraphStatistics::totalActionMutexes()
{
	int iRes=0;

	for(IntVector::iterator i=ivActionMutexes.begin(); i!=ivActionMutexes.end(); i++)
	{
		iRes += (*i);
	}

	return iRes;
}

int PlanningGraphStatistics::totalPredicateMutexes()
{
	int iRes=0;

	for(IntVector::iterator i=ivPredicateMutexes.begin(); i!=ivPredicateMutexes.end(); i++)
	{
		iRes += (*i);
	}

	return iRes;
}

PlanningGraphStatistics &PlanningGraphStatistics::operator=(PlanningGraphStatistics &pgsRight)
{
	if(this!=&pgsRight)
	{
		this->ivActionNodes=pgsRight.ivActionNodes;
		this->ivPredicateNodes=pgsRight.ivPredicateNodes;
		this->ivPreconditionEdges=pgsRight.ivPreconditionEdges;
		this->ivEffectEdges=pgsRight.ivEffectEdges;
		this->ivActionMutexes=pgsRight.ivActionMutexes;
		this->ivPredicateMutexes=pgsRight.ivPredicateMutexes;
	}

	return *this;
}

string PlanningGraphStatistics::toString()
{
	ostringstream out;

	out << "Planning Graph statistics: \n";

	int iGraphSize=ivPredicateNodes.size()*2;

	for(int i=0; i<iGraphSize; i++)
	{
		out << "Level: " << i << "\n";
		if((i%2)!=0)//If it is an action level
		{
			int iActionLevel=i/2;
			out << "\t" << "Precondition Edges: " << this->getPreconditionEdges(iActionLevel) << "\n";
			out << "\t" << "Action Nodes: " << this->getActionNodes(iActionLevel) << "\n";
			out << "\t" << "Action Mutexes: " << this->getActionMutexes(iActionLevel) << "\n";
			out << "\t" << "Effect Edges: " << this->getEffectEdges(iActionLevel) << "\n";
		}else
		{
			int iPredicateLevel=i/2;
			out << "\t" << "Predicate Nodes: " << this->getPredicateNodes(iPredicateLevel) << "\n";
			out << "\t" << "Predicate Mutexes: " << this->getPredicateMutexes(iPredicateLevel) << "\n";
		}
	}

	out << "Total Predicate Nodes: " << this->totalPredicateNodes() << "\n";
	out << "Total Action Nodes: " << this->totalActionNodes() << "\n";
	out << "Total Precondition Edges: " << this->totalPreconditionEdges() << "\n";
	out << "Total Effect Edges: " << this->totalEffectEdges() << "\n";
	out << "Total Action Mutexes: " << this->totalActionMutexes() << "\n";
	out << "Total Predicate Mutexes: " << this->totalPredicateMutexes() << "\n";

	return out.str();
}
