#include "CEllipse.h"

CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	ID = 4;
}

Point CEllipse::getCenter() { return Center; }

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawEllip(Center, FigGfxInfo, Selected);
}

bool InsideEllip(CFigure* Ptr, int x, int y)
{
	Point p1 = (static_cast<CEllipse*>(Ptr))->getCenter();

	int rx = 150; // Semi-minor axis 
	int ry = 85;

	if ((pow((x - p1.x), 2) / pow(rx, 2)) + (pow((y - p1.y), 2) / pow(ry, 2)) <= 1) return true;

	return false;
}