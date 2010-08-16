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
* OperatorParser.cpp
* C++ source file generated from OperatorParser.y.
* 
* Date: 12/27/03
* Time: 19:58:52
* 
* AYACC Version: 2.05
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\OperatorParser.y"

/****************************************************************************
OperatorParser.y
ParserWizard generated YACC file.

Date: domingo, 9 de fevereiro de 2003
****************************************************************************/

#include "OperatorLexer.h"

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;
using std::endl;


#line 56 "OperatorParser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include "OperatorParser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 65 ".OperatorParser.y"

	// place any extra initialisation code here
	this->pvStart=NULL;
	this->pvGoal=NULL;
	this->pvPredicates=NULL;
	this->ovOperators=NULL;

#line 84 "OperatorParser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 74 ".OperatorParser.y"

	// place any extra cleanup code here

#line 98 "OperatorParser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 127 ".OperatorParser.y"
REDUCE("Grammar 1")
#line 208 "OperatorParser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 128 ".OperatorParser.y"
ovOperators=yyattribute(1 - 1).ovOpers;
														REDUCE("Grammar 2")
#line 222 "OperatorParser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 130 ".\\OperatorParser.y"
ovOperators=yyattribute(2 - 2).ovOpers;
														REDUCE("Grammar 3")
#line 236 "OperatorParser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 135 ".\\OperatorParser.y"
REDUCE("Facts 1")
#line 249 "OperatorParser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 139 ".\\OperatorParser.y"
pvStart=yyattribute(3 - 4).pvPredicates;
														 if(!PredicateFactory::isFullyInstantiated(pvStart))
														 {
															string sError="Start and Goal must be fully instantiated.";
															yyerror(sError.c_str());
															yysyntaxerror();
														 }
														 REDUCE("Start 1")
#line 269 "OperatorParser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 150 ".\\OperatorParser.y"
pvGoal=yyattribute(3 - 4).pvPredicates;
														 if(!PredicateFactory::isFullyInstantiated(pvStart))
														 {
															string sError="Start and Goal must be fully instantiated.";
															yyerror(sError.c_str());
															yysyntaxerror();
														 }
														 REDUCE("Goal 1")
#line 289 "OperatorParser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 161 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).ovOpers=yyattribute(1 - 2).ovOpers;
														 (*(YYSTYPE YYFAR*)yyvalptr).ovOpers->push_back(yyattribute(2 - 2).oper);
														 REDUCE("Operator_List 1")
#line 304 "OperatorParser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 164 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).ovOpers=new OperatorVector();
														 (*(YYSTYPE YYFAR*)yyvalptr).ovOpers->push_back(yyattribute(1 - 1).oper);
														 REDUCE("Operator_List 2")
#line 319 "OperatorParser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 172 ".\\OperatorParser.y"
if(!OperatorFactory::checkOperator(yyattribute(2 - 7).symbol, yyattribute(4 - 7).dnv, yyattribute(6 - 7).pvPredicates, yyattribute(7 - 7).pvPredicates))
														 {
															string sError="Variables in operator "+yyattribute(2 - 7).symbol+" do not match";
															yyerror(sError.c_str());
															yysyntaxerror();
														 }
														 (*(YYSTYPE YYFAR*)yyvalptr).oper= OperatorFactory::newOperator(yyattribute(2 - 7).symbol, yyattribute(4 - 7).dnv, yyattribute(6 - 7).pvPredicates, yyattribute(7 - 7).pvPredicates);
														 yyst->registerOperator((*(YYSTYPE YYFAR*)yyvalptr).oper);
														 REDUCE("Operator 1")
#line 340 "OperatorParser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 183 ".\\OperatorParser.y"
if(!OperatorFactory::checkOperator(yyattribute(2 - 4).symbol, NULL, yyattribute(3 - 4).pvPredicates, yyattribute(4 - 4).pvPredicates))
														 {
															string sError="Variables in operator "+yyattribute(2 - 4).symbol+" do not match";
															yyerror(sError.c_str());
															yysyntaxerror();
														 }
														 (*(YYSTYPE YYFAR*)yyvalptr).oper= OperatorFactory::newOperator(yyattribute(2 - 4).symbol, NULL, yyattribute(3 - 4).pvPredicates, yyattribute(4 - 4).pvPredicates);
														 yyst->registerOperator((*(YYSTYPE YYFAR*)yyvalptr).oper);
														 REDUCE("Operator 2")
#line 361 "OperatorParser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 195 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).pvPredicates=yyattribute(3 - 4).pvPredicates;
														REDUCE("Preconditions 1")
#line 375 "OperatorParser.cpp"
			}
		}
		break;
	case 11:
		{
#line 197 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).pvPredicates=NULL;
														REDUCE("Preconditions 2")
#line 384 "OperatorParser.cpp"
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 202 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).pvPredicates=yyattribute(3 - 4).pvPredicates;
														REDUCE("Effects 1")
