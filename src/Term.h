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
// Term.h: interface for the Term class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Term_H__3EAEC4EE_B806_402B_A624_ACD810143A38__INCLUDED_)
#define AFX_Term_H__3EAEC4EE_B806_402B_A624_ACD810143A38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::less;

#include <string>
using std::string;

#include "Debug.h"

class Term  
{
	typedef map<string, Term *, less<string> > TermMap;
	typedef vector<Term *> TermVector;
private:
	TermMap *dnmVariables;//To store references to variables
protected:
	Term * getVariable(Term *dnVar);
	string sName;
	bool bVariable;//To denote that the current node is a variable
	bool bFunction;//To denote that the current node is a function i.e. dnvTerms!=NULL
	Term *dnBinding;//Pointer to bound term if this is a variable
	TermVector dnvTerms;//The child terms if this is a function
public:
	
	Term(const string &sName, bool bVar=false);
	Term(const string &sName, TermVector dnvTerms);
	Term(Term *dn, TermMap *dnmVariables);
	string getName();
	bool isFunction();
	bool isVariable();
	bool bind(Term *dn);
	bool occur(Term *dn);
	virtual ~Term();
	int getArity();
	Term * getBinding();
	TermVector getTerms();

	bool operator ==(const Term &dn);
	void unbind();

	string toString();
};

typedef map<string, Term *, less<string> > TermMap;
typedef vector<Term *> TermVector;

#endif // !defined(AFX_Term_H__3EAEC4EE_B806_402B_A624_ACD810143A38__INCLUDED_)
