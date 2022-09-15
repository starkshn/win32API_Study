#pragma once
#include "CScene.h"
class ToolScene : public CScene
{
private :

public :
	ToolScene();
	virtual ~ToolScene() override;

public:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void update() override;

};

