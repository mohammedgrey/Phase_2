#pragma once

#include "Action.h"
#include "../Figures/CFigure.h"
class SelectAction :public Action
{
private:
	Point Click;
	CFigure* Selected;

public:
	

	SelectAction(ApplicationManager*);

	void ReadActionParameters();

	void Execute();

	
};

