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
/****************************************************************************
*                         A C A D E M I C   C O P Y
* 
* This file was produced by an ACADEMIC COPY of Parser Generator. It is for
* use in non-commercial software only. An ACADEMIC COPY of Parser Generator
* can only be used by a student, or a member of an academic community. If
* however you want to use Parser Generator for commercial purposes then you
* will need to purchase a license. For more information see the online help or
* go to the Bumble-Bee Software homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* OperatorParser.h
* C++ header file generated from OperatorParser.y.
* 
* Date: 12/27/03
* Time: 19:58:52
* 
* AYACC Version: 2.05
****************************************************************************/

#ifndef _OPERATORPARSER_H
#define _OPERATORPARSER_H

#include <yycpars.h>

#line 23 ".\\OperatorParser.y"

#include"Debug.h"
#include "SymbolTable.h"

#include "Operator.h"
#include "Predicate.h"
#include "Term.h"

#include "OperatorFactory.h"
#include "PredicateFactory.h"
#include "TermFactory.h"

#include "yystype.h"

#line 47 "OperatorParser.h"
/////////////////////////////////////////////////////////////////////////////
// OperatorParser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR OperatorParser : public _YL yyfparser {
public:
	OperatorParser();
	virtual ~OperatorParser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 42 ".\\OperatorParser.y"

	// place any extra class members here
		// place any extra class members here
		virtual void yysyntaxerror();
	protected:
		SymbolTable *yyst;
	
		PredicateVector *pvStart;
		PredicateVector *pvGoal;
		PredicateVector *pvPredicates;
		
		OperatorVector *ovOperators;
	public:
		PredicateVector *getStart();
		PredicateVector *getGoal();
		PredicateVector *getPredicates();
		OperatorVector *getOperators();
		static const string version;
		
		bool setSymbolTable(SymbolTable *yyst);

#line 102 "OperatorParser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME OperatorParser
#endif

#line 90 ".\\OperatorParser.y"

#ifndef YYSTYPE
//#define YYSTYPE int
#define YYSTYPE yystype
#endif

#line 116 "OperatorParser.h"
#define OPERATOR 257
#define PRECONDS 258
#define EFFECTS 259
#define START 260
#define GOAL 261
#define STRING 262
#define NUMBER 263
#define IDENTIFIER 264
#define NOT 265
#endif
