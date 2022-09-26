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
#include "UI.h"

ToolScene::ToolScene()
{

}

ToolScene::~ToolScene()
{

}

void ToolScene::update()
{
	CScene::update();

	// TOOL_SCENE_SERVICE service = TOOL_SCENE_SERVICE::CHANGE_IMAGE_IDX;
	// ToolSceneService(service);

	SetTileIdx();

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
	// Ÿ�� ����
	CreateTile(5, 5);

	// Camera Look ����
	Vector2 resolution = CCore::GetInstance()->GetResolution();
	CameraManager::GetInstance()->SetLookAtPos(resolution / 2.f);

	// UI �ϳ� �׽�Ʈ ���� (������ܿ� ��ġ)
	UI* parentUI = new UI();
	parentUI->SetScale(Vector2(500.f, 300.f));
	parentUI->SetPos(Vector2(resolution._x - parentUI->GetScale()._x, 0.f));

	UI* childUI = new UI();
	childUI->SetScale(Vector2(100.f, 40.f));
	childUI->SetPos(Vector2(0.f, 0.f));

	parentUI->AddChild(childUI);

	AddObject(parentUI, GROUP_TYPE::UI);

};

void ToolScene::Exit()
{
	
}

void ToolScene::SetTileIdx()
{
	// ���콺 Ŭ���� ���� ���� �����ϰ� �ϴ� �κ�.
	if (KEY_TAP(KEY::LBTN))
	{
		// ���콺 ���� ��ǥ�� ���ϴ� �۾�.
		Vector2 mousePos = MOUSE_POS;
		mousePos = CameraManager::GetInstance()->GetRealPos(mousePos);

		int tileXCount = static_cast<int>(GetTileX());
		int tileYCount = static_cast<int>(GetTileY());

		int col = static_cast<int>(mousePos._x / TILE_SIZE);
		int row = static_cast<int>(mousePos._y / TILE_SIZE);
		
		UINT tileIdx = row * tileXCount + col;
		
		if (mousePos._x < 0.f || tileXCount <= col || mousePos._y < 0.f || tileYCount <= row)
			return;
		
		const vector<CObject*>& vecTile = GetGroupObjects(GROUP_TYPE::TILE);
		dynamic_cast<Tile*>(vecTile[tileIdx])->AddImageIdx();
	}
}




void ToolScene::ToolSceneService(TOOL_SCENE_SERVICE srv)
{
	switch (srv)
	{
		case TOOL_SCENE_SERVICE::CHANGE_IMAGE_IDX:
		{
			Vector2 mousePos = MOUSE_POS;


		}
			break;
	}
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

			// ToolSceneȮ�� 
			// �����ϸ� nullptr
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



