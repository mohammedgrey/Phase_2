#include "DeleteAction.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager *pApp) :Action(pApp)
{
}
/*
void DeleteAction::ReadActionParameters()
{
	CFigure **A;
	A = pManager->GetFigureList();
	int c;
	for (int i = 0; i < pManager->GetFigureCount(); i++)
	{
		if (A[i] == pManager->GetSelectedFigure())
		{
			delete A[i];
			c = i;
		}
	}
	A[c] = A[pManager->GetFigureCount() - 1];
	A[pManager->GetFigureCount() - 1] = NULL;
	pManager->DecrementCount();

}
*/
void DeleteAction::Execute()
{ 
	ReadActionParameters(); 
}