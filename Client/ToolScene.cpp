#include "pch.h"
#include "ToolScene.h"
#include "CKeyManager.h"
#include "ResourceManager.h"
#include "CameraManager.h"
#include "CCore.h"
#include "Tile.h"
#include "Texture.h"

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

void ToolScene::render(HDC dc)
{
	CScene::render(dc);
};

void ToolScene::Enter()
{
	Texture* tileTexture = ResourceManager::GetInstance()->LoadTexture(L"Tile", L"Textures\\tiles.bmp");

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			Tile* tile = new Tile();

			tile->SetPos(Vector2(static_cast<float>(j * TILE_SIZE), static_cast<float>(i * TILE_SIZE)));
			tile->SetTexture(tileTexture);

			AddObject(tile, GROUP_TYPE::TILE);

		}
	}

	// Camera Look ÁöÁ¤
	Vector2 resolution = CCore::GetInstance()->GetResolution();
	CameraManager::GetInstance()->SetLookAtPos(resolution / 2.f);
};

void ToolScene::Exit()
{

};


