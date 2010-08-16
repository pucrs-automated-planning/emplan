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
// PredicateSignature.cpp: implementation of the PredicateSignature class.
//
//////////////////////////////////////////////////////////////////////

#include "PredicateSignature.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PredicateSignature::PredicateSignature()
{
	this->pSignature=NULL;
}

PredicateSignature::PredicateSignature(Predicate *p):Signature()
{
	this->pSignature=PredicateSignature::makeSignaturePredicate(p->getName(), p->getArity());
	this->sName=PredicateSignature::getSignature(pSignature);
}

PredicateSignature::~PredicateSignature()
{
	delete pSignature;
}

Predicate *PredicateSignature::getPredicate()
{
	return this->pSignature;
}

string PredicateSignature::toString()
{
	return this->sName;
}

string PredicateSignature::getSignature(Predicate *p)
{
	ostringstream out;
	out << p->getName();
	out << "/";
	out << p->getArity();

	return out.str();
}

PredicateSignature & PredicateSignature::operator=(PredicateSignature &pRight)
{
	if(this!=&pRight)
	{
		this->sName=pRight.sName;
		this->iId=pRight.iId;
		this->pSignature=pRight.pSignature;
	}

	return *this;
}

Predicate *PredicateSignature::makeSignaturePredicate(string sName, int iArity)
{
	TermVector tvTerms;
	tvTerms.resize(iArity);
	string sVarBase="A";

	for(int i=0; i<iArity; i++)
	{
		ostringstream out;
		out<<sVarBase<<i;
		
		//Create a variable
		Term *t=new Term(out.str(), true);
		tvTerms[i]=t;
	}

	Term *t=new Term(sName, tvTerms);
	Predicate *p=new Predicate(t);

	return p;
}
