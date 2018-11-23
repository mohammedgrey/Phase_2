#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "ToolsMenuAction.h"

ToolsMenuAction::ToolsMenuAction(ApplicationManager *pApp):Action(pApp)
{
}

void ToolsMenuAction::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();

	pOut->CreateToolMenulBar();

}

//Goes to Tools Menu
void ToolsMenuAction::Execute() {

	ReadActionParameters();

}

ToolsMenuAction::~ToolsMenuAction()
{
	
}
