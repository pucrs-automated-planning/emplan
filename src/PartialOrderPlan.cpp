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
// PartialOrderPlan.cpp: implementation of the PartialOrderPlan class.
//
//////////////////////////////////////////////////////////////////////

#include "PartialOrderPlan.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
PartialOrderPlan::PartialOrderPlan()
{

}

PartialOrderPlan::PartialOrderPlan(PredicateVector &pvStart, PredicateVector &pvGoal)
{
	PredicateVector pvEmpty;
	TermVector dvEmpty;

	this->oStart=new Operator("start", dvEmpty, pvEmpty, pvStart, true, false);
	this->oGoal=new Operator("goal", dvEmpty, pvGoal, pvEmpty, true, false);
	
	ovSteps.push_back(oStart);
	ovSteps.push_back(oGoal);

	assert(oStart!=NULL && oGoal!=NULL);

	ollOrder.addOrderLink(oStart, oGoal);

	unification = new RobinsonUnify();
}

PartialOrderPlan::~PartialOrderPlan()
{
	for(OperatorVector::iterator i=ovSteps.begin(); i!=ovSteps.end(); i++)
	{
		delete *i;
	}
}

//////////////////////////////////////////////////////////////////////
// According to "http://www.cs.wisc.edu/~dyer/cs540/notes/pop.html", 
//if there is no CausalLink to a given precondition, then this 
//precondition has not been dealt with, therefore, the plan is not 
//complete.
//
// This mehtod not only determines if the plan is complete or not, but 
//it "calculates" the difference between the current plan, and the 
//goal state.
//////////////////////////////////////////////////////////////////////
bool PartialOrderPlan::isSolution()
{
	bool bRes=true;
	this->omUnfulfilled.clear();
	
	for(OperatorVector::iterator i=ovSteps.begin(); i!=ovSteps.end(); i++)
	{
		Operator *o=(*i);
		PredicateVector pvPreconds=o->getPreconds();
		for(PredicateVector::iterator j=pvPreconds.begin(); j!=pvPreconds.end(); j++)
		{
			Predicate *p=(*j);
			if(!cllCauses.isFulfilled(p))
			{
				this->omUnfulfilled[p]=o;
				bRes=false;
			}
		}
	}

	return bRes;
}

//////////////////////////////////////////////////////////////////////
// Selects an unfulfilled objective among those that were selected
//in the isSolution method.
//////////////////////////////////////////////////////////////////////
Predicate *PartialOrderPlan::selectSubgoal()
{
	Predicate *pRes;
	if(this->omUnfulfilled.size()>0)
	{
		//Looks weird, but it gets the first field(index) of the first element (the begin iterator)
		//in the Map
		pRes= omUnfulfilled.begin()->first;
	}else
		pRes=NULL;

	return pRes;
}

//////////////////////////////////////////////////////////////////////
// Returns the operator that has the referred predicate as a 
//precondition
//////////////////////////////////////////////////////////////////////
Operator * PartialOrderPlan::getOperatorFromGoal(Predicate *p)
{
	return omUnfulfilled[p];
}

