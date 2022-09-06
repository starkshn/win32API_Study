#include "pch.h"
#include "StartScene.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CCore.h"
#include "CMissile.h"
#include "PathManager.h"
#include "Texture.h"

StartScene::StartScene()
{

}

StartScene::~StartScene()
{
	// 씬 전부 삭제
	
}

void StartScene::Enter()
{
	Texture* texture = new Texture();

	wstring filePath = PathManager::GetInstance()->GetContentsPath();
	filePath += L"textures\\apple.bmp";
	texture->Load(filePath);


	
	delete texture;

	// Object 추가
	CObject* obj = new CPlayer();
	obj->SetPos(Vector2(640.f, 384.f));
	obj->SetScale(Vector2(100.f, 100.f));

	AddObject(obj, GROUP_TYPE::PLAYER);

	// 몬스터 오브젝트
	CMonster* monster = nullptr;

	// 몬스터 배치
	SetMonsterCount(16);
	float moveDistance = 25.f;
	float monsterScale = 50.f;

	Vector2 resolution = CCore::GetInstance()->GetResolution();
	float term = ( resolution._x - (moveDistance + monsterScale / 2.f) * 2) / static_cast<float>(GetMonsterCount() - 1);

	for (int i = 0; i < GetMonsterCount(); ++i)
	{
		monster = new CMonster();
		monster->SetPos(Vector2( (moveDistance + monsterScale / 2.f )+ static_cast<float>(i) * term, 50.f));
		monster->SetMoveDistance(moveDistance);
		monster->SetCenterAnchor(monster->GetPos());
		monster->SetScale(Vector2(50.f, 50.f));
		monster->SetMonsterId(_monsterId++);
		AddObject(monster, GROUP_TYPE::MONSTER);
	}
}

void StartScene::Exit()
{

}
