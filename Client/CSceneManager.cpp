#include "pch.h"
#include "CSceneManager.h"
#include "StartScene.h"

CSceneManager::CSceneManager() : _scenes{}, _curScene(nullptr)
{

}

CSceneManager::~CSceneManager()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(SCENE_TYPE::END); ++i)
	{	
		if (_scenes[i] != nullptr)
		{
			delete _scenes[i];
		}
	}
}

void CSceneManager::init()
{
	// Scene ����
	_scenes[static_cast<unsigned int>(SCENE_TYPE::START)] = new StartScene;
	_scenes[static_cast<unsigned int>(SCENE_TYPE::START)]->SetName(L"StartScene");
	//_scenes[static_cast<unsigned int>(SCENE_TYPE::TOOL)] = new ToolScene;
	//_scenes[static_cast<unsigned int>(SCENE_TYPE::STAGE_01)] = new Stage01Scene;
	//_scenes[static_cast<unsigned int>(SCENE_TYPE::STAGE_02)] = new Stage02Scene;

	// ���� �� ����
	_curScene = _scenes[static_cast<unsigned int>(SCENE_TYPE::START)];
	_curScene->Enter();
}

void CSceneManager::update()
{
	_curScene->update();
}

void CSceneManager::render(HDC sceneDC)
{
	_curScene->render(sceneDC);
}
