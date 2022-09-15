#include "pch.h"
#include "ToolScene.h"
#include "CKeyManager.h"

ToolScene::ToolScene()
{

}

ToolScene::~ToolScene()
{

}

void ToolScene::update()
{
	CScene::update();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}

}

void ToolScene::Enter()
{

}

void ToolScene::Exit()
{

}


