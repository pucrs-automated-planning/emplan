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
// GroundPlan.h: interface for the GroundPlan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GROUNDPLAN_H__551E02B8_7A70_44A4_9051_3DB31839865D__INCLUDED_)
#define AFX_GROUNDPLAN_H__551E02B8_7A70_44A4_9051_3DB31839865D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include "OperatorInstance.h"

//////////////////////////////////////////////////////////////////////
// Represents a plan comprised of ground terms
//////////////////////////////////////////////////////////////////////
class GroundPlan
{
public:
	GroundPlan();
	virtual ~GroundPlan();

	//Returns the plan as a vector of operator instances
	virtual OperatorInstanceVector toVector();

	virtual string toString(OperatorInstanceVector &oiv);
	//Prints a string representation of the plan
	virtual string toString();
};

#endif // !defined(AFX_GROUNDPLAN_H__551E02B8_7A70_44A4_9051_3DB31839865D__INCLUDED_)
