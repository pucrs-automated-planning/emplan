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
%{
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

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

%include {
#include"Debug.h"
#include "SymbolTable.h"

#include "Operator.h"
#include "Predicate.h"
#include "Term.h"

#include "OperatorFactory.h"
#include "PredicateFactory.h"
#include "TermFactory.h"

#include "yystype.h"
}

// parser name
%name OperatorParser

// class definition
{
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
}

// constructor
{
	// place any extra initialisation code here
	this->pvStart=NULL;
	this->pvGoal=NULL;
	this->pvPredicates=NULL;
	this->ovOperators=NULL;
}

// destructor
{
	// place any extra cleanup code here
}

/*%union {
	int iFlag;
	char *symbol;
	Predicate *predicate;
	PredicateVector *pvPredicates;
	Operator *oper;
	OperatorVector *ovOpers;
	Term *dn;
	TermVector *dnv;
}*/

// attribute type
%include {
#ifndef YYSTYPE
//#define YYSTYPE int
#define YYSTYPE yystype
#endif
}

// place any declarations here

%token <oper> OPERATOR
%token <pvPredicates> PRECONDS
%token <pvPredicates> EFFECTS
%token <pvPredicates> START
%token <pvPredicates> GOAL
%token <symbol> STRING
%token <symbol> NUMBER
%token <symbol> IDENTIFIER
%token <iFlag> NOT

%type <pvPredicates> Start Goal Predicate_List Preconditions Effects
%type <ovOpers> Operator_List
%type <predicate> Predicate
%type <oper> Operator
%type <dnv> Term_List
%type <dn> Term
%type <iFlag> Not

%start Grammar

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

Grammar
	: Facts												{REDUCE("Grammar 1")}
	| Operator_List										{ovOperators=$1;
														REDUCE("Grammar 2")}
	| Facts Operator_List								{ovOperators=$2;
														REDUCE("Grammar 3")}
	;

Facts
	: Start Goal										{REDUCE("Facts 1")}
	;
	
Start
	: START '(' Predicate_List ')'						{pvStart=$3;
														 if(!PredicateFactory::isFullyInstantiated(pvStart))
														 {
															string sError="Start and Goal must be fully instantiated.";
															yyerror(sError.c_str());
															yysyntaxerror();
														 }
														 REDUCE("Start 1")}
	;

Goal
	: GOAL '(' Predicate_List ')'						{pvGoal=$3;
														 if(!PredicateFactory::isFullyInstantiated(pvStart))
														 {
															string sError="Start and Goal must be fully instantiated.";
															yyerror(sError.c_str());
															yysyntaxerror();
														 }
														 REDUCE("Goal 1")}
	;

Operator_List
	: Operator_List Operator							{$$=$1;
														 $$->push_back($2);
														 REDUCE("Operator_List 1")}
	| Operator											{$$=new OperatorVector();
														 $$->push_back($1);
														 REDUCE("Operator_List 2")}
	;

Operator
	: OPERATOR IDENTIFIER '(' Term_List ')'
	  Preconditions
	  Effects											{if(!OperatorFactory::checkOperator($2, $4, $6, $7))
														 {
															string sError="Variables in operator "+$2+" do not match";
															yyerror(sError.c_str());
															yysyntaxerror();
														 }
														 $$= OperatorFactory::newOperator($2, $4, $6, $7);
														 yyst->registerOperator($$);
														 REDUCE("Operator 1")}
	| OPERATOR IDENTIFIER
	  Preconditions
	  Effects											{if(!OperatorFactory::checkOperator($2, NULL, $3, $4))
														 {
															string sError="Variables in operator "+$2+" do not match";
															yyerror(sError.c_str());
															yysyntaxerror();
														 }
														 $$= OperatorFactory::newOperator($2, NULL, $3, $4);
														 yyst->registerOperator($$);
														 REDUCE("Operator 2")}
	;
	
Preconditions
	: PRECONDS '(' Predicate_List ')'					{$$=$3;
														REDUCE("Preconditions 1")}
	|													{$$=NULL;
														REDUCE("Preconditions 2")}
	;
	
Effects
	: EFFECTS '(' Predicate_List ')'					{$$=$3;
														REDUCE("Effects 1")}
	|													{$$=NULL;
														REDUCE("Effects 2")}
	;

Predicate_List
	: Predicate_List ',' Predicate						{$$=$1;
														 $$->push_back($3);
														 REDUCE("Predicate_List 1")}
	| Predicate											{$$=new PredicateVector();
														 $$->push_back($1);
														 REDUCE("Predicate_List 2")}
	;

Predicate
	: IDENTIFIER '(' Term_List ')'						{$$=PredicateFactory::newPredicate($1, $3);
														 yyst->registerPredicate($$);
														 REDUCE("Predicate 1")}
	| IDENTIFIER										{$$=PredicateFactory::newPredicate($1, NULL, false);
														 yyst->registerPredicate($$);
														 REDUCE("Predicate 2")}
	| Not IDENTIFIER '(' Term_List ')'					{$$=PredicateFactory::newPredicate($2, $4, true);
														 yyst->registerPredicate($$);
														 REDUCE("Predicate 3")}
	| Not IDENTIFIER									{$$=PredicateFactory::newPredicate($2, NULL, true);
														 yyst->registerPredicate($$);
														 REDUCE("Predicate 4")}
	| Not '(' IDENTIFIER '(' Term_List ')' ')'			{$$=PredicateFactory::newPredicate($3, $5, true);
														 yyst->registerPredicate($$);
														 REDUCE("Predicate 3")}
	| Not '(' IDENTIFIER ')'							{$$=PredicateFactory::newPredicate($3, NULL, true);
														 yyst->registerPredicate($$);
														 REDUCE("Predicate 4")}
	;

Not
	: NOT												{$$=$1;
														 REDUCE("Not 1")}													
	| '-'												{$$=true;
														 REDUCE("Not 2")}
	;

Term_List
	: Term_List ',' Term								{$$=$1;
														 $$->push_back($3);
														 REDUCE("Term_List 1")}
	| Term												{$$=new TermVector();
														 $$->push_back($1);
														 REDUCE("Term_List 2")}
	;
	
Term
	: IDENTIFIER										{string sTerm=$1;
														 bool bVar=(isupper(sTerm[0]) || sTerm[0]=='_');
														 $$=TermFactory::newTerm(sTerm, bVar);
														 yyst->registerTerm($$);
														 REDUCE("Term 2")}
	| STRING											{$$=TermFactory::newTerm($1);
														 yyst->registerTerm($$);
														 REDUCE("Term 3")}
	| NUMBER											{$$=TermFactory::newTerm($1);
														 yyst->registerTerm($$);
														 REDUCE("Term 4")}
	| IDENTIFIER '(' Term_List ')'						{yyerror("Function terms not allowed in STRIPS!");
														yysyntaxerror();}
	;

%%

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