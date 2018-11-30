#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point start;	
	Point end;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );

	Point getStart();
	Point getEnd();

	virtual void Draw(Output* pOut) const;
};
bool InsideLine(CFigure* Ptr, int x, int y);
#endif