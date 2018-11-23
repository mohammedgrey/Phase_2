#include "AddFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



AddFigureAction::AddFigureAction(ApplicationManager *pApp) :Action(pApp)
{
}

void AddFigureAction::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();

	pOut->CreateAddMenulBar();


}

void AddFigureAction::Execute() {

	ReadActionParameters();




}


AddFigureAction::~AddFigureAction()
{
}
