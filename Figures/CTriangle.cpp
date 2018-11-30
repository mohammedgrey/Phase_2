#include "CTriangle.h"
#include <cmath>

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;

	ID = 2;
}


Point CTriangle::getCorner1() { return Corner1; }
Point CTriangle::getCorner2() { return Corner2; }
Point CTriangle::getCorner3() { return Corner3; }

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Triangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

double TriArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
  return  abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

bool InsideTri(CFigure* Ptr, int x, int y)
{
	Point p1 = (static_cast<CTriangle*>(Ptr))->getCorner1();
	Point p2 = (static_cast<CTriangle*>(Ptr))->getCorner2();
	Point p3 = (static_cast<CTriangle*>(Ptr))->getCorner3();

	double A = TriArea(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y); // Total Area
	double A1 = TriArea(x, y, p2.x, p2.y, p3.x, p3.y);// Partial Areas
	double A2 = TriArea(p1.x, p1.y, x, y, p3.x, p3.y);
	double A3 = TriArea(p1.x, p1.y, p2.x, p2.y, x, y);

	if (A == (A1 + A2 + A3)) return true;

	return false;
}