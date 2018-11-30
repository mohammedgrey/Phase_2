#include "CRhombus.h"


CRhombus::CRhombus( Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	ID = 3;
}

Point CRhombus::getCenter() { return Center; }

void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRhom(Center, FigGfxInfo, Selected);
}

void Getcorners(Point center, Point * corners) {
	int Cx[4], Cy[4];
	Cx[0] = center.x + 150;
	Cy[0] = center.y;
	Cx[1] = center.x;
	Cy[1] = center.y + 85;
	Cx[2] = center.x - 150;
	Cy[2] = center.y;
	Cx[3] = center.x;
	Cy[3] = center.y - 85;

	corners[0].x = Cx[0];
	corners[1].x = Cx[1];
	corners[2].x = Cx[2];
	corners[3].x = Cx[3];

	corners[0].y = Cy[0];
	corners[1].y = Cy[1];
	corners[2].y = Cy[2];
	corners[3].y = Cy[3];

}

bool InsideRhom(CFigure* Ptr, int x, int y)
{
	Point p1 = (static_cast<CRhombus*>(Ptr))->getCenter();

	// Getting Rhombus's Corners
	Point corner[4];
	Getcorners(p1, corner);

	GfxInfo FigGfxInfo;
	CFigure *t1 = new CTriangle(corner[0], corner[1], corner[3], FigGfxInfo);
	CFigure *t2 = new CTriangle(corner[2], corner[1], corner[3], FigGfxInfo);

	if ((InsideTri(t1, x, y)) || (InsideTri(t2, x, y))) return true;


	return false;
}