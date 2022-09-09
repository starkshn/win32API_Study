#include "pch.h"
#include "CPlayer.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "CMissile.h"
#include "CCharingMissile.h"
#include "ThreeMissile.h"
#include "CSceneManager.h"
#include "CScene.h"
#include "Texture.h"
#include "PathManager.h"
#include "ResourceManager.h"
#include "Collider.h"

CPlayer::CPlayer() : p_myObject(nullptr)
{
	p_myObject = ResourceManager::GetInstance()->LoadTexture(L"PlayerTexture", L"Textures\\Plane2.bmp");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vector2{0.f, 5.f});
	GetCollider()->SetColliderScale(Vector2{ 30.f, 30.f });
}
CPlayer::~CPlayer()
{
	
}

void CPlayer::update()
{
	Vector2 pos = GetPos();

	if ( KEY_HOLD(KEY::W) )
	{
		pos._y -= 200.f * DeltaTime_F;
	}
	if (KEY_HOLD(KEY::S))
	{
		pos._y += 200.f * DeltaTime_F;
	}
	if (KEY_HOLD(KEY::A))
	{
		pos._x -= 200.f * DeltaTime_F;
	}
	if (KEY_HOLD(KEY::D))
	{
		pos._x += 200.f * DeltaTime_F;
	}

	// Missile
	if (KEY_TAP(KEY::Z))
	{
		CreateMissile();
	}
	if (KEY_TAP(KEY::SPACE))
	{
		CreateThreeMissile();
	}

	SetPos(pos);
}

void CPlayer::render(HDC dc)
{
	int width = static_cast<int>(p_myObject->GetWidth());
	int height = static_cast<int>(p_myObject->GetHeight());

	Vector2 pos = GetPos();

	//BitBlt
	//(
	//	dc,
	//	static_cast<int>(pos._x - static_cast<float>//((width / 2))),
	//	static_cast<int>(pos._y - static_cast<float>//((height / 2))),
	//	width,
	//	height,
	//	_myObject->GetDC(),
	//	0, 0, SRCCOPY
	//);

	TransparentBlt
	(
		dc,
		static_cast<int>(pos._x - static_cast<float>((width / 2))),
		static_cast<int>(pos._y - static_cast<float>((height / 2))),
		width,
		height,
		p_myObject->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255)
	);

	// Component있는 경우 호출...
	CObject::ComponentRender(dc);
}

void CPlayer::CreateMissile()
{
	Vector2 playerPos = GetPos();
	
	// 미사일 생성
	CMissile* missile = new CMissile();

	// 미사일 방향
	missile->SetTheta(PI / 2.f);
	/*missile->SetDir(Vector2{-1.f, -7.f});*/

	// 미사일 크기
	missile->SetScale(Vector2(25.f, 25.f));

	// 미사일 위치
	playerPos._y -= (GetScale()._y / 2.f) + (missile->GetScale()._y / 2.f);
	missile->SetPos(playerPos);
	
	CScene* curScene = CSceneManager::GetInstance()->GetcurScene();
	curScene->AddObject(missile, GROUP_TYPE::MISSILE);
}

void CPlayer::CreateThreeMissile()
{
	Vector2 playerPos = GetPos();

	// 미사일 생성
	ThreeMissile* missile1 = new ThreeMissile();
	ThreeMissile* missile2 = new ThreeMissile();
	ThreeMissile* missile3 = new ThreeMissile();

	// 미사일 크기
	missile1->SetScale(Vector2(25.f, 25.f));
	missile2->SetScale(Vector2(25.f, 25.f));
	missile3->SetScale(Vector2(25.f, 25.f));

	// 미사일 위치
	playerPos._y -= (GetScale()._y / 2.f) + (missile1->GetScale()._y / 2.f);
	missile1->SetPos(playerPos);

	playerPos._x -= (missile2->GetScale()._x);
	missile2->SetPos(playerPos);

	playerPos._x += (missile2->GetScale()._x) + (missile3->GetScale()._x);
	missile3->SetPos(playerPos);
	
	int id = 0;
	missile1->SetId(id);
	missile2->SetId(++id);
	missile3->SetId(++id);

	CScene* curScene = CSceneManager::GetInstance()->GetcurScene();

	curScene->AddObject(missile1, GROUP_TYPE::THREEMISSILE);
	curScene->AddObject(missile2, GROUP_TYPE::THREEMISSILE);
	curScene->AddObject(missile3, GROUP_TYPE::THREEMISSILE);
}

void CPlayer::ChargingMissile()
{
}

void CPlayer::ShootMissile()
{
	
}

