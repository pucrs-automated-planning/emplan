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
/**
 * ActionNode.cpp: implementation of the ActionNode class.
 *
 *  Created on: Aug 15, 2002
 *      Author: meneguzzi
 */

#include "ActionNode.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ActionNode::ActionNode()
{
	this->oiAction=NULL;
}

ActionNode::ActionNode(OperatorInstance *oiAction)
{
	this->oiAction=oiAction;
}

ActionNode::~ActionNode()
{

}

//////////////////////////////////////////////////////////////////////
// Marks the given index as a static mutex
//////////////////////////////////////////////////////////////////////
void ActionNode::addMutex(int iMutex)
{
	//Permanent mutexes are more important than conditional mutexes, therefore
	//they should be selected first, and when a mutex is both conditional (because
	//it was created by checking conditional mutexes in the level before)
	//and permanent, then it is stored in the permanent mutexes list
	if(find(ivMutexes.begin(), ivMutexes.end(), iMutex) == ivMutexes.end())
		this->ivMutexes.push_back(iMutex);
}

//////////////////////////////////////////////////////////////////////
// Marks the given index as a conditional mutex
// the diferentiation of mutexes is not yet implemented
// but it may possibly result in an increase in performance
//////////////////////////////////////////////////////////////////////
void ActionNode::addCondMutex(int iMutex)
{
	if(find(ivMutexes.begin(), ivMutexes.end(), iMutex) == ivMutexes.end() ||
		find(ivCondMutexes.begin(), ivCondMutexes.end(), iMutex) == ivCondMutexes.end())
		this->ivCondMutexes.push_back(iMutex);
}

//////////////////////////////////////////////////////////////////////
// Checks whether the given index is mutex or not of this node
//////////////////////////////////////////////////////////////////////
bool ActionNode::isMutex(int iMutex)
{
	return (find(ivMutexes.begin(), ivMutexes.end(), iMutex) != ivMutexes.end() ||
		find(ivCondMutexes.begin(), ivCondMutexes.end(), iMutex) != ivCondMutexes.end());
}

//////////////////////////////////////////////////////////////////////
// Counts the mutex relations this node has
//////////////////////////////////////////////////////////////////////
int ActionNode::countMutexes()
{
	return ivMutexes.size();
}

//////////////////////////////////////////////////////////////////////
// Returns the list of mutexes this node has
//////////////////////////////////////////////////////////////////////
IntVector &ActionNode::getMutexes()
{
	return this->ivMutexes;
}

//////////////////////////////////////////////////////////////////////
// Returns the action instance stored in this node
//////////////////////////////////////////////////////////////////////
OperatorInstance *ActionNode::getAction()
{
	return this->oiAction;
}

//////////////////////////////////////////////////////////////////////
// Marks the predicate index given as parameter as having a precondition
// relation to this node
//////////////////////////////////////////////////////////////////////
void ActionNode::linkPrecondition(int iPreconditionIndex)
{
	//If there is no link to the referred index already
	if(find(ivPreconditionLinks.begin(), ivPreconditionLinks.end(), iPreconditionIndex) == ivPreconditionLinks.end())
		ivPreconditionLinks.push_back(iPreconditionIndex);
}

//////////////////////////////////////////////////////////////////////
// Returns the precondition links that this node has
//////////////////////////////////////////////////////////////////////
IntVector &ActionNode::getPreconditionLinks()
{
	return this->ivPreconditionLinks;
}

//////////////////////////////////////////////////////////////////////
// Marks the predicate index given as parameter as having an effect
// relation to this node
//////////////////////////////////////////////////////////////////////
void ActionNode::linkEffect(int iEffectIndex)
{
	//If there is no link to the referred index already
	if(find(ivEffectLinks.begin(), ivEffectLinks.end(), iEffectIndex) == ivEffectLinks.end())
		ivEffectLinks.push_back(iEffectIndex);
}

//////////////////////////////////////////////////////////////////////
// Returns the effect links that this node has
//////////////////////////////////////////////////////////////////////
IntVector &ActionNode::getEffectLinks()
{
	return this->ivEffectLinks;
}
	
ActionNode &ActionNode::operator=(const ActionNode &anRight)
{
	if(this!=&anRight)
	{
		this->oiAction=anRight.oiAction;
		this->ivMutexes=anRight.ivMutexes;
	}

	return *this;
}

//The equals operator verifies if all the mutexes are equal between
//two action levels
bool ActionNode::operator==(ActionNode &anRight)
{
	bool bRes=true;

	if(this!=&anRight)
	{
		bRes &= (this->oiAction == anRight.oiAction);

		for(int i=0; bRes && (i<ivMutexes.size()); i++)
		{
			bRes &= ivMutexes[i]==anRight.ivMutexes[i];
		}

		for(int i=0; bRes && (i<ivCondMutexes.size()); i++)
		{
			bRes &= ivCondMutexes[i]==anRight.ivCondMutexes[i];
		}
	}else
		bRes=true;

	return bRes;
}

string ActionNode::toString()
{
	ostringstream sRes;
	
	sRes <<"[ActionNode:";

	sRes << oiAction->getKey();

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
