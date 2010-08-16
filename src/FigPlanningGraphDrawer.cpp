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
// FigPlanningGraphDrawer.cpp: implementation of the FigPlanningGraphDrawer class.
//
//////////////////////////////////////////////////////////////////////

#include "FigPlanningGraphDrawer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FigPlanningGraphDrawer::FigPlanningGraphDrawer()
{
	this->cEdge.iR=1;
	this->cEdge.iG=1;
	this->cEdge.iB=1;

	this->cMutex.iR=255;
	this->cMutex.iG=0;
	this->cMutex.iB=0;

	this->cNode.iR=0;
	this->cNode.iG=0;
	this->cNode.iB=255;

	this->iFontSize=10;
	
	this->fHorzSpacing=8;
	this->fVertSpacing=3;

	this->fHorzMargin=2;
	this->fVertMargin=2;

	this->fScaleDownFactor=3;
	this->fScaleUpFactor=10;
}

FigPlanningGraphDrawer::~FigPlanningGraphDrawer()
{

}

//Draws the Planning Graph as a FIG object
ostream &FigPlanningGraphDrawer::drawGraph(PredicateLevelVector &plvPredicates, ActionLevelVector &alvActions, ostream &out)
{
	this->iMaxStringSize=this->getMaxStringSize(plvPredicates, alvActions);
	this->setUpSpacing();

	//Taking the definition of the planning graph, the size of the graph is 
	int iLastLevel=plvPredicates.size()+alvActions.size();

	for(int i=0; i<iLastLevel; i++)
	{
		ostringstream oss;
		oss << "Level "<< i;
		out << this->setColor(cEdge);
		string s=oss.str();
		out << this->drawText(this->getNodeXPosition(i), 0, s);

		if(i%2!=0)//If the index is of an action level (i.e. it is not even)
		{
			int iActionLevel=i/2;
			iMaxLevelSize=alvActions[iActionLevel].size();
			for(int j=0; j<alvActions[iActionLevel].size(); j++)
			{
				//Draw the actual node
				string sNodeName=alvActions[iActionLevel][j].getAction()->getKey();
				out << this->drawActionNode(i, j, sNodeName);

				//Draw the Precondition edges
				IntVector ivPreconditions=alvActions[iActionLevel][j].getPreconditionLinks();
				for(int k=0; k<ivPreconditions.size(); k++)
				{
					string sPredicate = plvPredicates[iActionLevel][ivPreconditions[k]].getPredicate()->getKey();
					out << this->drawPreconditionEdge(i, j, ivPreconditions[k], sNodeName, sPredicate);
				}

				//Draw the effect edges
				IntVector ivEffects=alvActions[iActionLevel][j].getEffectLinks();
				for(int k=0; k<ivEffects.size(); k++)
				{
					string sPredicate = plvPredicates[iActionLevel+1][ivEffects[k]].getPredicate()->getKey();
					out << this->drawEffectEdge(i, j, ivEffects[k], sNodeName, sPredicate);
				}

				//And draw the mutexes among the actions
				IntVector ivMutexes=alvActions[iActionLevel][j].getMutexes();
				for(int k=0; k<ivMutexes.size(); k++)
				{
					if(!isDrawn(j, ivMutexes[k]))
					{
						out << this->drawMutex(i, j, ivMutexes[k]);
						addMutex(j, ivMutexes[k]);
					}
				}

			}
		}else//or if it is a predicate level
		{
			int iPredicateLevel=i/2;
			iMaxLevelSize=plvPredicates[iPredicateLevel].size();
			for(int j=0; j<plvPredicates[iPredicateLevel].size(); j++)
			{
				//Draw the actual node
				string sNodeName=plvPredicates[iPredicateLevel][j].getPredicate()->getKey();
				out << this->drawPredicateNode(i, j, sNodeName);
				
				//And draw the mutexes among the actions
				IntVector ivMutexes=plvPredicates[iPredicateLevel][j].getMutexes();
				for(int k=0; k<ivMutexes.size(); k++)
				{
					if(!isDrawn(j, ivMutexes[k]))
					{
						out << this->drawMutex(i, j, ivMutexes[k]);
						addMutex(j, ivMutexes[k]);
					}
				}

			}
		}

		clearMutexes();
	}

	return out;
}

string FigPlanningGraphDrawer::setFontSize(int iSize)
{
	ostringstream out;

	out << "fontsize " << iSize << endl;

	return out.str();
}

