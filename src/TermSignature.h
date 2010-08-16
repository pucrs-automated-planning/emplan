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
// TermSignature.h: interface for the TermSignature class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERMSIGNATURE_H__65A71333_7B3E_4E27_9845_F2AD41BFA644__INCLUDED_)
#define AFX_TERMSIGNATURE_H__65A71333_7B3E_4E27_9845_F2AD41BFA644__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Signature.h"
#include "Term.h"

class TermSignature : public Signature  
{
protected:
	Term *tSignature;
public:
	TermSignature();
	TermSignature(Term *t);
	virtual ~TermSignature();

	virtual string toString();
	TermSignature & operator=(TermSignature &tRight);

	Term *getTerm();
	
	static string getSignature(Term *t);
};

#endif // !defined(AFX_TERMSIGNATURE_H__65A71333_7B3E_4E27_9845_F2AD41BFA644__INCLUDED_)
