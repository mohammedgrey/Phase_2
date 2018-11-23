#ifndef ADD_FIG_ACTION_H
#define ADD_FIG_ACTION_H

#include "Action.h"

class AddFigureAction : public Action
{
public:
	AddFigureAction(ApplicationManager *pApp);


	virtual void ReadActionParameters();

	//Goes to Add figures menu
	virtual void Execute();


	~AddFigureAction();
};

#endif