#ifndef ADD_ELLIP_ACTION_H
#define ADD_ELLIP_ACTION_H

#include "Action.h"

//Add Ellipse Action class
class AddEllipAction : public Action
{
private:
	Point P1; //Ellipse Center
	GfxInfo EllipGfxInfo;
public:
	AddEllipAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif