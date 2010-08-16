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
* OperatorLexer.h
* C++ header file generated from OperatorLexer.l.
* 
* Date: 12/27/03
* Time: 19:58:52
* 
* ALex Version: 2.05
****************************************************************************/

#ifndef _OPERATORLEXER_H
#define _OPERATORLEXER_H

#include <yyclex.h>

#line 14 ".\\OperatorLexer.l"

#include"Debug.h"
#include "SymbolTable.h"

#line 37 "OperatorLexer.h"
/////////////////////////////////////////////////////////////////////////////
// OperatorLexer

#ifndef YYEXPLEXER
#define YYEXPLEXER
#endif

class YYEXPLEXER YYFAR OperatorLexer : public _YL yyflexer {
public:
	OperatorLexer();
	virtual ~OperatorLexer();

	// backards compatibility with lex
#ifdef input
	virtual int yyinput();
#endif
#ifdef output
	virtual void yyoutput(int ch);
#endif
#ifdef unput
	virtual void yyunput(int ch);
#endif

protected:
	void yytables();
	virtual int yyaction(int action);

public:
#line 22 ".\\OperatorLexer.l"

	// place any extra class members here
	public:
		//Override the default output function
		void yyoutput(int ch);
		SymbolTable *yyst;
		
		static const string version;
		
		SymbolTable *getSymbolTable();

#line 78 "OperatorLexer.h"
};

#ifndef YYLEXERNAME
#define YYLEXERNAME OperatorLexer
#endif

#define COMMENT 2
#define LINECOMMENT 4
#ifndef INITIAL
#define INITIAL 0
#endif

#endif
