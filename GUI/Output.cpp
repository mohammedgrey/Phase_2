#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;

	UI.PaletteHeight = 550;
	UI.PaletteWidth = 40;
	UI.PaletteItemHeight = 40;

	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = color(97, 42, 140);	//Filling color
	UI.MsgColor = BLACK;		//Messages color
	UI.BkGrndColor = color(172, 171, 173);	//Background color
	UI.HighlightColor = color(26, 255, 255);	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = WHITE;
	UI.ToolBarColor = WHITE;
	UI.PaletteColor = WHITE;
	UI.PenWidth = 15;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreatePalette();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(UI.PaletteWidth, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);

	//Draw a line above the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePalette() const
{

	//Background Creating
	pWind->SetPen(UI.PaletteColor, 1);
	pWind->SetBrush(UI.PaletteColor);
	pWind->DrawRectangle(0, UI.height - (UI.StatusBarHeight + UI.PaletteHeight) + 3, UI.PaletteWidth, UI.height - UI.StatusBarHeight);


	/// reawing palette menu iteam

	color PaletteColor[DRAW_COLORS_COUNT];

	PaletteColor[COLOR_BLACK] = BLACK;

	PaletteColor[COLOR_GREY] = color(96, 96, 96);

	PaletteColor[COLOR_BROWN] = color(102, 51, 0);

	PaletteColor[COLOR_WHITE] = WHITE;

	PaletteColor[COLOR_RED] = color(249, 6, 6);

	PaletteColor[COLOR_GREEN] = color(0, 153, 0);

	PaletteColor[COLOR_BLUE] = color(0, 64, 255);

	PaletteColor[COLOR_YELLOW] = YELLOW;

	PaletteColor[COLOR_ORANGE] = color(255, 102, 0);

	PaletteColor[COLOR_PINK] = color(255, 51, 153);

	PaletteColor[COLOR_PURPLE] = PURPLE;

	PaletteColor[COLOR_LIGHTBLUE] = LIGHTBLUE;



	//Draw one color at a time	
	int q;
	for (int i = 0; i < DRAW_COLORS_COUNT; i++)
	{

		pWind->SetPen(PaletteColor[i], 1);
		pWind->SetBrush(PaletteColor[i]);
		pWind->DrawRectangle(0, UI.ToolBarHeight + (UI.PaletteItemHeight*i) + (2 * i), UI.PaletteWidth, UI.ToolBarHeight + UI.PaletteItemHeight*(i + 1) + (2 * i));

		pWind->SetPen(color(64, 64, 64), 3);
		pWind->DrawLine(0, UI.ToolBarHeight + UI.PaletteItemHeight*(i + 1) + (2 * i), UI.PaletteWidth, UI.ToolBarHeight + UI.PaletteItemHeight*(i + 1) + (2 * i));
		q = i;
	}




	//Print "Colors" under the palette

	int sHeight = UI.ToolBarHeight + UI.PaletteItemHeight*(q + 1) + (2 * q);
	sHeight += 20;

	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(BLACK);
	pWind->SetFont(13, BOLD, BY_NAME, "Comic Sans MS");
	pWind->DrawString(1, sHeight, "COLORS");
	//Draw a line Rigth to the Palette
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(UI.PaletteWidth, UI.ToolBarHeight, UI.PaletteWidth, UI.height - UI.StatusBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()const
{
	//Clear Tool bar by drawing a filled white rectangle
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	UI.DrawbarMenu = MENU_MAIN;

	ClearToolBar();

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_ADDMENU] = "images\\MenuItems\\Addmenu.jpg";

	MenuItemImages[ITM_TOOLMENU] = "images\\MenuItems\\Toolmenu.jpg";

	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Savegraph.jpg";

	MenuItemImages[ITM_SAVEBYTYPE] = "images\\MenuItems\\Savebytype.jpg";

	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";

	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Playmode.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);



}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateAddMenulBar() const
{
	UI.DrawbarMenu = MENU_ADD;

	ClearToolBar();

	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum AddMenu
	string MenuItemImages[ADD_ITM_COUNT];

	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Rectangle.jpg";

	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Line.jpg";

	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Triangle.jpg";

	MenuItemImages[ITM_RHOM] = "images\\MenuItems\\Rhombus.jpg";

	MenuItemImages[ITM_ELLIP] = "images\\MenuItems\\Ellipse.jpg";

	MenuItemImages[ITM_TOMAIN] = "images\\MenuItems\\Mainmenu.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ADD_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);





}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateToolMenulBar() const
{
	UI.DrawbarMenu = MENU_TOOL;

	ClearToolBar();

	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum ToolMenu

	string MenuItemImages[TOOL_ITM_COUNT];

	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Select.jpg";

	MenuItemImages[ITM_CHANGEDRAWINGCOLOR] = "images\\MenuItems\\Changedcolor.jpg";

	MenuItemImages[ITM_CHANGEFILLCOLOR] = "images\\MenuItems\\Changefcolor.jpg";

	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Copy.jpg";

	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";

	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Paste.jpg";

	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Delete.jpg";

	MenuItemImages[ITM_TOMAIN2] = "images\\MenuItems\\Mainmenu.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < TOOL_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar();

	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PHCOLOR] = "images\\MenuItems\\Phcolor.jpg";

	MenuItemImages[ITM_PHTYPE] = "images\\MenuItems\\Phtype.jpg";

	MenuItemImages[ITM_DRAWMODE] = "images\\MenuItems\\Drawmode.jpg";

	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);




	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(UI.PaletteWidth + 3, UI.ToolBarHeight + 3, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////


void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Comic Sans MS");
	pWind->DrawString((const int)((1250 - msg.length()) / 3.2), UI.height - (int)(UI.StatusBarHeight / 1.2), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}


//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 2);

	drawstyle style;
	style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);


}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);


}

void Output::DrawRhom(Point P1, GfxInfo RhomGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RhomGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RhomGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhomGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int Px[4], Py[4];
	Px[0] = P1.x + 150;
	Py[0] = P1.y;
	Px[1] = P1.x;
	Py[1] = P1.y + 85;
	Px[2] = P1.x - 150;
	Py[2] = P1.y;
	Px[3] = P1.x;
	Py[3] = P1.y - 85;

	pWind->DrawPolygon(Px, Py, 4, style);

}

void Output::DrawEllip(Point P1, GfxInfo EllipGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = EllipGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (EllipGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllipGfxInfo.FillClr);
	}
	else
		style = FRAME;

	Point P2, P3;
	P2.x = P1.x - 150;
	P2.y = P1.y - 85;
	P3.x = P1.x + 150;
	P3.y = P1.y + 85;

	pWind->DrawEllipse(P2.x, P2.y, P3.x, P3.y, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