#line 397 "OperatorParser.cpp"
			}
		}
		break;
	case 13:
		{
#line 204 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).pvPredicates=NULL;
														REDUCE("Effects 2")
#line 406 "OperatorParser.cpp"
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 209 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).pvPredicates=yyattribute(1 - 3).pvPredicates;
														 (*(YYSTYPE YYFAR*)yyvalptr).pvPredicates->push_back(yyattribute(3 - 3).predicate);
														 REDUCE("Predicate_List 1")
#line 420 "OperatorParser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 212 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).pvPredicates=new PredicateVector();
														 (*(YYSTYPE YYFAR*)yyvalptr).pvPredicates->push_back(yyattribute(1 - 1).predicate);
														 REDUCE("Predicate_List 2")
#line 435 "OperatorParser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 218 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).predicate=PredicateFactory::newPredicate(yyattribute(1 - 4).symbol, yyattribute(3 - 4).dnv);
														 yyst->registerPredicate((*(YYSTYPE YYFAR*)yyvalptr).predicate);
														 REDUCE("Predicate 1")
#line 450 "OperatorParser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 221 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).predicate=PredicateFactory::newPredicate(yyattribute(1 - 1).symbol, NULL, false);
														 yyst->registerPredicate((*(YYSTYPE YYFAR*)yyvalptr).predicate);
														 REDUCE("Predicate 2")
#line 465 "OperatorParser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 224 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).predicate=PredicateFactory::newPredicate(yyattribute(2 - 5).symbol, yyattribute(4 - 5).dnv, true);
														 yyst->registerPredicate((*(YYSTYPE YYFAR*)yyvalptr).predicate);
														 REDUCE("Predicate 3")
#line 480 "OperatorParser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 227 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).predicate=PredicateFactory::newPredicate(yyattribute(2 - 2).symbol, NULL, true);
														 yyst->registerPredicate((*(YYSTYPE YYFAR*)yyvalptr).predicate);
														 REDUCE("Predicate 4")
#line 495 "OperatorParser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 230 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).predicate=PredicateFactory::newPredicate(yyattribute(3 - 7).symbol, yyattribute(5 - 7).dnv, true);
														 yyst->registerPredicate((*(YYSTYPE YYFAR*)yyvalptr).predicate);
														 REDUCE("Predicate 3")
#line 510 "OperatorParser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 233 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).predicate=PredicateFactory::newPredicate(yyattribute(3 - 4).symbol, NULL, true);
														 yyst->registerPredicate((*(YYSTYPE YYFAR*)yyvalptr).predicate);
														 REDUCE("Predicate 4")
#line 525 "OperatorParser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 239 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).iFlag=yyattribute(1 - 1).iFlag;
														 REDUCE("Not 1")
#line 539 "OperatorParser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 241 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).iFlag=true;
														 REDUCE("Not 2")
#line 553 "OperatorParser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 246 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).dnv=yyattribute(1 - 3).dnv;
														 (*(YYSTYPE YYFAR*)yyvalptr).dnv->push_back(yyattribute(3 - 3).dn);
														 REDUCE("Term_List 1")
#line 568 "OperatorParser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 249 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).dnv=new TermVector();
														 (*(YYSTYPE YYFAR*)yyvalptr).dnv->push_back(yyattribute(1 - 1).dn);
														 REDUCE("Term_List 2")
#line 583 "OperatorParser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 255 ".\\OperatorParser.y"
string sTerm=yyattribute(1 - 1).symbol;
														 bool bVar=(isupper(sTerm[0]) || sTerm[0]=='_');
														 (*(YYSTYPE YYFAR*)yyvalptr).dn=TermFactory::newTerm(sTerm, bVar);
														 yyst->registerTerm((*(YYSTYPE YYFAR*)yyvalptr).dn);
														 REDUCE("Term 2")
#line 600 "OperatorParser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 260 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).dn=TermFactory::newTerm(yyattribute(1 - 1).symbol);
														 yyst->registerTerm((*(YYSTYPE YYFAR*)yyvalptr).dn);
														 REDUCE("Term 3")
#line 615 "OperatorParser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 263 ".\\OperatorParser.y"
(*(YYSTYPE YYFAR*)yyvalptr).dn=TermFactory::newTerm(yyattribute(1 - 1).symbol);
														 yyst->registerTerm((*(YYSTYPE YYFAR*)yyvalptr).dn);
														 REDUCE("Term 4")
#line 630 "OperatorParser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 266 ".\\OperatorParser.y"
yyerror("Function terms not allowed in STRIPS!");
														yysyntaxerror();
