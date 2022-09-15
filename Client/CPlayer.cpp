#include "pch.h"
#include "CPlayer.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "CMissile.h"
#include "ThreeMissile.h"
#include "CSceneManager.h"
#include "CScene.h"
#include "Texture.h"
#include "PathManager.h"
#include "ResourceManager.h"
#include "Collider.h"

CPlayer::CPlayer() : p_myObject(nullptr)
{
	p_myObject = ResourceManager::GetInstance()->LoadTexture(L"PlayerTexture", L"Textures\\gb_player_1.bmp");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vector2{0.f, 5.f});
	GetCollider()->SetColliderScale(Vector2{ 30.f, 30.f });

	SetObjectName(L"gb_player_1");
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

	// Component�ִ� ��� ȣ��...
	CObject::ComponentRender(dc);
}

void CPlayer::CreateMissile()
{
	Vector2 playerPos = GetPos();
	
	// �̻��� ����
	CMissile* missile = new CMissile();

	// �̻��� ����
	missile->SetTheta(PI / 2.f);
	/*missile->SetDir(Vector2{-1.f, -7.f});*/

	// �̻��� ũ��
	missile->SetScale(Vector2(25.f, 25.f));

	// �̻��� ��ġ
	playerPos._y -= (GetScale()._y / 2.f) + (missile->GetScale()._y / 2.f);
	missile->SetPos(playerPos);

	// �̻��� �̸�
	SetObjectName(L"gb_missile_1");
	
	CreateObjectEvent(missile, GROUP_TYPE::PROJ_PLAYER);
}

void CPlayer::CreateThreeMissile()
{
	Vector2 playerPos = GetPos();

	// �̻��� ���� 1, 2, 3
	ThreeMissile* missile1 = new ThreeMissile();
	ThreeMissile* missile2 = new ThreeMissile();
	ThreeMissile* missile3 = new ThreeMissile();

	// �̻��� ũ�� 1, 2, 3
	missile1->SetScale(Vector2(25.f, 25.f));
	missile2->SetScale(Vector2(25.f, 25.f));
	missile3->SetScale(Vector2(25.f, 25.f));

	// �̻��� ��ġ 1, 2, 3
	playerPos._y -= (GetScale()._y / 2.f) + (missile1->GetScale()._y / 2.f);
	missile1->SetPos(playerPos);

	playerPos._x -= (missile2->GetScale()._x);
	missile2->SetPos(playerPos);

	playerPos._x += (missile2->GetScale()._x) + (missile3->GetScale()._x);
	missile3->SetPos(playerPos);
	
	// ID �ο� 1, 2, 3
	int id = 0;
	missile1->SetId(id);
	missile2->SetId(++id);
	missile3->SetId(++id);

	// �̸� ���� 1, 2, 3
	missile1->SetObjectName(L"gb_missile_1");
	missile2->SetObjectName(L"gb_missile_1");
	missile3->SetObjectName(L"gb_missile_1");

	CreateObjectEvent(missile1, GROUP_TYPE::PROJ_PLAYER);
	CreateObjectEvent(missile2, GROUP_TYPE::PROJ_PLAYER);
	CreateObjectEvent(missile3, GROUP_TYPE::PROJ_PLAYER);

	//CScene* curScene = CSceneManager::GetInstance()->GetCurScene();
	//curScene->AddObject(missile1, GROUP_TYPE::THREEMISSILE);
	//curScene->AddObject(missile2, GROUP_TYPE::THREEMISSILE);
 	//curScene->AddObject(missile3, GROUP_TYPE::THREEMISSILE);
}

