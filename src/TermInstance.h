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
// TermInstance.h: interface for the TermInstance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERMINSTANCE_H__55EDF537_C7F5_4769_9BBB_D5A45AE4C3BA__INCLUDED_)
#define AFX_TERMINSTANCE_H__55EDF537_C7F5_4769_9BBB_D5A45AE4C3BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <vector>
using std::string;

#include "Term.h"

class TermInstance
{
protected:
	string sName;
public:
	TermInstance();
	TermInstance(string sName);
	virtual ~TermInstance();

	bool operator==(TermInstance &tRight);
	TermInstance & operator=(TermInstance &tRight);

	string getKey();
	string toString();

	static string getKey(Term *t);
};

typedef vector<TermInstance *> TermInstanceVector;

#endif // !defined(AFX_TERMINSTANCE_H__55EDF537_C7F5_4769_9BBB_D5A45AE4C3BA__INCLUDED_)