string FigPlanningGraphDrawer::setColor(Color &c)
{
	ostringstream out;

	out << "color " << hex << c.iR << " " << hex << c.iG << " " << hex << c.iB << endl;
	//out << "fillintensity 50" << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawArc(float x1, float y1, float xmid, float ymid, float x2, float y2)
{
	ostringstream out;

	out << "arc " << x1 << " " << y1 << " " << xmid << " " << ymid << " " << x2 << " " << y2 << endl;
	//out << "arc " << x2 << " " << y2 << " " << xmid << " " << ymid << " " << x1 << " " << y1 << endl;
	//out << "arc " << xmid << " " << ymid << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawNode(float x, float y, float larg, float alt, float round)
{
	ostringstream out;

	out << "node " << x << " " << y << " " << larg << " " << alt << " " << round << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawBox(float x, float y, float larg, float alt)
{
	ostringstream out;

	out << "box " << x << " " << y << " " << larg << " " << alt << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawEllipsis(float x, float y, float rx, float ry)
{
	ostringstream out;

	out << "ellipse " << x << " " << y << " " << rx << " " << ry << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawCircle(float x, float y, float radius)
{
	ostringstream out;

	out << "circle " << x << " " << y << " " << radius << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawText(float x, float y, string &sText)
{
	ostringstream out;

	out << "text " << x << " " << y << " " << sText << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawArrow(float x1, float y1, float x2, float y2)
{
	ostringstream out;

	out << "arrow " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawLine(float x1, float y1, float x2, float y2)
{
	ostringstream out;

	out << "line " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

	return out.str();
}

string FigPlanningGraphDrawer::drawActionNode(int iActionLevel, int iActionIndex, string sActionName)
{
	ostringstream out;

	out << this->setColor(this->cNode);

	float fX=getNodeXPosition(iActionLevel);
	float fY=getNodeYPosition(iActionIndex);
	//this->drawNode(iX, iY, this->iFontSize/fScaleDownFactor, this->iFontSize/fScaleDownFactor, this->iFontSize);

	//iY-=this->iFontSize/fScaleDownFactor;

	out << this->drawText(fX, fY, sActionName);

	float fBoxWidth=12*sActionName.size()*dotsToCentimeters(iFontSize);
	float fBoxHeight=20*dotsToCentimeters(iFontSize);

	fX-=(fBoxWidth/2)+7*dotsToCentimeters(iFontSize);
	fY-=fBoxHeight-4*dotsToCentimeters(iFontSize);

	out << this->drawBox(fX, fY, fBoxWidth, fBoxHeight);

	return out.str();
}

string FigPlanningGraphDrawer::drawPredicateNode(int iPredicateLevel, int iPredicateIndex, string sPredicateName)
{
	ostringstream out;

	out << this->setColor(this->cNode);
	
	float fX=getNodeXPosition(iPredicateLevel);
	float fY=getNodeYPosition(iPredicateIndex);

	//this->drawNode(iX, iY, this->iFontSize/fScaleDownFactor, this->iFontSize/fScaleDownFactor, this->iFontSize);

	//iY-=this->iFontSize/fScaleDownFactor;

	out << this->drawText(fX, fY, sPredicateName);
	
	float fEllipsisXRadius=6*sPredicateName.size()*dotsToCentimeters(iFontSize);
	float fEllipsisYRadius=14*dotsToCentimeters(iFontSize);

	fX-=6*dotsToCentimeters(iFontSize);
	fY-=(fEllipsisYRadius/2);

	out << this->drawEllipsis(fX, fY, fEllipsisXRadius, fEllipsisYRadius);
	return out.str();
}

//Draws a precondition edge between an Action Level and a Predicate Level
string FigPlanningGraphDrawer::drawPreconditionEdge(int iActionLevel, int iActionIndex, int iPredicateIndex, string sAction, string sPredicate)
{
	ostringstream out;

	out << this->setColor(this->cEdge);

	float fX1=getNodeXPosition(iActionLevel);
	float fY1=getNodeYPosition(iActionIndex);
	//fY1-=5*dotsToCentimeters(iFontSize);
	
	fX1 -= (12*(sAction.size()/2)*dotsToCentimeters(iFontSize))+7*dotsToCentimeters(iFontSize);;
	fY1 -= 8*dotsToCentimeters(iFontSize);

	iActionLevel--;

	float fX2=getNodeXPosition(iActionLevel);
	float fY2=getNodeYPosition(iPredicateIndex);
	//fY2-=5*dotsToCentimeters(iFontSize);

	fX2 += 12*(sPredicate.size()/2)*dotsToCentimeters(iFontSize);
	fY2 -= 8*dotsToCentimeters(iFontSize);
	
	out << this->drawLine(fX1, fY1, fX2, fY2);

	return out.str();
}

//Draws an effect edge between an Action Level and a Predicate Level
string FigPlanningGraphDrawer::drawEffectEdge(int iActionLevel, int iActionIndex, int iPredicateIndex, string sAction, string sPredicate)
{
	ostringstream out;

	out << this->setColor(this->cEdge);

	float fX1=getNodeXPosition(iActionLevel);
	float fY1=getNodeYPosition(iActionIndex);
	//fY1-=5*dotsToCentimeters(iFontSize);
	
	fX1 += (12*(sAction.size()/2)*dotsToCentimeters(iFontSize))-7*dotsToCentimeters(iFontSize);;
	fY1 -= 8*dotsToCentimeters(iFontSize);

	iActionLevel++;

	float fX2=getNodeXPosition(iActionLevel);
	float fY2=getNodeYPosition(iPredicateIndex);
	//fY2-=5*dotsToCentimeters(iFontSize);
	
	fX2 -= 12*(sPredicate.size()/2)*dotsToCentimeters(iFontSize);
	fY2 -= 8*dotsToCentimeters(iFontSize);

	out << this->drawLine(fX1, fY1, fX2, fY2);

	return out.str();
}

string FigPlanningGraphDrawer::drawMutex(int iLevel, int i1, int i2)
{
	ostringstream out;

	out << this->setColor(this->cMutex);

	float fX1=getNodeXPosition(iLevel);
	float fY1=getNodeYPosition(i1);
	//fY1-=5*dotsToCentimeters(iFontSize);

	float fX2=getNodeXPosition(iLevel);
	float fY2=getNodeYPosition(i2);
	//fY2-=5*dotsToCentimeters(iFontSize);

	//float fDistancing=(this->fHorzSpacing/this->fScaleDownFactor);//Original distancing
	float fDistancing=(this->fHorzSpacing/this->fScaleDownFactor)*(abs(i1-i2)/(1.0*iMaxLevelSize));
	float fXMid=getNodeXPosition(iLevel)-fDistancing;
	float fYMid=(fY1+fY2)/2;

	out << this->drawArc(fX1, fY1, fXMid, fYMid, fX2, fY2);

	return out.str();
}

float FigPlanningGraphDrawer::dotsToCentimeters(float fPoints)
{
	float fDotsPerCentimeters=1*(XFIGRES/XFIGINCH);
	float fRes;

	fRes=fPoints/fDotsPerCentimeters;

	return fRes;
}

int FigPlanningGraphDrawer::getMaxStringSize(PredicateLevelVector &plvPredicates, ActionLevelVector &alvActions)
{
	iMaxStringSize=10;
	for(int i=0; i<plvPredicates.size(); i++)
	{
		for(int j=0; j<plvPredicates[i].size(); j++)
		{
			string sKey=plvPredicates[i][j].getPredicate()->getKey();
			if(iMaxStringSize < sKey.size())
			{
				iMaxStringSize=sKey.size();
			}
		}
	}

	for(int i=0; i<alvActions.size(); i++)
	{
		for(int j=0; j<alvActions[i].size(); j++)
		{
			string sKey=alvActions[i][j].getAction()->getKey();
			if(iMaxStringSize < sKey.size())
			{
				iMaxStringSize=sKey.size();
			}
		}
	}

	return iMaxStringSize;
}


float FigPlanningGraphDrawer::getNodeXPosition(int iLevel)
{
	float fRes;

	fRes=fHorzMargin+(this->fHorzSpacing*iLevel);

	return fRes;
}

float FigPlanningGraphDrawer::getNodeYPosition(int iNodeIndex)
{
	float fRes;

	fRes=fVertMargin+(this->fVertSpacing*iNodeIndex);
	//fRes=this->fVertSpacing*iNodeIndex;

	return fRes;
}

void FigPlanningGraphDrawer::setUpSpacing()
{
	float fDotsPerCentimeters=1*(XFIGRES/XFIGINCH);
	//The spacing should be the size in centimeters that the largest string can occupy so that strings do not overlap
	this->fHorzSpacing=12*(iFontSize*iMaxStringSize)/fDotsPerCentimeters;
	//The left margin should be half the size of a string (because strings are centered) so that it never escapes through the left
	this->fHorzMargin=fHorzSpacing/2;

	//Vertical spacing should be (roughly)three times the height of a string in cm.
	this->fVertSpacing=35*(iFontSize)/fDotsPerCentimeters;
	this->fVertMargin=fVertSpacing;
}


void FigPlanningGraphDrawer::addMutex(int i1, int i2)
{
	Mutex m={i1,i2};
	mv.push_back(m);
}

bool FigPlanningGraphDrawer::isDrawn(int i1, int i2)
{
	bool bRes=false;

	for(MutexVector::iterator i=mv.begin(); !bRes && i!=mv.end(); i++)
	{
		Mutex m=*i;
		bRes=((m.i1==i1 && m.i2==i2) || (m.i2==i1 && m.i1==i2));
	}

	return bRes;
}

void FigPlanningGraphDrawer::clearMutexes()
{
	MutexVector mvNew;

	mv.clear();
	mv=mvNew;
}
