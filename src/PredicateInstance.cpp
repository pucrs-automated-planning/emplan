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
// PredicateInstance.cpp: implementation of the PredicateInstance class.
//
//////////////////////////////////////////////////////////////////////

#include "PredicateInstance.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PredicateInstance::PredicateInstance()
{

}

PredicateInstance::PredicateInstance(string sName, TermInstanceVector &tivTerms, bool bNot)
{
	this->sName=sName;
	this->tivTerms=tivTerms;
	this->bNot=bNot;
	this->sPredicate=this->makePredicate();
	if(bNot)
		this->sKey="-"+this->sPredicate;
	else
		this->sKey=this->sPredicate;
}

PredicateInstance::~PredicateInstance()
{

}

string PredicateInstance::makePredicate()
{
	string sRes;

	sRes+=sName;
	sRes+="(";
	for(TermInstanceVector::iterator i=tivTerms.begin(); i!=tivTerms.end(); i++)
	{
		if(i!=tivTerms.begin())
			sRes+=",";
		TermInstance *ti=*i;
		sRes+=ti->getKey();
	}
	sRes+=")";

	return sRes;
}

bool PredicateInstance::operator ==(PredicateInstance &piRight)
{
	if(this!=&piRight)
	{
		return this->sKey==piRight.sKey;
	}else
		return true;
}

PredicateInstance &PredicateInstance::operator=(PredicateInstance &piRight)
{
	if(this!=&piRight)
	{
		this->sName=piRight.sName;
		this->sKey=piRight.sKey;
		this->tivTerms=piRight.tivTerms;
	}
	return *this;
}

bool PredicateInstance::isMutex(PredicateInstance *pi)
{
	return (pi->sPredicate==this->sPredicate && this->bNot!=pi->bNot);
}

string PredicateInstance::getKey()
{
	return sKey;
}

string PredicateInstance::toString()
{
	return sKey;
}

string PredicateInstance::getKey(Predicate *p)
{
	string sRes;
	
	if(p!=NULL)
	{
		if(p->isNegative())
			sRes="-";

		sRes+=p->getName();
	
		sRes+="(";

		TermVector tv=p->getTerms();
		
		for(TermVector::iterator i=tv.begin(); i!=tv.end(); i++)
		{
			if(i!=tv.begin())
				sRes+=",";
			Term *t=*i;
			sRes+=TermInstance::getKey(t);
		}

		sRes+=")";
	}

	return sRes;
}
