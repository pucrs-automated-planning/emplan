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
 * CausalLink.cpp: implementation of the CausalLink class.
 *
 *  Created on: Aug 15, 2002
 *      Author: meneguzzi
 */

#include "CausalLink.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CausalLink::CausalLink()
{
	this->oFulfills=NULL;
	this->pCauses=NULL;
}

CausalLink::CausalLink(Operator *oFulfills, Predicate *pCauses)
{
	assert(oFulfills != NULL && pCauses!=NULL);
	this->oFulfills=oFulfills;
	this->pCauses=pCauses;
}

CausalLink::~CausalLink()
{

}

bool CausalLink::fulfills(Operator *o)
{
	return (o==this->oFulfills);
}

bool CausalLink::fulfilled(Predicate *p)
{
	return (p==this->pCauses);
}

CausalLink &CausalLink::operator=(CausalLink &clRight)
{
	if(this != &clRight)
	{
		this->oFulfills=clRight.oFulfills;
		this->pCauses=clRight.pCauses;
	}

	assert(oFulfills != NULL && pCauses != NULL);

	return *this;
}

string CausalLink::toString()
{
	assert(oFulfills != NULL && pCauses!=NULL);
	string sRes = oFulfills->toString() + " causes " + pCauses->toString();

	return sRes;
}
