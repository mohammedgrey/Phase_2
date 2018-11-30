#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
	ID = 1;
}
	

Point CLine::getStart() { return start; }
Point CLine::getEnd() { return end; }

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a rectangle on the screen	
	pOut->DrawLine(start, end, FigGfxInfo, Selected);
}

bool InsideLine(CFigure* Ptr, int x, int y)
{
	int Xo;
	int Yo;
	int Xf;
	int Yf;

	Point p1 = (static_cast<CLine*>(Ptr))->getStart();
	Point p2 = (static_cast<CLine*>(Ptr))->getEnd();

	Xo = (p1.x < p2.x) ? p1.x : p2.x;
	Yo = (p1.y < p2.y) ? p1.y : p2.y;
	Xf = (p1.x > p2.x) ? p1.x : p2.x;
	Yf = (p1.y > p2.y) ? p1.y : p2.y;

	double m1;// slope of line ( start to end )
	double m2;// slope of line ( Clicked point to end )

	m1 = (double)(p1.y - p2.y) / (p1.x - p2.x);

	if (!(Xo>=Xf-15 && Xo<=Xf+15) && !(Yo >= Yf - 15 && Yo <= Yf + 15))
	{
		if ((x >= Xo && x <= Xf) && (y >= Yo && y <= Yf))
		{
			m2 = (double)(y - p2.y) / (x - p2.x);
			if ((m1 + 0.35) >= m2 && (m1 - 0.35) <= m2) return true;
		}
	}
	else {
		if ((x >= Xo - 5 && x <= Xf + 5) && (y >= Yo - 5 && y <= Yf + 5))
		{
			 return true;
		}
	}

	return false;
}