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
// OrderLinkList.cpp: implementation of the OrderLinkList class.
//
//////////////////////////////////////////////////////////////////////

#include "OrderLinkList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OrderLinkList::OrderLinkList()
{

}

OrderLinkList::~OrderLinkList()
{

}

void OrderLinkList::addOrderLink(Operator *oBefore, Operator *oAfter)
{
	OrderLink ol(oBefore, oAfter);
	
	olmOrder.insert(pair<Operator *, OrderLink> (oBefore, ol));

}

bool OrderLinkList::before(Operator *oBefore, Operator *oAfter)
{
	for(OrderLinkMap::iterator i=olmOrder.find(oBefore);i!=olmOrder.end();i++)
	{
		if(i->second.before(oBefore, oAfter))
			return true;
	}

	return false;
}

string OrderLinkList::toString()
{
	ostringstream oRes;

	oRes << "Order Links\n";

	for(OrderLinkMap::iterator i=olmOrder.begin(); i!=olmOrder.end(); i++)
	{
		if(i!=olmOrder.begin())
			oRes << "\n";
		oRes << i->second.toString();
	}

	return oRes.str();
}
