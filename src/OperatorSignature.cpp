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
// OperatorSignature.cpp: implementation of the OperatorSignature class.
//
//////////////////////////////////////////////////////////////////////

#include "OperatorSignature.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OperatorSignature::OperatorSignature()
{
	this->oSignature=NULL;
}

OperatorSignature::OperatorSignature(Operator *o):Signature()
{
	this->oSignature=new Operator(o);
	this->sName=OperatorSignature::getSignature(oSignature);
}

OperatorSignature::~OperatorSignature()
{
	delete oSignature;
}

Operator *OperatorSignature::getOperator()
{
	return this->oSignature;
}

string OperatorSignature::toString()
{
	return this->sName;
}

OperatorSignature & OperatorSignature::operator=(OperatorSignature &oRight)
{
	if(this!=&oRight)
	{
		this->sName=oRight.sName;
		this->iId=oRight.iId;
		this->oSignature=oRight.oSignature;
	}

	return *this;
}

//This method exists so that the SymbolTable can grab the signature of an
//operator without the need for instantiating a new signature
string OperatorSignature::getSignature(Operator *o)
{
	ostringstream out;

	out << o->getName();

	out << "/";

	out << o->getArity();

	return out.str();
}
