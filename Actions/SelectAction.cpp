#include "SelectAction.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

SelectAction::SelectAction(ApplicationManager*pApp) : Action(pApp)
{
	
}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Action: Click Anywhere");

	//Read center and store in point Click
	pIn->GetPointClicked(Click.x, Click.y);

	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	//Use GetFigure to determine if the click was on figure or not
	
	Selected = pManager->GetFigure(Click.x, Click.y);
	// If any figure is found then make it selected
	if (Selected != NULL)
	{ 
		if (pManager->GetSelectedFig() != NULL) { (pManager->GetSelectedFig())->SetSelected(false); }//unselect any selected figure when select another one


		if (pManager->GetSelectedFig() == Selected) 
		{ 
			Selected->SetSelected(false);
			pManager->SetSelectedFig(NULL);
		}
		else {
			pManager->SetSelectedFig(Selected);
			Selected->SetSelected(true);
		}
	}
	else
	{
		if (pManager->GetSelectedFig() != NULL) {
			(pManager->GetSelectedFig())->SetSelected(false);
			pManager->SetSelectedFig(NULL);
		} // unselect any selected figure when the click is on the drawing area
	}


}


