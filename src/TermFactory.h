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
// TermFactory.h: interface for the TermFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TermFACTORY_H__C53C04D7_5D7D_4AC3_895E_EC59C33372FB__INCLUDED_)
#define AFX_TermFACTORY_H__C53C04D7_5D7D_4AC3_895E_EC59C33372FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Term.h"

class TermFactory  
{
public:
	static Term * newTerm(const string &sName, TermVector dnvTerms);
	static Term * newTerm(const string &sName, bool bVar=false);
	TermFactory();
	virtual ~TermFactory();

};

#endif // !defined(AFX_TermFACTORY_H__C53C04D7_5D7D_4AC3_895E_EC59C33372FB__INCLUDED_)
