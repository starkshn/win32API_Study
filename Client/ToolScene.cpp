#include "pch.h"
#include "ToolScene.h"
#include "CKeyManager.h"
#include "ResourceManager.h"
#include "CameraManager.h"
#include "CCore.h"
#include "Tile.h"
#include "Texture.h"
#include "Resource.h"
#include "CSceneManager.h"
#include "CScene.h"

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
	
	// 타일 생성
	CreateTile(5, 5);

	// Camera Look 지정
	Vector2 resolution = CCore::GetInstance()->GetResolution();
	CameraManager::GetInstance()->SetLookAtPos(resolution / 2.f);
};

void ToolScene::Exit()
{

};

// =======================
// Tile Count window Proc
// =======================
INT_PTR CALLBACK TileCountProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			// IDC_EDIT1 : x ID
			// IDC_EDIT2 : y ID
			UINT xCount = GetDlgItemInt(hDlg, IDC_EDIT1, nullptr, false);
			UINT yCount = GetDlgItemInt(hDlg, IDC_EDIT2, nullptr, false);

			CScene* curScene = CSceneManager::GetInstance()->GetCurScene();

			// ToolScene확인 
			// 실패하면 nullptr
			ToolScene* toolScene = dynamic_cast<ToolScene*>(curScene);
			assert(toolScene);


			toolScene->DeleteGroupObjects(GROUP_TYPE::TILE);
			toolScene->CreateTile(xCount, yCount);

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

