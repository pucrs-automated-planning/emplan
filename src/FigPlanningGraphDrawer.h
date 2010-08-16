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
// FigPlanningGraphDrawer.h: interface for the FigPlanningGraphDrawer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIGPLANNINGGRAPHDRAWER_H__0E611660_91DD_491F_995A_8A4342A10132__INCLUDED_)
#define AFX_FIGPLANNINGGRAPHDRAWER_H__0E611660_91DD_491F_995A_8A4342A10132__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PlanningGraphDrawer.h"

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;
using std::endl;

#include <iomanip>
using std::hex;

/*# Comandos permitidos

# color rr gg bb     (em hexadecimal)
# fillcolor rr gg bb (em hexadecimal)
# fillintensity f    (f = 0..100)
# thickness t        (t = 1, 2, 3, ... em 1/80 pol.)
# depth d        (0..999, default 50)
# line x1 y1 x2 y2 ... xn yn
# arrow x1 y1 x2 y2
# arrow2 x1 y1 x2 y2
# poly x1 y1 x2 y2 ... xn yn
# node x y larg alt round
# box x y larg alt
# arc x1 y1 xmid ymid x2 y2 
# fontsize s         (s em pontos)
# fontangle a        (a em graus)
# justify s          (s = "center", "left", "right")
# caps s             (s = "butt", "round", "project")
# text x y bla bla bla bla
# circle x y r
# ellipse x y rx ry
# scale s
# object
# end
*/

/*
Lembretes:
De acordo com o script do JB são 1200 pontos por polegada, fazendo a conversão pelas polegadas
bizarras do XFifg, temos aproximadamente 450 pontos por centímetro.
*/

#define XFIGRES 1200
#define XFIGINCH 2.66666666

class FigPlanningGraphDrawer : public PlanningGraphDrawer  
{
	//Adaptação ad-hoc para evitar que um mutex seja desenhado duas vezes, atrapalhando desta forma
	//A sua visualização pelo xfig
	typedef struct Mutex{
		int i1;
		int i2;
	};
	
	typedef struct Color{
		int iR;
		int iG;
		int iB;
	};

	typedef vector<Mutex> MutexVector;
protected:
	float fHorzSpacing;
	float fVertSpacing;

	float fHorzMargin;
	float fVertMargin;

	float fScaleDownFactor;
	float fScaleUpFactor;

	int iFontSize;

	int iMaxStringSize;//For scaling purposes
	int iMaxLevelSize;//Again for scaling purposes

	Color cMutex;
	Color cEdge;
	Color cNode;

	string setFontSize(int iSize);
	string setColor(Color &c);

	string drawArc(float x1, float y1, float xmid, float ymid, float x2, float y2);
	string drawNode(float x, float y, float larg, float alt, float round);
	string drawBox(float x, float y, float larg, float alt);
	string drawEllipsis(float x, float y, float rx, float ry);
	string drawCircle(float x, float y, float radius);
	string drawText(float x, float y, string &sText);
	string drawArrow(float x1, float y1, float x2, float y2);
	string drawLine(float x1, float y1, float x2, float y2);

	string drawActionNode(int iActionLevel, int iActionIndex, string sActionName);
	string drawPredicateNode(int iPredicateLevel, int iPredicateIndex, string sPredicateName);
	string drawPreconditionEdge(int iActionLevel, int iActionIndex, int iPredicateIndex, string sAction, string sPredicate);
	string drawEffectEdge(int iActionLevel, int iActionIndex, int iPredicateIndex, string sAction, string sPredicate);
	string drawMutex(int iLevel, int i1, int i2);

	int getMaxStringSize(PredicateLevelVector &plvPredicates, ActionLevelVector &alvActions);
	float dotsToCentimeters(float fPoints);
	float getNodeXPosition(int iLevel);
	float getNodeYPosition(int iIndex);

	void setUpSpacing();

	//Solução para o desenho correto dos Mutexes
	MutexVector mv;

	void addMutex(int i1, int i2);
	bool isDrawn(int i1, int i2);
	void clearMutexes();
public:
	FigPlanningGraphDrawer();
	virtual ~FigPlanningGraphDrawer();

	virtual ostream &drawGraph(PredicateLevelVector &plvPredicates, ActionLevelVector &alvActions, ostream &out);
};

#endif // !defined(AFX_FIGPLANNINGGRAPHDRAWER_H__0E611660_91DD_491F_995A_8A4342A10132__INCLUDED_)
