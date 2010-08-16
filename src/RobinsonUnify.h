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
// RobinsonUnify.h: interface for the RobinsonUnify class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBINSONUNIFY_H__FDCCF0A1_FB2A_4A13_8AA3_6C77104E6FD9__INCLUDED_)
#define AFX_ROBINSONUNIFY_H__FDCCF0A1_FB2A_4A13_8AA3_6C77104E6FD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UnificationAlgorithm.h"

class RobinsonUnify : public UnificationAlgorithm  
{
protected:
	Term *t1, *t2;

	bool unify(Term *k1, Term *k2);
public:
	RobinsonUnify();
	virtual ~RobinsonUnify();

	virtual bool unifyPredicates(Predicate *p1, Predicate *p2);
	virtual void rollback();
};

#endif // !defined(AFX_ROBINSONUNIFY_H__FDCCF0A1_FB2A_4A13_8AA3_6C77104E6FD9__INCLUDED_)
