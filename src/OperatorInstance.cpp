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
// OperatorInstance.cpp: implementation of the OperatorInstance class.
//
//////////////////////////////////////////////////////////////////////

#include "OperatorInstance.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OperatorInstance::OperatorInstance()
{

}

OperatorInstance::OperatorInstance(string sName, 
					TermInstanceVector &tivParameters, 
					PredicateInstanceVector &pivPreconditions, 
					PredicateInstanceVector &pivEffects,
					bool bNoop)
{
	this->bNoop=bNoop;
	this->sName=sName;
	this->tivParameters=tivParameters;
	this->pivPreconditions=pivPreconditions;
	this->pivEffects=pivEffects;
	
	this->sKey=makeKey();
}

string OperatorInstance::makeKey()
{
	string sRes=this->sName;
	if(tivParameters.size() != 0)//Added at june 6th 2003
		sRes+="(";
	for(TermInstanceVector::iterator i=tivParameters.begin(); i!=tivParameters.end(); i++)
	{
		if(i!=tivParameters.begin())
			sRes+=",";
		TermInstance *ti=*i;

		sRes+=ti->getKey();
	}
	if(tivParameters.size() != 0)//Added at june 6th 2003
		sRes+=")";

	return sRes;
}

OperatorInstance::~OperatorInstance()
{

}


bool OperatorInstance::operator==(OperatorInstance &oiRight)
{
	if(this!=&oiRight)
	{
		return this->sKey==oiRight.sKey;
	}else
		return true;
}

OperatorInstance & OperatorInstance::operator=(OperatorInstance &oiRight)
{
	if(this!=&oiRight)
	{
		this->bNoop=oiRight.bNoop;
		this->sName=oiRight.sName;
		this->sKey=oiRight.sKey;
		this->tivParameters=oiRight.tivParameters;
		this->pivPreconditions=oiRight.pivPreconditions;
		this->pivEffects=oiRight.pivEffects;
	}

	return *this;
}


//This predicate detects mutexes based on the definition of the
//operators, this mainly detects of competing needs mutexes,
//incosistant effects and interference
bool OperatorInstance::isMutex(OperatorInstance *oi)
{
	bool bRes=false;
	PredicateInstanceVector pivPre=oi->getPreconditions();
	PredicateInstanceVector pivEff=oi->getEffects();

	PredicateInstanceVector::iterator ip;
	PredicateInstanceVector::iterator ie;

	//Verify if any of this Operator's preconditions is mutex with any precondition or effect in the
	//target Operator
	for(PredicateInstanceVector::iterator i=pivPreconditions.begin(); (!bRes && i!=pivPreconditions.end()); i++)
	{
		PredicateInstance *pi=*i;

		for(ip=pivPre.begin(); !bRes && ip!=pivPre.end(); ip++)
		{
			PredicateInstance *piPre=*ip;
			bRes=pi->isMutex(piPre);
		}

		for(ie=pivEff.begin(); !bRes && ie!=pivEff.end(); ie++)
		{
			PredicateInstance *piEff=*ie;
			bRes=pi->isMutex(piEff);
		}
	}

	//Verify if any of this Operator's effetcs is mutex with any precondition or effect in the
	//target Operator
	for(PredicateInstanceVector::iterator i=pivEffects.begin(); (!bRes && i!=pivEffects.end()); i++)
	{
		PredicateInstance *pi=*i;

		for(ip=pivPre.begin(); !bRes && ip!=pivPre.end(); ip++)
		{
			PredicateInstance *piPre=*ip;
			bRes=pi->isMutex(piPre);
		}

		for(ie=pivEff.begin(); !bRes && ie!=pivEff.end(); ie++)
		{
			PredicateInstance *piEff=*ie;
			bRes=pi->isMutex(piEff);
		}
	}

	return bRes;
}

PredicateInstanceVector OperatorInstance::getPreconditions()
{
	return this->pivPreconditions;
}

PredicateInstanceVector OperatorInstance::getEffects()
{
	return this->pivEffects;
}

bool OperatorInstance::isNoop()
{
	return this->bNoop;
}

string OperatorInstance::getKey()
{
	return sKey;
}

bool OperatorInstance::fulfills(PredicateInstance *piEffect)
{
	for(PredicateInstanceVector::iterator i=pivEffects.begin(); i!=pivEffects.end(); i++)
	{
		if((*i)==piEffect)
			return true;
	}

	return false;
}

bool OperatorInstance::requires(PredicateInstance *piPrecondition)
{
	for(PredicateInstanceVector::iterator i=pivPreconditions.begin(); i!=pivPreconditions.end(); i++)
	{
		if((*i)==piPrecondition)
			return true;
	}

	return false;
}

bool OperatorInstance::requiresNothing()
{
	return (pivPreconditions.size()==0);
}

bool OperatorInstance::selfConsistent()
{
	for(PredicateInstanceVector::iterator i=pivPreconditions.begin(); i!=pivPreconditions.end(); i++)
	{
		for(PredicateInstanceVector::iterator j=i+1; j!=pivPreconditions.end(); j++)
		{
			if((*i)->isMutex(*j))
				return false;
		}
	}

	for(PredicateInstanceVector::iterator i=pivEffects.begin(); i!=pivEffects.end(); i++)
	{
		for(PredicateInstanceVector::iterator j=i+1; j!=pivEffects.end(); j++)
		{
			if((*i)->isMutex(*j))
				return false;
		}
	}

	return true;
}

string OperatorInstance::toString()
{
	string sRes=sName;
	
	if(tivParameters.size() != 0)//Added at june 6th 2003
		sRes+="(";
	for(TermInstanceVector::iterator i=tivParameters.begin(); i!=tivParameters.end(); i++)
	{
		if(i!=tivParameters.begin())
			sRes+=",";
		TermInstance *ti=*i;

		sRes+=ti->getKey();
	}
	if(tivParameters.size() != 0)//Added at june 6th 2003
		sRes+=")";

	sRes+="\n\tpreconditions:";
	for(PredicateInstanceVector::iterator j=pivPreconditions.begin(); j!=pivPreconditions.end(); j++)
	{
		sRes+="\n\t\t";
		PredicateInstance *pi=*j;
		sRes+=pi->toString();
	}

	sRes+="\n\teffects:";
	for(PredicateInstanceVector::iterator j=pivEffects.begin(); j!=pivEffects.end(); j++)
	{
		sRes+="\n\t\t";
		PredicateInstance *pi=*j;
		sRes+=pi->toString();
	}

	return sRes;
}

string OperatorInstance::getKey(Operator *o)
{
	string sRes;

	if(o!=NULL)
	{
		sRes=o->getName();
		TermVector tv=o->getParameters();
		if(tv.size() != 0)//Added at june 6th 2003
			sRes+="(";
		for(TermVector::iterator i=tv.begin(); i!=tv.end(); i++)
		{
			if(i!=tv.begin())
				sRes+=",";
			Term *t=*i;
			sRes+=TermInstance::getKey(t);
		}
		if(tv.size() != 0)//Added at june 6th 2003
			sRes+=")";
	}

	return sRes;
}
