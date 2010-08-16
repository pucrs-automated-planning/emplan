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
// TermInstance.cpp: implementation of the TermInstance class.
//
//////////////////////////////////////////////////////////////////////

#include "TermInstance.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TermInstance::TermInstance()
{

}

TermInstance::TermInstance(string sName)
{
	this->sName=sName;
}

TermInstance::~TermInstance()
{

}

bool TermInstance::operator==(TermInstance &tRight)
{
	if(this!=&tRight)
	{
		return this->sName==tRight.sName;
	}else
		return true;
}

TermInstance & TermInstance::operator=(TermInstance &tRight)
{
	if(this!=&tRight)
	{
		this->sName=tRight.sName;
	}

	return *this;
}

string TermInstance::getKey()
{
	return sName;
}

string TermInstance::toString()
{
	return this->sName;
}


string TermInstance::getKey(Term *t)
{
	if(t!=NULL)
	{
		t=t->getBinding();
		return t->getName();
	}else
		return "";
}
