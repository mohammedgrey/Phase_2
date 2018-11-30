#include "AddRhomAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRhomAction::AddRhomAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhomAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	RhomGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RhomGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhomGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhomAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CRhombus *R = new CRhombus(P1, RhomGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
