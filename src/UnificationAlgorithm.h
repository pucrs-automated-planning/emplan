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
// UnificationAlgorithm.h: interface for the UnificationAlgorithm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNIFICATIONALGORITHM_H__AA138CB1_ECC3_48CD_943D_5C1EC2A9DAD1__INCLUDED_)
#define AFX_UNIFICATIONALGORITHM_H__AA138CB1_ECC3_48CD_943D_5C1EC2A9DAD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Predicate.h"
#include "Term.h"

class UnificationAlgorithm  
{
public:
	UnificationAlgorithm();
	virtual ~UnificationAlgorithm();

	//Unifies two Predicates assigning the variable bindings in the
	//Predicate's pointer structures
	virtual bool unifyPredicates(Predicate *p1, Predicate *p2)=0;
	//Rolls back the unification so that the variable binding made in
	//the last unification are undone
	virtual void rollback()=0;
};

#endif // !defined(AFX_UNIFICATIONALGORITHM_H__AA138CB1_ECC3_48CD_943D_5C1EC2A9DAD1__INCLUDED_)
