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
// Term.cpp: implementation of the Term class.
//
//////////////////////////////////////////////////////////////////////

#include "Term.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Term::Term(const string &sName, bool bVar)
{
	this->sName=sName;
	this->bFunction=false;
	this->bVariable=bVar;
	this->dnmVariables=NULL;
	this->dnBinding=NULL;
}

Term::Term(const string &sName, TermVector dnvTerms)
{
	this->sName=sName;
	this->bFunction=true;
	this->bVariable=false;
	this->dnmVariables=NULL;
	this->dnvTerms=dnvTerms;
	this->dnBinding=NULL;
}

Term::Term(Term *dn, TermMap *dnmVariables)
{
	if(dn->bVariable && dn->dnBinding!=NULL)
	{
		dn=dn->getBinding();
	}

	this->sName=dn->sName;
	this->bFunction=dn->bFunction;
	this->bVariable=dn->bVariable;
	this->dnmVariables=dnmVariables;
	this->dnBinding=NULL;

	//PRINT((dn->bFunction) << " && " << (dn->dnmVariables!=NULL))

	if(dn->bFunction)
	{
		TermVector dnvAux=dn->dnvTerms;

		for(TermVector::iterator i=dnvAux.begin(); i!=dnvAux.end(); i++)
		{
			Term *dnI=*i;
			Term *dnNew;
			if(dnI->bVariable)
			{
				dnNew=this->getVariable(dnI);
			}else
			{
				dnNew=new Term(dnI, dnmVariables);
			}

			dnvTerms.push_back(dnNew);
		}
	}
}

Term::~Term()
{
	if(this->bFunction)
	{
		for(TermVector::iterator i=dnvTerms.begin();
			i!=dnvTerms.end(); i++)
		{
			if(!(*i)->bVariable)
				delete *i;
		}
	}
}

string Term::getName()
{
	return this->sName;
}

Term * Term::getVariable(Term *dgVar)
{
	if(!dgVar->bVariable)
		return NULL;
	string sVarName=dgVar->sName;

	if(dnmVariables!=NULL)//If there is a variable mapping
	{
		//Try to find a pointer to the specific variable
		if(dnmVariables->find(sVarName) != dnmVariables->end())//if the pointer is found
			return (*dnmVariables)[sVarName];//return it
		else
		{
			//Create a new free Variable
			Term *dgNew=new Term(dgVar, this->dnmVariables);
			//Insert it into the map
			(*dnmVariables)[sVarName]=dgNew;
			return dgNew;//return NULL;
		}
	}else//if not return any variable
		return new Term(sVarName, true);
	return NULL;
}

bool Term::isVariable()
{
	return this->bVariable;
}

bool Term::isFunction()
{
	return this->bFunction;
}

bool Term::bind(Term *dn)
{
	Term *dnVar=this->getBinding();
	if(dnVar->bVariable && dnVar->dnBinding==NULL)
	{
		dnVar->dnBinding=dn;
		return true;
	}else
		return false;
}

bool Term::occur(Term *dn)
{
	bool bRes=false;
	if(this == dn)
		return false;
	if(this->dnBinding == dn)
		return false;
	for(TermVector::iterator i=dnvTerms.begin();
		i!=dnvTerms.end() && !bRes; i++)
	{
		Term *d=*i;
		bRes = d->occur(dn);
	}

	return bRes;

}

int Term::getArity()
{
	return dnvTerms.size();
}

//Goes through the binding structure (if there are multiple variables chained) and returns the final one
Term * Term::getBinding()
{
	if(this->bVariable && this->dnBinding!=NULL)
	{
		return dnBinding->getBinding();
	}else
		return this;
}

TermVector Term::getTerms()
{
	return this->dnvTerms;
}

bool Term::operator ==(const Term &dn)
{
	bool bRes=false;

	if(this!=&dn)
	{
		Term *dnB1=this;
		//If if one of the Terms is a bound variable, then get its binding
		if(this->bVariable && this->dnBinding!=NULL)
		{
			//Get the final binding of the variable
			while(dnB1->dnBinding!=NULL)
				dnB1=dnB1->dnBinding;
		}

		Term *dnB2;
		if(dn.bVariable && dn.dnBinding!=NULL)
		{
			dnB2=dn.dnBinding;
			//Get the final binding of the variable
			while(dnB2->dnBinding!=NULL)
				dnB2=dnB2->dnBinding;
		}

		//If the names are the same and both are functions with the same
		// arity then the answer might be true
		bRes = ((dnB1->sName == dnB2->sName) && (dnB1->bFunction==dnB2->bFunction));

		if(bRes && this->bFunction)
		{
			if(dnB1->dnvTerms.size() == dnB2->dnvTerms.size())
			{
				for(int i=0; (i< dnB1->dnvTerms.size() && bRes); i++)
				{
					Term *dn1=dnB1->dnvTerms[i];
					Term *dn2=dnB2->dnvTerms[i];

					bRes &= (*dn1) == (*dn2);
				}
			}else
				bRes=false;
		}
	}else
		bRes=false;

	return bRes;
}

string Term::toString()
{
	string sRes=this->sName;
	
	if(this->isFunction())
	{
		sRes+="(";
		for(TermVector::iterator i=this->dnvTerms.begin();
			i!=dnvTerms.end(); i++)
		{
			if(i!=this->dnvTerms.begin())
				sRes+=", ";
			Term *d=*i;
			sRes+= d->toString();
		}
		sRes+=")";
	}else if(this->isVariable())
	{
		sRes+="[";
		if(this->dnBinding!=NULL)
			sRes+=this->dnBinding->toString();
		sRes+="]";
	}

	return sRes;
}

void Term::unbind()
{
	if(this->bVariable && this->dnBinding!=NULL)
	{
		dnBinding=NULL;
	}else if(this->bFunction)
	{
		for(TermVector::iterator i=dnvTerms.begin(); i!=dnvTerms.end(); i++)
		{
			(*i)->unbind();
		}
	}
}
