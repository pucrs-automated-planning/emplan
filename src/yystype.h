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
#if !defined(YYSTYPE_H)
#define YYSTYPE_H

#include "Predicate.h"
#include "Term.h"
#include "Operator.h"
#include "Debug.h"


typedef struct yystype{

	int iFlag;
	string symbol;
	Predicate *predicate;
	PredicateVector *pvPredicates;
	Operator *oper;
	OperatorVector *ovOpers;
	Term *dn;
	TermVector *dnv;
}yyvar;


#endif
