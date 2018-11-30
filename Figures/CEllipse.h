#ifndef CELLIP_H
#define CELLIP_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Center;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);

	Point getCenter();

	virtual void Draw(Output* pOut) const;
};
bool InsideEllip(CFigure* Ptr, int x, int y);
#endif