#line 644 "OperatorParser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "\'(\'", 40 },
		{ "\')\'", 41 },
		{ "\',\'", 44 },
		{ "\'-\'", 45 },
		{ "error", 256 },
		{ "OPERATOR", 257 },
		{ "PRECONDS", 258 },
		{ "EFFECTS", 259 },
		{ "START", 260 },
		{ "GOAL", 261 },
		{ "STRING", 262 },
		{ "NUMBER", 263 },
		{ "IDENTIFIER", 264 },
		{ "NOT", 265 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: Grammar",
		"Grammar: Facts",
		"Grammar: Operator_List",
		"Grammar: Facts Operator_List",
		"Facts: Start Goal",
		"Start: START \'(\' Predicate_List \')\'",
		"Goal: GOAL \'(\' Predicate_List \')\'",
		"Operator_List: Operator_List Operator",
		"Operator_List: Operator",
		"Operator: OPERATOR IDENTIFIER \'(\' Term_List \')\' Preconditions Effects",
		"Operator: OPERATOR IDENTIFIER Preconditions Effects",
		"Preconditions: PRECONDS \'(\' Predicate_List \')\'",
		"Preconditions:",
		"Effects: EFFECTS \'(\' Predicate_List \')\'",
		"Effects:",
		"Predicate_List: Predicate_List \',\' Predicate",
		"Predicate_List: Predicate",
		"Predicate: IDENTIFIER \'(\' Term_List \')\'",
		"Predicate: IDENTIFIER",
		"Predicate: Not IDENTIFIER \'(\' Term_List \')\'",
		"Predicate: Not IDENTIFIER",
		"Predicate: Not \'(\' IDENTIFIER \'(\' Term_List \')\' \')\'",
		"Predicate: Not \'(\' IDENTIFIER \')\'",
		"Not: NOT",
		"Not: \'-\'",
		"Term_List: Term_List \',\' Term",
		"Term_List: Term",
		"Term: IDENTIFIER",
		"Term: STRING",
		"Term: NUMBER",
		"Term: IDENTIFIER \'(\' Term_List \')\'"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 1, 1, 1 },
		{ 1, 2, 2 },
		{ 2, 2, 3 },
		{ 3, 4, 4 },
		{ 4, 4, 5 },
		{ 5, 2, 6 },
		{ 5, 1, 7 },
		{ 6, 7, 8 },
		{ 6, 4, 9 },
		{ 7, 4, 10 },
		{ 7, 0, 11 },
		{ 8, 4, 12 },
		{ 8, 0, 13 },
		{ 9, 3, 14 },
		{ 9, 1, 15 },
		{ 10, 4, 16 },
		{ 10, 1, 17 },
		{ 10, 5, 18 },
		{ 10, 2, 19 },
		{ 10, 7, 20 },
		{ 10, 4, 21 },
		{ 11, 1, 22 },
		{ 11, 1, 23 },
		{ 12, 3, 24 },
		{ 12, 1, 25 },
		{ 13, 1, 26 },
		{ 13, 1, 27 },
		{ 13, 1, 28 },
		{ 13, 4, 29 }
	};
	yyreduction = reduction;

	yytokenaction_size = 225;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 22, YYAT_SHIFT, 35 },
		{ 42, YYAT_SHIFT, 17 },
		{ 45, YYAT_SHIFT, 54 },
		{ 45, YYAT_SHIFT, 55 },
		{ 8, YYAT_SHIFT, 14 },
		{ 54, YYAT_SHIFT, 24 },
		{ 54, YYAT_SHIFT, 25 },
		{ 54, YYAT_SHIFT, 26 },
		{ 60, YYAT_SHIFT, 62 },
		{ 52, YYAT_SHIFT, 59 },
		{ 0, YYAT_SHIFT, 1 },
		{ 60, YYAT_SHIFT, 40 },
		{ 52, YYAT_SHIFT, 34 },
		{ 0, YYAT_SHIFT, 2 },
		{ 62, YYAT_SHIFT, 63 },
		{ 56, YYAT_SHIFT, 61 },
		{ 49, YYAT_SHIFT, 30 },
		{ 48, YYAT_SHIFT, 57 },
		{ 43, YYAT_SHIFT, 53 },
		{ 41, YYAT_SHIFT, 51 },
		{ 39, YYAT_SHIFT, 15 },
		{ 37, YYAT_SHIFT, 47 },
		{ 36, YYAT_SHIFT, 46 },
		{ 35, YYAT_SHIFT, 45 },
		{ 30, YYAT_SHIFT, 42 },
		{ 27, YYAT_SHIFT, 39 },
		{ 26, YYAT_SHIFT, 38 },
		{ 20, YYAT_SHIFT, 33 },
		{ 18, YYAT_SHIFT, 32 },
		{ 16, YYAT_SHIFT, 30 },
		{ 15, YYAT_SHIFT, 29 },
		{ 13, YYAT_SHIFT, 1 },
		{ 10, YYAT_SHIFT, 23 },
		{ 7, YYAT_SHIFT, 1 },
		{ 6, YYAT_ACCEPT, 0 },
		{ 4, YYAT_SHIFT, 1 },
		{ 3, YYAT_SHIFT, 10 },
		{ 2, YYAT_SHIFT, 9 },
		{ 1, YYAT_SHIFT, 8 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 42, YYAT_SHIFT, 18 },
		{ 42, YYAT_SHIFT, 19 },
		{ 8, YYAT_SHIFT, 15 },
		{ -1, YYAT_ERROR, 0 },
		{ 22, YYAT_SHIFT, 36 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -247, 1, YYAT_ERROR, 0 },
		{ -226, 1, YYAT_ERROR, 0 },
		{ -3, 1, YYAT_ERROR, 0 },
		{ -225, 1, YYAT_ERROR, 0 },
		{ -222, 1, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 34, 1, YYAT_ERROR, 0 },
		{ -224, 1, YYAT_REDUCE, 1 },
		{ -36, 1, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 42 },
		{ -8, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ -226, 1, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 54 },
		{ -10, 1, YYAT_ERROR, 0 },
		{ -230, 1, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ -12, 1, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ -14, 1, YYAT_DEFAULT, 52 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -40, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 42 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -14, 1, YYAT_REDUCE, 27 },
		{ -16, 1, YYAT_DEFAULT, 60 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_DEFAULT, 42 },
		{ -16, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_DEFAULT, 54 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_DEFAULT, 42 },
		{ -241, 1, YYAT_ERROR, 0 },
		{ -18, 1, YYAT_REDUCE, 20 },
		{ -20, 1, YYAT_DEFAULT, 52 },
		{ 0, 0, YYAT_DEFAULT, 54 },
		{ -238, 1, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 54 },
		{ -22, 1, YYAT_DEFAULT, 52 },
		{ -44, 1, YYAT_ERROR, 0 },
		{ -23, 1, YYAT_DEFAULT, 60 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ -38, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 54 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ -24, 1, YYAT_DEFAULT, 60 },
		{ -243, 1, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -32, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -257, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ -26, 1, YYAT_DEFAULT, 60 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -33, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ -27, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 21 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 26;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 0, 6 },
		{ 0, 7 },
		{ 0, 3 },
		{ 49, 58 },
		{ 0, 4 },
		{ 54, 60 },
		{ 54, 28 },
		{ 42, 52 },
		{ 42, 21 },
		{ 34, 44 },
		{ 34, 22 },
		{ 7, 13 },
		{ 7, 5 },
		{ 46, 56 },
		{ 40, 50 },
		{ 39, 49 },
		{ 38, 48 },
		{ 32, 43 },
		{ 29, 41 },
		{ 23, 37 },
		{ 16, 31 },
		{ 14, 27 },
		{ 13, 12 },
		{ 9, 20 },
		{ 8, 16 },
		{ 3, 11 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ -1, 7 },
		{ 0, -1 },
		{ 0, -1 },
		{ 21, -1 },
		{ 0, 13 },
		{ 0, -1 },
		{ 0, -1 },
		{ 6, -1 },
		{ 17, -1 },
		{ 14, 42 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, -1 },
		{ 9, 54 },
		{ 0, -1 },
		{ 12, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 10, 42 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 9, 42 },
		{ 0, -1 },
		{ 0, -1 },
		{ 5, 54 },
		{ 0, -1 },
		{ -1, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 4, 54 },
		{ 8, -1 },
		{ 1, -1 },
		{ 0, -1 },
		{ -2, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 1, 54 },
		{ 0, -1 },
		{ 0, -1 },
		{ -5, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -7, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 270 ".\\OperatorParser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

const string OperatorParser::version="Planner Parser version 0.1b";

void OperatorParser::yysyntaxerror()
{
	ostringstream oErr;
	
	oErr << "Line " << yylexerptr->yylineno;
	oErr << ": error: syntax error before \"";
	oErr << yylexerptr->yytext << "\"" << endl;

	yyerror(oErr.str().c_str());
	//yyerror(sErr);
	yyabort();
}

PredicateVector *OperatorParser::getStart()
{
	return this->pvStart;
}

PredicateVector *OperatorParser::getGoal()
{
	return this->pvGoal;
}

PredicateVector *OperatorParser::getPredicates()
{
	return this->pvPredicates;
}

OperatorVector *OperatorParser::getOperators()
{
	return this->ovOperators;
}

bool OperatorParser::setSymbolTable(SymbolTable *yyst)
{
	this->yyst=yyst;
	
	return (yyst!=NULL);
}
