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
// TermSignature.cpp: implementation of the TermSignature class.
//
//////////////////////////////////////////////////////////////////////

#include "TermSignature.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TermSignature::TermSignature()
{
	this->tSignature=NULL;
}

TermSignature::TermSignature(Term *t):Signature()
{
	assert(t!=NULL);
	this->sName=TermSignature::getSignature(t);
	this->tSignature=new Term(t->getName());
}

TermSignature::~TermSignature()
{

}

string TermSignature::toString()
{
	return this->sName;
}

Term *TermSignature::getTerm()
{
	return this->tSignature;
}

TermSignature & TermSignature::operator=(TermSignature &tRight)
{
	if(this!=&tRight)
	{
		this->sName=tRight.sName;
		this->iId=tRight.iId;
		this->tSignature=tRight.tSignature;
		assert(tSignature != NULL);
	}

	return *this;
}

string TermSignature::getSignature(Term *t)
{
	assert(t!=NULL);
	return t->getName();
}
