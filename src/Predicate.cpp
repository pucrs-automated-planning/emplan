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
// Predicate.cpp: implementation of the Predicate class.
//
//////////////////////////////////////////////////////////////////////

#include "Predicate.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Predicate::Predicate()
{
	this->dnPredicate=NULL;
	this->dnmVariables=NULL;
}

Predicate::~Predicate()
{
	delete dnPredicate;
}

Predicate::Predicate(Term *dnPredicate, bool bNot)
{
	this->dnPredicate=dnPredicate;
	this->dnmVariables=NULL;
	this->bNot=bNot;
}

Predicate::Predicate(Term *dnPredicate, TermMap *dnmVariables, bool bNot)
{
	this->dnPredicate=dnPredicate;
	this->dnmVariables=dnmVariables;
	this->bNot=bNot;
}


const Predicate &Predicate::operator =(const Predicate &pRight)
{
	if(this != &pRight)
	{
		this->dnPredicate=pRight.dnPredicate;
		this->dnmVariables=dnmVariables;
	}

	return *this;
}

const bool Predicate::operator ==(const Predicate &pRight)
{
	bool bRes=true;
	if(this != &pRight)
	{
		bRes &= (this->dnPredicate == pRight.dnPredicate);
	}else
		bRes=true;
	return bRes;
}

void Predicate::flip()
{
	this->bNot=!bNot;
}

const TermVector Predicate::getTerms()
{
	return this->dnPredicate->getTerms();
}

string Predicate::getName()
{
	return this->dnPredicate->getName();
}

int Predicate::getArity()
{
	return this->dnPredicate->getArity();
}

Term * Predicate::getTerm()
{
	return this->dnPredicate;
}

bool Predicate::isNegative()
{
	return this->bNot;
}

TermMap *Predicate::getVariables()
{
	return this->dnmVariables;
}

Predicate::Predicate(Predicate *p, TermMap *dnmVariables)
{
	this->bNot=p->bNot;
	this->dnmVariables=dnmVariables;
	this->dnPredicate=new Term(p->getTerm(), dnmVariables);
}

string Predicate::toString()
{
	string sRes="[(Predicate)";

	sRes+=this->dnPredicate->toString();

	sRes+="]";

	return sRes;
}


void Predicate::unbind()
{
	TermVector tvTerms=dnPredicate->getTerms();
	for(TermVector::iterator i=tvTerms.begin(); i!=tvTerms.end(); i++)
	{
		(*i)->unbind();
	}
}