//////////////////////////////////////////////////////////////////////
// Chooses an operator to fulfull the proposition pCause, which is
//a precondition to the Operator oCause.
// The selected operator is first searched for among the actions 
//already present in the plan, and then among the uninstantiated 
//operators.
//////////////////////////////////////////////////////////////////////
bool PartialOrderPlan::chooseOperator(Predicate *pCause, Operator *oCause, OperatorVector ovOperators)
{
	Operator *oNew;

	bool bOperatorFound=false;
	bool bNewOperator=false;

	PRINTL("Resolving sub-goal: " << pCause->toString())

	//First, try to find a step within the plan that may satisty the goal
	for(OperatorVector::iterator i=ovSteps.begin(); (!bOperatorFound && i!=ovSteps.end()); i++)
	{
		oNew=(*i);
		PredicateVector pvEffects=oNew->getEffects();

		//For every effect in the current operator, try to unify it with the predicate we are
		//trying to satisfy
		for(PredicateVector::iterator j=pvEffects.begin(); (!bOperatorFound && j!=pvEffects.end()); j++)
		{
			Predicate *p=(*j);
			//If we can unify the causing predicate with an effect from the operator then
			//we have found ourselves a satisfying plan step
			if((pCause->isNegative()==p->isNegative()) && unification->unifyPredicates(pCause, p))
			{
				PRINTL("Resolved "<< pCause->toString() <<" through: " << p->toString() << endl)
				bOperatorFound=true;
				bNewOperator=false;
			}
		}
	}

	//If we have not found an operator already in the plan to satisfy this predicate, then
	//we move on to check the possible operators in the domain.
	for(OperatorVector::iterator i2=ovOperators.begin(); (!bOperatorFound && i2!=ovOperators.end()); i2++)
	{
		oNew=new Operator(*i2);
		//PRINTL(o->toString())
		PredicateVector pvEffects=oNew->getEffects();

		//Same thing here, we should check every effect in the operator to see whether this operator
		//can be used to fulfill the predicate
		for(PredicateVector::iterator j=pvEffects.begin(); (!bOperatorFound && j!=pvEffects.end()); j++)
		{
			Predicate *p=(*j);
			if((pCause->isNegative()==p->isNegative()) && unification->unifyPredicates(pCause, p))
			{
				PRINTL("Resolved "<< pCause->toString() <<" through: " << p->toString() << endl)
				bOperatorFound=true;
				bNewOperator=true;
			}
		}
		
		if(!bOperatorFound)
		{
			//PRINTL(o->toString())
			delete oNew;
			oNew=NULL;
		}
	}

	if(bOperatorFound)
	{
		PRINTL("Choosen operator "<< oNew->toString() << endl)
		//When an operator to satisfy the current goal has been
		//found, we must order it in relation to the operator
		//containing the proposition we are trying to satisfy
		//and set that we have fulfilled the proposition by adding
		//a causal link between it and the operator found
		cllCauses.addCausalLink(oNew, pCause);
		ollOrder.addOrderLink(oNew, oCause);
		
		if(bNewOperator)
		{
			//If we have created a new operator in the plan then
			//we must establish an order between it and the rest of the
			//plan, and also insert it into nthe steps already chosen by 
			//the planner
			PRINTL("Operator " << oNew->getName() << " added.")
			PRINTL("Plan size=" << ovSteps.size())
			this->ovSteps.push_back(oNew);
			PRINTL("Plan size=" << ovSteps.size())
			ollOrder.addOrderLink(oNew, oGoal);
			ollOrder.addOrderLink(oStart, oNew);
		}
	}

	return bOperatorFound;
}

//////////////////////////////////////////////////////////////////////
// Tries to resolve any threats that may have been inserted into the
//plan.
//////////////////////////////////////////////////////////////////////
bool PartialOrderPlan::resolveThreats()
{
	bool bRes = true;
	for(OperatorVector::iterator i=ovSteps.begin(); i!=ovSteps.end(); i++)
	{
		Operator *o=*i;
		for(OperatorVector::iterator j=ovSteps.begin(); j!=ovSteps.end(); j++)
		{
			Operator *oThreat=*j;
			if(oThreat==o)
				continue;

			PredicateVector pv=oThreat->getEffects();

			//Try to find a threatening predicate
			for(PredicateVector::iterator k=pv.begin(); k!=pv.end(); k++)
			{
				//A threat was detected
				if(o->threatened(*k))
				{//Then deal with it
					//Either promote the step, or demote it
					PRINTL("Threat detected!!")
					//If we have decided to promote the step then we should add
					//the order link below
					ollOrder.addOrderLink(oThreat, o);
					//If we have decided to demote the step then we should add
					//the order link below
					//ollOrder.addOrderLink(o, oThreat);
				}
			}

		}
	}

	return bRes;
}

PartialOrderPlan &PartialOrderPlan::operator =(PartialOrderPlan &popRight)
{
	if(this != &popRight)
	{
		this->unification=popRight.unification;

		this->ovSteps=popRight.ovSteps;
		this->oStart=popRight.oStart;
		this->oGoal=popRight.oGoal;
		this->cllCauses=popRight.cllCauses;
		this->ollOrder=popRight.ollOrder;
		this->omUnfulfilled=popRight.omUnfulfilled;
	}

	return *this;
}

OperatorVector PartialOrderPlan::toVector()
{
	this->sortSteps();

	return ovSteps;
}

void PartialOrderPlan::sortSteps()
{
	//sort(ovSteps.begin(), ovSteps.end(), ollOrder.before);

	for(int i=0; i< ovSteps.size(); i++)
	{
		for(int j=i+1; j<ovSteps.size(); j++)
		{
			if(ollOrder.before(ovSteps[j], ovSteps[i]))
			{
				Operator *oTemp=ovSteps[j];
				ovSteps[j]=ovSteps[i];
				ovSteps[i]=oTemp;
			}
		}
	}
}

string PartialOrderPlan::toString()
{
	stringstream sRes;

	sRes << "Plan size=" << ovSteps.size();

	for(OperatorVector::iterator i=ovSteps.begin(); i!= ovSteps.end(); i++)
	{
		Operator *o=*i;
		sRes << o->toHeaderString() << "\n";
	}

	sRes << ollOrder.toString();

	return sRes.str();
}
