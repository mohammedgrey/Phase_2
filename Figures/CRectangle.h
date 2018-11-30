#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );

	Point getCorner1();
	Point getCorner2();

	virtual void Draw(Output* pOut) const;

	
};
bool InsideRect(CFigure* Ptr, int x, int y);
#endif