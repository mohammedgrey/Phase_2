#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)

	MODE_PLAY	//Playing mode
};

enum DRAW_MENU
{
	MENU_MAIN, // main menu for draw bar mood
	MENU_ADD,  // menu inside draw mode bar
	MENU_TOOL // menu inside draw mode bar
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_ADDMENU,

	ITM_TOOLMENU,

	ITM_SAVE,

	ITM_SAVEBYTYPE,

	ITM_LOAD,

	ITM_PLAYMODE,

	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum AddMenu //The items of the Add menu 
{

	ITM_RECT,		//Recangle item in menu


	ITM_LINE,

	ITM_TRI,

	ITM_RHOM,

	ITM_ELLIP,    //Ellipse item menu

	

	ITM_TOMAIN,

	ADD_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum


};

enum ToolMenu //The items of the tools menu 
{
	
	ITM_SELECT,


	ITM_CHANGEDRAWINGCOLOR,

	ITM_CHANGEFILLCOLOR,


	ITM_COPY,

	ITM_CUT,

	ITM_PASTE,

	ITM_DELETE,

	ITM_TOMAIN2,

	TOOL_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum


};


enum DrawPalette //The items of the Draw menu (you should add more items)
{
	COLOR_BLACK,
	COLOR_BROWN,
	COLOR_GREEN,
	COLOR_RED,
	COLOR_YELLOW,
	COLOR_ORANGE,
	COLOR_WHITE,
	COLOR_BLUE,
	COLOR_LIGHTBLUE,
	COLOR_GREY,
	COLOR_PINK,
	COLOR_PURPLE,
	
	
	//Add colors

	DRAW_COLORS_COUNT		//no. of colors ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{

	ITM_PHCOLOR, // Pick and hide figure color mode

	ITM_PHTYPE,	// Pick and hide figure type mode

	ITM_DRAWMODE, // Back to draw mode

	ITM_EXIT2, // exit the program

	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	DRAW_MENU DrawbarMenu;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		PaletteHeight,		//Palette Height
		PaletteWidth,		//Palette Width
		PaletteItemHeight,	//Height of each item in Palette menu
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;     //Tool bar color
	color PaletteColor;		//Palette color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif
