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
// PredicateNode.cpp: implementation of the PredicateNode class.
//
//////////////////////////////////////////////////////////////////////

#include "PredicateNode.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PredicateNode::PredicateNode()
{
	this->piPredicate=NULL;
}

PredicateNode::PredicateNode(PredicateInstance *piPredicate)
{
	this->piPredicate=piPredicate;
}

PredicateNode::~PredicateNode()
{

}

//////////////////////////////////////////////////////////////////////
// Marks the given index as a static mutex
//////////////////////////////////////////////////////////////////////
void PredicateNode::addMutex(int iMutex)
{
	//If the index is not already marked as mutex then add it
	if(find(ivMutexes.begin(), ivMutexes.end(), iMutex) == ivMutexes.end())
		this->ivMutexes.push_back(iMutex);
}

//////////////////////////////////////////////////////////////////////
// Marks the given index as a conditional mutex
// the diferentiation of mutexes is not yet implemented
// but it may possibly result in an increase in performance
//////////////////////////////////////////////////////////////////////
void PredicateNode::addCondMutex(int iMutex)
{
	//If the index is not already marked as mutex then add it
	if(find(ivMutexes.begin(), ivMutexes.end(), iMutex) == ivMutexes.end() &&
		find(ivCondMutexes.begin(), ivCondMutexes.end(), iMutex) == ivCondMutexes.end())
		this->ivCondMutexes.push_back(iMutex);
}

//////////////////////////////////////////////////////////////////////
// Checks whether the given index is mutex or not of this node
//////////////////////////////////////////////////////////////////////
bool PredicateNode::isMutex(int iMutex)
{
	return (find(ivMutexes.begin(), ivMutexes.end(), iMutex) != ivMutexes.end() ||
		find(ivCondMutexes.begin(), ivCondMutexes.end(), iMutex) != ivCondMutexes.end());
}

//////////////////////////////////////////////////////////////////////
// Counts the mutex relations this node has
//////////////////////////////////////////////////////////////////////
int PredicateNode::countMutexes()
{
	return ivMutexes.size()+ivCondMutexes.size();
}

//////////////////////////////////////////////////////////////////////
// Returns the list of mutexes this node has
//////////////////////////////////////////////////////////////////////
IntVector &PredicateNode::getMutexes()
{
	return this->ivMutexes;
}

//////////////////////////////////////////////////////////////////////
// Returns the predicate instance stored in this node
//////////////////////////////////////////////////////////////////////
PredicateInstance *PredicateNode::getPredicate()
{
	return this->piPredicate;
}

//////////////////////////////////////////////////////////////////////
// Marks the action index given as parameter as having a precondition
// relation to this node
//////////////////////////////////////////////////////////////////////
void PredicateNode::linkPrecondition(int iPreconditionIndex)
{
	//If there is no link to the referred index already
	if(find(ivPreconditionLinks.begin(), ivPreconditionLinks.end(), iPreconditionIndex) == ivPreconditionLinks.end())
		ivPreconditionLinks.push_back(iPreconditionIndex);
}

//////////////////////////////////////////////////////////////////////
// Returns the precondition links that this node has
//////////////////////////////////////////////////////////////////////
IntVector &PredicateNode::getPreconditionLinks()
{
	return this->ivPreconditionLinks;
}

//////////////////////////////////////////////////////////////////////
// Marks the action index given as parameter as having an effect
// relation to this node
//////////////////////////////////////////////////////////////////////
void PredicateNode::linkEffect(int iEffectIndex)
{
	//If there is no link to the referred index already
	if(find(ivEffectLinks.begin(), ivEffectLinks.end(), iEffectIndex) == ivEffectLinks.end())
		ivEffectLinks.push_back(iEffectIndex);
}

//////////////////////////////////////////////////////////////////////
// Returns the effect links that this node has
//////////////////////////////////////////////////////////////////////
IntVector &PredicateNode::getEffectLinks()
{
	return this->ivEffectLinks;
}

PredicateNode &PredicateNode::operator=(const PredicateNode &pnRight)
{
	if(this!=&pnRight)
	{
		this->piPredicate=pnRight.piPredicate;
		this->ivMutexes=pnRight.ivMutexes;
	}

	return *this;
}

bool PredicateNode::operator==(PredicateNode &pnRight)
{
	bool bRes=true;

	if(this != &pnRight)
	{
		bRes &= (this->piPredicate == pnRight.piPredicate);

		for(int i=0; bRes && (i<ivMutexes.size()); i++)
		{
			bRes &= ivMutexes[i]==pnRight.ivMutexes[i];
		}

		for(int i=0; bRes && (i<ivCondMutexes.size()); i++)
		{
			bRes &= ivCondMutexes[i]==pnRight.ivCondMutexes[i];
		}
	}else
		bRes=true;

	return bRes;
}

string PredicateNode::toString()
{
	ostringstream sRes;
	
	sRes << "[PredicateNode:";

	sRes << piPredicate->getKey();

	sRes << "M-";
	for(IntVector::iterator i=ivMutexes.begin(); i!=ivMutexes.end(); i++)
	{
		if(i!=ivMutexes.begin())
			sRes << ",";
		sRes << *i;
	}

	sRes << "|Pre-";
	for(IntVector::iterator i=ivPreconditionLinks.begin(); i!=ivPreconditionLinks.end(); i++)
	{
		if(i!=ivPreconditionLinks.begin())
			sRes << ",";
		sRes << *i;
	}

	sRes << "|Eff-";
	for(IntVector::iterator i=ivEffectLinks.begin(); i!=ivEffectLinks.end(); i++)
	{
		if(i!=ivEffectLinks.begin())
			sRes << ",";
		sRes << *i;
	}

	sRes << "]";

	return sRes.str();
}
