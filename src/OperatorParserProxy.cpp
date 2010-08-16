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
// OperatorParserProxy.cpp: implementation of the OperatorParserProxy class.
//
//////////////////////////////////////////////////////////////////////

#include "OperatorParserProxy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OperatorParserProxy::OperatorParserProxy()
{
	if (parser.yycreate(&lexer) && parser.setSymbolTable(lexer.getSymbolTable())) {
		if (lexer.yycreate(&parser) && lexer.yyin!=NULL) {
			this->bStartUp=true;
			//n = parser.yyparse();
			//while(lexer.yylex()!=0);
		}else
			this->bStartUp=false;
	}else
		this->bStartUp=false;
}

OperatorParserProxy::~OperatorParserProxy()
{

}


bool OperatorParserProxy::parse(string sFilename)
{
	if(bStartUp)
	{
		ifstream *yyin=new ifstream(sFilename.c_str());
		//FILE *yyin = fopen(sFilename.c_str(),"r");
		if(!yyin->fail())
		{
			lexer.yyin=yyin;
			PRINTL("Teste 1")
			n = parser.yyparse();
			//lexer.yyin=&cin;
			yyin->close();
		}else
		{
			WRITELN("Cannot open file: \""<< sFilename << "\".");
			n = YYEXIT_FAILURE;
		}
		delete yyin;
	}
	else
	{
		cerr << "Error initializing parser" << endl;
		return false;
	}

	if(n==YYEXIT_SUCCESS)
	{
		WRITELN("Parse Process Complete");
		//Do planning now
		return true;
	}else
		return false;
}

PredicateVector OperatorParserProxy::getStart()
{
	return *parser.getStart();
}

PredicateVector OperatorParserProxy::getGoal()
{
	return *parser.getGoal();
}

OperatorVector OperatorParserProxy::getOperators()
{
	return *parser.getOperators();
}

SymbolTable *OperatorParserProxy::getSymbolTable()
{
	return lexer.yyst;
}

string OperatorParserProxy::toString()
{
	string sRes;

	sRes+=lexer.version+"\n";
	sRes+=parser.version+"\n";

	return sRes;
}
