#ifndef TOOLS_MENU_ACTION_H
#define TOOLS_MENU_ACTION_H

#include "Action.h"

class ToolsMenuAction :public Action
{
public:
	ToolsMenuAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	//Goes to Tools Menu
	virtual void Execute();

	~ToolsMenuAction();



};






#endif
