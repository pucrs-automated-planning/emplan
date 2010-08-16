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
// MemoizationLevel.cpp: implementation of the MemoizationLevel class.
//
//////////////////////////////////////////////////////////////////////

#include "MemoizationLevel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MemoizationLevel::MemoizationLevel()
{

}

MemoizationLevel::~MemoizationLevel()
{
	
}

//////////////////////////////////////////////////////////////////////
// Constructs the storing key for the integer vector given as 
// parameter
// Most of the efficiency of the memoization table resides here
// if this key generation takes too much time then it will
// globally slow the algorithm down
//////////////////////////////////////////////////////////////////////
string MemoizationLevel::makeKey(IntVector &iv)
{
	ostringstream out;

	//First sort the vector so that vector with the same entries in different orders
	//will occupy the same position
	sort(iv.begin(), iv.end());

	//Then converts each component of the vector into the key
	for(IntVector::iterator i=iv.begin(); i!=iv.end(); i++)
	{
		out << intToKey(*i);//<< ","; //The end of these line is only to be used with variable string size
	}

	return out.str();
}

//////////////////////////////////////////////////////////////////////
// Converts an integer into a part of the key, as of now it is a 
//simple conversion from integer to string
//////////////////////////////////////////////////////////////////////
string MemoizationLevel::intToKey(int i)
{
	char *c;
	unsigned int ui=i;
	c=(char *)&ui;

	string sRes(c);

	return sRes;
}

//////////////////////////////////////////////////////////////////////
// Checks if the goals given as parameter have not already been 
//proven unsatisfiable
//////////////////////////////////////////////////////////////////////
bool MemoizationLevel::isNoGood(IntVector &ivGoals)
{
	string sKey=makeKey(ivGoals);
	bool bRes = (ivmNoGoods.find(sKey) != ivmNoGoods.end());

	return bRes;
}

//////////////////////////////////////////////////////////////////////
// Adds a given set of goals as not satisfiable in the memoization
//level
//////////////////////////////////////////////////////////////////////
void MemoizationLevel::addNoGood(IntVector &ivGoals)
{
	string sKey=makeKey(ivGoals);

	if(ivmNoGoods.find(sKey) == ivmNoGoods.end())
	{
		ivmNoGoods[sKey]=true;
	}
}

//////////////////////////////////////////////////////////////////////
// Returns the number of entries that are currently in this level 
//of the memoization table
//////////////////////////////////////////////////////////////////////
int MemoizationLevel::size()
{
	return ivmNoGoods.size();
}

string MemoizationLevel::toString()
{
	ostringstream out;

	out << "No goods: \n";

	for(IntVectorMap::iterator i=ivmNoGoods.begin(); i!= ivmNoGoods.end(); i++)
	{
		out << "\t" << i->first << "\n";
	}

	return out.str();
}
