#ifndef ADD_RHOM_ACTION_H
#define ADD_RHOM_ACTION_H

#include "Action.h"

//Add Rhombus Action class
class AddRhomAction : public Action
{
private:
	Point P1; //Rhombus center
	GfxInfo RhomGfxInfo;
public:
	AddRhomAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();

	//Add rehombus to the ApplicationManager
	virtual void Execute();

};

#endif