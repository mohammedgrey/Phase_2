#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo );

	Point getCorner1();
	Point getCorner2();
	Point getCorner3();

	

	virtual void Draw(Output* pOut) const;
};


double TriArea(int x1, int y1, int x2, int y2, int x3, int y3);
bool InsideTri(CFigure* Ptr, int x, int y);

#endif