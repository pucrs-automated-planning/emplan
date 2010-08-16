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
OperatorLexer.l
ParserWizard generated Lex file.

Date: domingo, 9 de fevereiro de 2003
****************************************************************************/

#include "OperatorParser.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
%include {
#include"Debug.h"
#include "SymbolTable.h"
}
// lexical analyser name
%name OperatorLexer

// class definition
{
	// place any extra class members here
	public:
		//Override the default output function
		void yyoutput(int ch);
		SymbolTable *yyst;
		
		static const string version;
		
		SymbolTable *getSymbolTable();
}

// constructor
{
	// place any extra initialisation code here
	yyst=new SymbolTable();
}

// destructor
{
	// place any extra cleanup code here
	delete yyst;
}

// place any declarations here
letter				[a-zA-Z_]
digit				[0-9]
esc					\\([abfnrtv"'?\\]|[0-7]{1,3}|x[0-9a-fA-F]+)
alphanum			[a-zA-Z_0-9]
blank				[ \t]
other				.

%x COMMENT
%x LINECOMMENT

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here

"operator"			{PRINT(" TK_OPERATOR ") return OPERATOR;}
"preconds"			{PRINT(" TK_PRECONDS ") return PRECONDS;}
"effects"			{PRINT(" TK_EFFECTS ") return EFFECTS;}
"start"				{PRINT(" TK_START ") return START;}
"goal"				{PRINT(" TK_GOAL ") return GOAL;}
"not"				{PRINT(" TK_NOT ") return NOT;}

{letter}{alphanum}*							{PRINT(" TK_IDENTIFIER ") 
												yylval.symbol=yytext;
												return IDENTIFIER;}

{digit}+[uUlL]*								{PRINT(" TK_NUMBER ")
												yylval.symbol=yytext;
												return NUMBER;}
L?\"([^"\\\n]|{esc})*\"						{PRINT(" TK_STRING")
												yylval.symbol=yytext;
												return STRING;}
L?\'([^"\\\n]|{esc})*\'						{PRINT(" TK_STRING")
												yylval.symbol=yytext;
												return STRING;}
{digit}+\.{digit}*((e|E)("+"|"-"){digit}+)?	{PRINT(" TK_NUMBER ")
												yylval.symbol=yytext;
												return NUMBER;}
\.{digit}+((e|E)("+"|"-"){digit}+)?			{PRINT(" TK_NUMBER ")
												yylval.symbol=yytext;
												return NUMBER;}

{blank}+		{;}

"/*"			BEGIN(COMMENT);
<COMMENT>"*/"		BEGIN(0);
<COMMENT>[^*\n]+	;		/* breaks comments into lines */
<COMMENT>\n			;//++yylineno;	/* so they won't overflow buffer */
<COMMENT>"*"		;		/* so they won't overflow buffer */

"//"			BEGIN(LINECOMMENT);
<LINECOMMENT>"\n"	BEGIN(0);

{other}			{PRINT(yytext[0]) return yytext[0];}

%%

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