#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	/////////////
	/// for add menu
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse
	
	/////////////
	/// for tools menu
	SELECT,

	CHNG_DRAW_CLR,	//Change the selected drawing color
	CHNG_FILL_CLR,	//Change the selected filling color


	COPY,
	CUT,
	PASTE,
	DEL,			//Delete a figure(s)
	/////////////
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file
	
	/////////////

	SELECT_BLACK,	//adding colors actions
	SELECT_GREY,
	SELECT_BROWN,
	SELECT_WHITE,
	SELECT_RED,
	SELECT_GREEN,
	SELECT_BLUE,
	SELECT_YELLOW,
	SELECT_ORANGE,
	SELECT_PINK,
	SELECT_PURPLE,
	SELECT_LIGHTBLUE,

	PHCOLOR_MODE,// Play mode operatios
	PHTYPE_MODE,

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	PALETTE,		//A click on the palette bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	/////////////
	/// Actions for switching to inner menues
	TO_MAINMENU,
	TO_ADDMENU,
	TO_TOOLMENU,
	/////////////
	TO_PLAY,		//Switch interface to Play mode

	EXIT			//Exit the application

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};


enum TrialEnum //The actions supported (you can add more if needed)
{
	T1,
	T2,
	T3

};

#endif
 
