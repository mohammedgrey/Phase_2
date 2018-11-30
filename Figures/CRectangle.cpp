#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID = 0;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

Point CRectangle::getCorner1() {

	return Corner1;
}
Point CRectangle::getCorner2() {
	return Corner2;
}

bool InsideRect(CFigure* Ptr, int x, int y)
{
	int Xo;
	int Yo;
	int Xf;
	int Yf;

	Point p1 = (static_cast<CRectangle*>(Ptr))->getCorner1();
	Point p2 = (static_cast<CRectangle*>(Ptr))->getCorner2();

	Xo = (p1.x < p2.x) ? p1.x : p2.x;
	Yo = (p1.y < p2.y) ? p1.y : p2.y;
	Xf = (p1.x > p2.x) ? p1.x : p2.x;
	Yf = (p1.y > p2.y) ? p1.y : p2.y;

	if ((x >= Xo && x <= Xf) && (y >= Yo && y <= Yf)) return true;


	return false;
}