#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"


#include <typeinfo>


CopyAction::CopyAction(ApplicationManager *pApp) :Action(pApp)
{
}


void CopyAction::ReadActionParameters() {


	if (typeid(*(pManager->GetSelectedFig())) == typeid(CRectangle)) {
		
		CFigure* Copied = new CRectangle(*(static_cast<CRectangle*>(pManager->GetSelectedFig())));
		pManager->SetClipboard(Copied);
	}

	
	
		
		
	

}

void CopyAction::Execute() {

	ReadActionParameters();

}



CopyAction::~CopyAction()
{
}
