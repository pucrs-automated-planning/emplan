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
// OperatorParserProxy.h: interface for the OperatorParserProxy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORPARSERPROXY_H__439AC185_545F_4213_8F3D_58BBB00D3F70__INCLUDED_)
#define AFX_OPERATORPARSERPROXY_H__439AC185_545F_4213_8F3D_58BBB00D3F70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Debug.h"
#include "Consoleout.h"

#include <iostream>
using std::cin;
using std::cerr;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include "OperatorParser.h"
#include "OperatorLexer.h"

//The OperatorParserProxy is a frontend to whatever parser you may be trying to use
//to parse the input language
class OperatorParserProxy  
{
protected:
	bool bStartUp;
	int n;
	OperatorLexer lexer;
	OperatorParser parser;
public:
	OperatorParserProxy();
	virtual ~OperatorParserProxy();

	//Parses the file given as input and returns if it has been sucessfull
	bool parse(string sFilename);

	//Returns 
	PredicateVector getStart();
	PredicateVector getGoal();
	OperatorVector getOperators();
	SymbolTable *getSymbolTable();

	string toString();
};

#endif // !defined(AFX_OPERATORPARSERPROXY_H__439AC185_545F_4213_8F3D_58BBB00D3F70__INCLUDED_)
