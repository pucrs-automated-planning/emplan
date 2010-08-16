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
 * CausalLinkList.cpp: implementation of the CausalLinkList class.
 *
 *  Created on: Aug 15, 2002
 *      Author: meneguzzi
 */

#include "CausalLinkList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CausalLinkList::CausalLinkList()
{

}

CausalLinkList::~CausalLinkList()
{

}

void CausalLinkList::addCausalLink(Operator *oFulfills, Predicate *pCauses)
{
	if(!this->isFulfilled(pCauses))
	{
		CausalLink cl(oFulfills, pCauses);
		clmCauses[pCauses]=cl;
	}
}

bool CausalLinkList::isFulfilled(Predicate *p)
{
	if(clmCauses.find(p) != clmCauses.end())
		return true;
	else
		return false;
}

CausalLink &CausalLinkList::operator[](Predicate *p)
{
	return clmCauses[p]; 
}

string CausalLinkList::toString()
{
	ostringstream oRes;

	oRes << "Causal Links\n";

	for(CausalLinkMap::iterator i=clmCauses.begin(); i!=clmCauses.end(); i++)
	{
		if(i!=clmCauses.begin())
			oRes << " ** ";
		oRes << i->second.toString();
	}

	return oRes.str();
}
