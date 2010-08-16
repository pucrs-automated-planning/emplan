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
// PartialOrderPlan.h: interface for the PartialOrderPlan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARTIALORDERPLAN_H__9319F349_BCB3_4792_B802_2AF44C65C2C2__INCLUDED_)
#define AFX_PARTIALORDERPLAN_H__9319F349_BCB3_4792_B802_2AF44C65C2C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <algorithm>
using std::sort;

#include <string>
using std::string;

#include "Plan.h"

#include "Debug.h"

#include "UnificationAlgorithm.h"
#include "RobinsonUnify.h"

#include "Term.h"
#include "Predicate.h"
#include "Operator.h"

#include "CausalLinkList.h"
#include "OrderLinkList.h"

typedef map<Predicate*, Operator*, less<Predicate*> > OperatorMap;

class PartialOrderPlan : public Plan  
{
protected:
	UnificationAlgorithm *unification;

	//The operators that are currently used in the plan
	OperatorVector ovSteps;
	//The "Pseudo-Operator" corresponding to the start state
	Operator *oStart;
	//The "Pseudo-Operator" corresponding to the goal state
	Operator *oGoal;
	//The causal links between plan steps denoting the linking predicates
	CausalLinkList cllCauses;

	//The order links between plan steps
	OrderLinkList ollOrder;

	//The precondition-predicates that have not been dealt
	//with by the steps currently in the plan along with their associated operators
	OperatorMap omUnfulfilled;

	void sortSteps();
public:
	PartialOrderPlan();
	PartialOrderPlan(PredicateVector &pvStart, PredicateVector &pvGoal);
	virtual ~PartialOrderPlan();

	bool isSolution();
	Predicate *selectSubgoal();
	Operator *getOperatorFromGoal(Predicate *p);
	bool chooseOperator(Predicate *pCause, Operator *oCause, OperatorVector ovOperators);
	bool resolveThreats();

	PartialOrderPlan &operator=(PartialOrderPlan &popRight);

	virtual OperatorVector toVector();
	virtual string toString();
};

#endif // !defined(AFX_PARTIALORDERPLAN_H__9319F349_BCB3_4792_B802_2AF44C65C2C2__INCLUDED_)
