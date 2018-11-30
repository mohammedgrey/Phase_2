#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions/ToolsMenuAction.h"

#include "Actions/AddFigureAction.h"
#include "Actions/MainMenuAction.h"
#include "Figures/CRectangle.h"
#include "Figures/CLine.h"
#include "Figures/CTriangle.h"
#include "Figures/CRhombus.h"
#include "Figures/CEllipse.h"

#include <cmath>

#include "Actions\AddLineAction.h"
#include "Actions/AddEllipAction.h"
#include "Actions/AddRhomAction.h"
#include "Actions/AddTriAction.h"
#include "Actions/SelectAction.h"




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{

		case TO_ADDMENU:
			pAct = new AddFigureAction(this);
			break;

		case TO_MAINMENU:
			pAct = new MainMenuAction(this);
			break;

		case TO_TOOLMENU:
			pAct = new ToolsMenuAction(this);
			break;


		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhomAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	
	int Type;
	CFigure* Ptr;

	for (int i = FigCount-1; i >= 0; i--) {

		Type = FigList[i]->GetID();
		Ptr = FigList[i];

		switch (Type)
		{
		case 0:
			if (InsideRect(FigList[i], x, y)) return FigList[i];
			break;
		case 1:
			if (InsideLine(FigList[i], x, y)) return FigList[i];
			break;
		case 2:
				if (InsideTri(FigList[i], x, y)) return FigList[i];
			break;
		case 3:
				if (InsideRhom(FigList[i], x, y)) return FigList[i];
				break;
		case 4:
				if (InsideEllip(FigList[i], x, y)) return FigList[i];
				break;
		}
	}
	
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it or you will simply get ZERO.

	return NULL;
}

void ApplicationManager::SetSelectedFig(CFigure*a) {
	SelectedFig = a;
}

CFigure *ApplicationManager::GetSelectedFig() {
	return SelectedFig;
}

void ApplicationManager::SetClipboard(CFigure * C) {
	Clipboard = C;

}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
