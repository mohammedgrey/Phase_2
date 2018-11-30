#ifndef COPY_ACTION_H
#define COPY_ACTION_H

#include "Action.h"


class CopyAction : public Action
{
public:
	CopyAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	//copies the selected figure
	virtual void Execute();



	~CopyAction();

private:

};






#endif
