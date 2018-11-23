#ifndef MAIN_MENU_ACTION_H
#define  MAIN_MENU_ACTION_H


#include "Action.h"


class MainMenuAction :public Action
{
public:
	MainMenuAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	//Goes to Main menu
	virtual void Execute();


	~MainMenuAction();
};

#endif