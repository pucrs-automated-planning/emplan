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
// PredicateFactory.cpp: implementation of the PredicateFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "PredicateFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PredicateFactory::PredicateFactory()
{

}

PredicateFactory::~PredicateFactory()
{

}

Predicate * PredicateFactory::newPredicate(const string &s, bool bNot)
{
	TermVector dnvTerms;
	Term *dn=new Term(s, dnvTerms);
	Predicate *p=new Predicate(dn, bNot);

	return p;
}

Predicate * PredicateFactory::newPredicate(const string &s, TermVector *dnvTerms, bool bNot)
{
	TermVector dnv;
	if(dnvTerms!=NULL)
	{
		dnv=*dnvTerms;
		delete dnvTerms;
	}

	Term *dn=new Term(s, dnv);
	Predicate *p=new Predicate(dn, bNot);

	return p;
}

bool PredicateFactory::isFullyInstantiated(PredicateVector *pvPredicates)
{
	if(pvPredicates==NULL)
		return true;

	for(PredicateVector::iterator i= pvPredicates->begin(); i!=pvPredicates->end(); i++)
	{
		Predicate *p=*i;
		TermVector tv=p->getTerms();
		for(TermVector::iterator j=tv.begin(); j!=tv.end(); j++)
		{
			Term *t=*j;
			if(t->isVariable() && (t->getBinding() == t))
				return false;
		}
	}

	return true;
}
