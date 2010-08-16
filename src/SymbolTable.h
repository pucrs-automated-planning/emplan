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
// SymbolTable.h: interface for the SymbolTable class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;
#include <map>
using std::map;
using std::less;

#include "TermSignature.h"
#include "PredicateSignature.h"
#include "OperatorSignature.h"
#include "Debug.h"

typedef map<string, TermSignature *, less<string> > TermSignatureMap;
typedef map<string, PredicateSignature *, less<string> > PredicateSignatureMap;
typedef map<string, OperatorSignature *, less<string> > OperatorSignatureMap;

class SymbolTable  
{
protected:
	TermSignatureMap tsmTerms;
	PredicateSignatureMap psmPredicates;
	OperatorSignatureMap osmOperators;
public:
	void registerOperator(Operator *o);
	void registerPredicate(Predicate *p);
	void registerTerm(Term *t);
	string toString();
	SymbolTable();
	virtual ~SymbolTable();

	TermSignatureMap getTermSignatures();
	PredicateSignatureMap getPredicateSignatures();
	OperatorSignatureMap getOperatorSignatures();
};

#endif // !defined(AFX_SYMBOLTABLE_H__86B0B0B8_75C8_44BB_8D5A_9C2B734F0742__INCLUDED_)
