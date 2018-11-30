#include "MainMenuAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"






MainMenuAction::MainMenuAction(ApplicationManager *pApp) : Action(pApp)
{
}

void MainMenuAction::ReadActionParameters() {


	Output* pOut = pManager->GetOutput();

	pOut->CreateDrawToolBar();

}

//Goes to Main menu
void MainMenuAction::Execute() {

	ReadActionParameters();

}



MainMenuAction::~MainMenuAction()
{
}
