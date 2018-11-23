
#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			if (UI.DrawbarMenu == MENU_MAIN)// if main menu was enabaled
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_ADDMENU: return TO_ADDMENU;
				case ITM_TOOLMENU: return TO_TOOLMENU;
				case ITM_SAVE: return SAVE;
				case ITM_SAVEBYTYPE: return SAVE_BY_TYPE;
				case ITM_LOAD: return LOAD;
				case ITM_PLAYMODE: return TO_PLAY;
				case ITM_EXIT: return EXIT;

				default: return EMPTY;	//A click on empty place in desgin toolbar

				}
			}
			else if (UI.DrawbarMenu == MENU_ADD) // if ADD menu was enabaled
			{
				//Check whick Menu item was clicked
							//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_RECT: return DRAW_RECT;
				case ITM_LINE: return DRAW_LINE;
				case ITM_TRI: return DRAW_TRI;
				case ITM_RHOM: return DRAW_RHOMBUS;
				case ITM_ELLIP: return DRAW_ELLIPSE;
				case ITM_TOMAIN: return TO_MAINMENU;


				default: return EMPTY;	//A click on empty place in desgin toolbar

				}
			}
			else if (UI.DrawbarMenu == MENU_TOOL) // if TOOLS menu was enabaled
			{
				//Check whick Menu item was clicked
											//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_SELECT: return SELECT;
				case ITM_CHANGEDRAWINGCOLOR: return CHNG_DRAW_CLR;
				case ITM_CHANGEFILLCOLOR: return CHNG_FILL_CLR;
				case ITM_COPY: return COPY;
				case ITM_CUT: return CUT;
				case ITM_PASTE: return PASTE;
				case ITM_DELETE: return DEL;
				case ITM_TOMAIN2: return TO_MAINMENU;

				default: return EMPTY;	//A click on empty place in desgin toolbar

				}
			}

		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x >= UI.PaletteWidth)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the palette area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x < UI.PaletteWidth)
		{
			int ClickedItemOrder = (y / (UI.PaletteItemHeight + 3));
			ClickedItemOrder--;

			switch (ClickedItemOrder) {

			case COLOR_BLACK: return SELECT_BLACK;
			case COLOR_BROWN: return SELECT_BROWN;
			case COLOR_WHITE: return SELECT_WHITE;
			case COLOR_RED: return SELECT_RED;
			case COLOR_GREEN: return SELECT_GREEN;
			case COLOR_BLUE: return SELECT_BLUE;
			case COLOR_YELLOW: return SELECT_YELLOW;
			case COLOR_ORANGE: return SELECT_ORANGE;
			case COLOR_PINK: return SELECT_PINK;
			case COLOR_PURPLE: return SELECT_PURPLE;
			case COLOR_LIGHTBLUE: return SELECT_LIGHTBLUE;
			case COLOR_GREY: return SELECT_GREY;

				// add cases for each color
			default:return PALETTE;
			}
		}

		//[4] User clicks on the status bar
		return STATUS;


	}
	else	//GUI is in PLAY mode
	{


		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PHCOLOR: return PHCOLOR_MODE;
			case ITM_PHTYPE: return PHTYPE_MODE;
			case ITM_DRAWMODE: return TO_DRAW;
			case ITM_EXIT2: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x >= UI.PaletteWidth)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the palette area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x < UI.PaletteWidth)
		{
			int ClickedItemOrder = (y / (UI.PaletteItemHeight + 3));
			ClickedItemOrder--;

			switch (ClickedItemOrder) {

			case COLOR_BLACK: return SELECT_BLACK;
			case COLOR_GREY: return SELECT_GREY;
			case COLOR_BROWN: return SELECT_BROWN;
			case COLOR_WHITE: return SELECT_WHITE;
			case COLOR_RED: return SELECT_RED;
			case COLOR_GREEN: return SELECT_GREEN;
			case COLOR_BLUE: return SELECT_BLUE;
			case COLOR_YELLOW: return SELECT_YELLOW;
			case COLOR_ORANGE: return SELECT_ORANGE;
			case COLOR_PINK: return SELECT_PINK;
			case COLOR_PURPLE: return SELECT_PURPLE;
			case COLOR_LIGHTBLUE: return SELECT_LIGHTBLUE;

				// add cases for each color
			default:return PALETTE;
			}
		}

		//[4] User clicks on the status bar
		return STATUS;




		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}
