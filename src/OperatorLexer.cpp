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
* OperatorLexer.cpp
* C++ source file generated from OperatorLexer.l.
* 
* Date: 12/27/03
* Time: 19:58:52
* 
* ALex Version: 2.05
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\OperatorLexer.l"

/****************************************************************************
OperatorLexer.l
ParserWizard generated Lex file.

Date: domingo, 9 de fevereiro de 2003
****************************************************************************/

#include "OperatorParser.h"

#line 48 "OperatorLexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include "OperatorLexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 35 ".\\OperatorLexer.l"

	// place any extra initialisation code here
	yyst=new SymbolTable();

#line 73 "OperatorLexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 41 ".OperatorLexer.l"

	// place any extra cleanup code here
	delete yyst;

#line 86 "OperatorLexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 62 ".\\OperatorLexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 157 "OperatorLexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 69 ".\\OperatorLexer.l"
PRINT(" TK_OPERATOR ") return OPERATOR;
#line 164 "OperatorLexer.cpp"
		}
		break;
	case 2:
		{
#line 70 ".\\OperatorLexer.l"
PRINT(" TK_PRECONDS ") return PRECONDS;
#line 171 "OperatorLexer.cpp"
		}
		break;
	case 3:
		{
#line 71 ".\\OperatorLexer.l"
PRINT(" TK_EFFECTS ") return EFFECTS;
#line 178 "OperatorLexer.cpp"
		}
		break;
	case 4:
		{
#line 72 ".\\OperatorLexer.l"
PRINT(" TK_START ") return START;
#line 185 "OperatorLexer.cpp"
		}
		break;
	case 5:
		{
#line 73 ".\\OperatorLexer.l"
PRINT(" TK_GOAL ") return GOAL;
#line 192 "OperatorLexer.cpp"
		}
		break;
	case 6:
		{
#line 74 ".\\OperatorLexer.l"
PRINT(" TK_NOT ") return NOT;
#line 199 "OperatorLexer.cpp"
		}
		break;
	case 7:
		{
#line 76 ".\\OperatorLexer.l"
PRINT(" TK_IDENTIFIER ") 
												yylval.symbol=yytext;
												return IDENTIFIER;
#line 208 "OperatorLexer.cpp"
		}
		break;
	case 8:
		{
#line 80 ".\\OperatorLexer.l"
PRINT(" TK_NUMBER ")
												yylval.symbol=yytext;
												return NUMBER;
#line 217 "OperatorLexer.cpp"
		}
		break;
	case 9:
		{
#line 83 ".\\OperatorLexer.l"
PRINT(" TK_STRING")
												yylval.symbol=yytext;
												return STRING;
#line 226 "OperatorLexer.cpp"
		}
		break;
	case 10:
		{
#line 86 ".\\OperatorLexer.l"
PRINT(" TK_STRING")
												yylval.symbol=yytext;
												return STRING;
#line 235 "OperatorLexer.cpp"
		}
		break;
	case 11:
		{
#line 89 ".\\OperatorLexer.l"
PRINT(" TK_NUMBER ")
												yylval.symbol=yytext;
												return NUMBER;
#line 244 "OperatorLexer.cpp"
		}
		break;
	case 12:
		{
#line 92 ".\\OperatorLexer.l"
PRINT(" TK_NUMBER ")
												yylval.symbol=yytext;
												return NUMBER;
#line 253 "OperatorLexer.cpp"
		}
		break;
	case 13:
		{
#line 96 ".\\OperatorLexer.l"
;
#line 260 "OperatorLexer.cpp"
		}
		break;
	case 14:
		{
#line 98 ".\\OperatorLexer.l"
BEGIN(COMMENT);
#line 267 "OperatorLexer.cpp"
		}
		break;
	case 15:
		{
#line 99 ".\\OperatorLexer.l"
BEGIN(0);
#line 274 "OperatorLexer.cpp"
		}
		break;
	case 16:
		{
#line 100 ".\\OperatorLexer.l"
;
#line 281 "OperatorLexer.cpp"
		}
		break;
	case 17:
		{
#line 101 ".\\OperatorLexer.l"
;
#line 288 "OperatorLexer.cpp"
		}
		break;
	case 18:
		{
#line 102 ".\\OperatorLexer.l"
;
#line 295 "OperatorLexer.cpp"
		}
		break;
	case 19:
		{
#line 104 ".\\OperatorLexer.l"
BEGIN(LINECOMMENT);
#line 302 "OperatorLexer.cpp"
		}
		break;
	case 20:
		{
#line 105 ".\\OperatorLexer.l"
BEGIN(0);
#line 309 "OperatorLexer.cpp"
		}
		break;
	case 21:
		{
#line 107 ".\\OperatorLexer.l"
PRINT(yytext[0]) return yytext[0];
#line 316 "OperatorLexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 502;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 8, 1 },
		{ 0, 1 },
		{ 0, 53 },
		{ 0, 51 },
		{ 0, 11 },
		{ 8, 8 },
		{ 63, 63 },
		{ 63, 63 },
		{ 63, 63 },
		{ 63, 63 },
		{ 63, 63 },
		{ 63, 63 },
		{ 63, 63 },
		{ 63, 63 },
		{ 63, 63 },
		{ 63, 63 },
		{ 29, 12 },
		{ 77, 3 },
		{ 0, 76 },
		{ 22, 15 },
		{ 56, 44 },
		{ 30, 12 },
		{ 56, 44 },
		{ 8, 1 },
		{ 25, 15 },
		{ 9, 1 },
		{ 0, 53 },
		{ 23, 51 },
		{ 8, 8 },
		{ 35, 18 },
		{ 10, 1 },
		{ 26, 53 },
		{ 55, 43 },
		{ 36, 19 },
		{ 55, 43 },
		{ 37, 20 },
		{ 0, 11 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 78, 3 },
		{ 0, 76 },
		{ 57, 45 },
		{ 58, 46 },
		{ 59, 48 },
		{ 60, 49 },
		{ 61, 50 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 45, 33 },
		{ 46, 34 },
		{ 27, 53 },
		{ 24, 51 },
		{ 14, 1 },
		{ 47, 35 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 16, 1 },
		{ 14, 1 },
		{ 17, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 21, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 0, 52 },
		{ 31, 31 },
		{ 31, 31 },
		{ 31, 31 },
		{ 31, 31 },
		{ 31, 31 },
		{ 31, 31 },
		{ 31, 31 },
		{ 31, 31 },
		{ 31, 31 },
		{ 31, 31 },
		{ 48, 36 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 44, 31 },
		{ 64, 57 },
		{ 23, 52 },
		{ 65, 59 },
		{ 66, 60 },
		{ 67, 61 },
		{ 49, 37 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 50, 38 },
		{ 68, 64 },
		{ 69, 65 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 70, 66 },
		{ 71, 68 },
		{ 72, 69 },
		{ 73, 70 },
		{ 74, 72 },
		{ 75, 73 },
		{ 44, 31 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 54, 42 },
		{ 38, 21 },
		{ 31, 13 },
		{ 0, 54 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 33, 16 },
		{ 34, 17 },
		{ 24, 52 },
		{ 79, 78 },
		{ 80, 5 },
		{ 0, 0 },
		{ 0, 0 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 52, 52 },
		{ 0, 54 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 26, 54 },
		{ 51, 39 },
		{ 51, 39 },
		{ 51, 39 },
		{ 51, 39 },
		{ 51, 39 },
		{ 51, 39 },
		{ 51, 39 },
		{ 51, 39 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 22, 24 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 24 },
		{ 0, 0 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 0, 0 },
		{ 39, 24 },
		{ 39, 24 },
		{ 39, 24 },
		{ 39, 24 },
		{ 39, 24 },
		{ 39, 24 },
		{ 39, 24 },
		{ 39, 24 },
		{ 0, 0 },
		{ 0, 0 },
		{ 32, 32 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 24 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 32, 32 },
		{ 27, 54 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 41, 27 },
		{ 41, 27 },
		{ 41, 27 },
		{ 41, 27 },
		{ 41, 27 },
		{ 41, 27 },
		{ 41, 27 },
		{ 41, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 32, 32 },
		{ 0, 0 },
		{ 22, 24 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 24 },
		{ 22, 24 },
		{ 32, 32 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 24 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 24 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 24 },
		{ 0, 0 },
		{ 22, 24 },
		{ 0, 0 },
		{ 22, 24 },
		{ 0, 0 },
		{ 40, 24 },
		{ 0, 0 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 25, 27 },
		{ 25, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 25, 27 },
		{ 0, 0 },
		{ 42, 27 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 14, 75 },
		{ 0, 0 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 14, 75 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 28, 28 },
		{ 28, 28 },
		{ 28, 28 },
		{ 28, 28 },
		{ 28, 28 },
		{ 28, 28 },
		{ 28, 28 },
		{ 28, 28 },
		{ 28, 28 },
		{ 28, 28 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 0, 0 },
		{ 43, 28 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 52, 40 },
		{ 53, 41 },
		{ 53, 41 },
		{ 53, 41 },
		{ 53, 41 },
		{ 53, 41 },
		{ 53, 41 },
		{ 53, 41 },
		{ 53, 41 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 43, 28 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -7, -8, 0 },
		{ 1, 0, 0 },
		{ -76, 8, 0 },
		{ 3, 0, 0 },
		{ 0, 189, 0 },
		{ 5, 0, 0 },
		{ 0, 0, 21 },
		{ 0, -3, 13 },
		{ 51, 0, 21 },
		{ 53, 0, 21 },
		{ 28, -64, 21 },
		{ 0, -25, 21 },
		{ 32, 137, 8 },
		{ 75, 0, 7 },
		{ 75, -14, 7 },
		{ 75, 93, 7 },
		{ 75, 85, 7 },
		{ 75, -81, 7 },
		{ 75, -78, 7 },
		{ 75, -78, 7 },
		{ 75, 66, 7 },
		{ 51, 0, 0 },
		{ 0, 0, 9 },
		{ 0, 198, 0 },
		{ 53, 0, 0 },
		{ 53, 0, 10 },
		{ 0, 229, 0 },
		{ 0, 400, 12 },
		{ 0, 0, 14 },
		{ 0, 0, 19 },
		{ 0, 68, 11 },
		{ 0, 180, 8 },
		{ 75, -19, 7 },
		{ 75, -13, 7 },
		{ 75, -28, 7 },
		{ 75, 25, 7 },
		{ 75, 42, 7 },
		{ 75, 53, 7 },
		{ 51, 166, 0 },
		{ 0, 377, 0 },
		{ 53, 432, 0 },
		{ 0, 79, 0 },
		{ 0, -10, 0 },
		{ 0, -22, 0 },
		{ 75, -49, 7 },
		{ 75, -55, 7 },
		{ 75, 0, 6 },
		{ 75, -60, 7 },
		{ 75, -44, 7 },
		{ 75, -58, 7 },
		{ -22, -6, 0 },
		{ -22, 105, 0 },
		{ -25, -7, 0 },
		{ -25, 174, 0 },
		{ 62, 0, 0 },
		{ 63, 0, 0 },
		{ 75, 39, 7 },
		{ 75, 0, 5 },
		{ 75, 43, 7 },
		{ 75, 30, 7 },
		{ 75, 26, 7 },
		{ 0, 410, 12 },
		{ 0, -41, 11 },
		{ 75, 35, 7 },
		{ 75, 36, 7 },
		{ 75, 53, 7 },
		{ 75, 0, 4 },
		{ 75, 49, 7 },
		{ 75, 54, 7 },
		{ 75, 66, 7 },
		{ 75, 0, 3 },
		{ 75, 53, 7 },
		{ 75, 53, 7 },
		{ 75, 0, 1 },
		{ 0, 302, 2 },
		{ -76, 9, 16 },
		{ 0, 0, 17 },
		{ 0, 151, 18 },
		{ 0, 0, 15 },
		{ 0, 0, 20 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 109 ".\\OperatorLexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

const string YYLEXERNAME::version="Planner Lexer version 0.1b";

SymbolTable *YYLEXERNAME::getSymbolTable()
{
	return this->yyst;
}

//This overrides the default behaviour of printing unmatched characters to
//the screen, if by chance you want to see those characters, uncomment the
//output(ch) line;
void YYLEXERNAME::yyoutput(int ch)
{
    //output(ch);
}
