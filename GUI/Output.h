#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void Output::ClearToolBar()const;// clear Tool bar to switch between Dar&Play modes
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void Output::CreateAddMenulBar() const;//creates Add menu inside Draw mode bar
	void Output::CreateToolMenulBar() const;//creates Tools menu inside Draw mode bar
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void Output::CreatePalette() const; // create Palette


	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected = false) const;

	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected = false) const;

	void DrawEllip(Point P1, GfxInfo EllipGfxInfo, bool selected = false) const; //Draw an Ellipse

	void DrawRhom(Point P1, GfxInfo RhomGfxInfo, bool selected = false) const; //Draw an Rhombus

///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif
 
