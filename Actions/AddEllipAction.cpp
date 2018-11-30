#include "AddEllipAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "../Figures/CEllipse.h"

AddEllipAction::AddEllipAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddEllipAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	EllipGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CEllipse *R = new CEllipse(P1, EllipGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
