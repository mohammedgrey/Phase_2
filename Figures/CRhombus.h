#ifndef CRHOM_H
#define CRHOM_H

#include "CFigure.h"
#include "CTriangle.h"

class CRhombus : public CFigure
{
private:
	Point Center;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);

	Point getCenter();

	virtual void Draw(Output* pOut) const;
};

void Getcorners(Point center, Point* corners);
bool InsideRhom(CFigure* Ptr, int x, int y);
#endif