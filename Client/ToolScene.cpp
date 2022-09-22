#include "pch.h"
#include "ToolScene.h"
#include "CKeyManager.h"

ToolScene::ToolScene()
{

}

ToolScene::~ToolScene()
{

}

void ToolScene::Enter()
{
	// 타일 생성
}

void ToolScene::Exit()
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




