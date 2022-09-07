#include "pch.h"
#include "CMonster.h"
#include "CTimeManager.h"
#include "CMissile.h"
#include "CScene.h"
#include "CSceneManager.h"
#include "MonsterMissile.h"
#include "CCore.h"
#include "ResourceManager.h"
#include "Texture.h"

CMonster::CMonster() 
	: 
	_speed(100.f), 
	_loopDistance(50.f),
	_centerAnchor{0.f, 0.f},
	_missile(nullptr),
	_dir(1)
{
	_texture = ResourceManager::GetInstance()->LoadTexture(L"MonsterTexture", L"Textures\\monsterPlane.bmp");
	_missileTexture = ResourceManager::GetInstance()->LoadTexture(L"MonsterTexture", L"Textures\\missile.bmp");
}

CMonster::~CMonster()
{

}

void CMonster::update()
{
	Vector2 curPos = GetPos();

	// 진행 방향으로 초당 _speed 만큼 이동
	curPos._x += _speed * _dir * DeltaTime_F;

	// 배회 거리 기준량을 넘어섰는지 확인

	float difDis = abs(_centerAnchor._x - curPos._x) - _loopDistance;

	if (0.f < difDis)
	{
		_dir *= -1;
		curPos._x += difDis * _dir;
	}

	if (GetMonsterId() % 2 == 0)
	{
		if (GetMissileFire())
		{
			SetMissileFire(false);
			CreateMonsterMissile();
		}
	}
	
	_acc += DeltaTime_F;

	if (_acc >= 0.99f)
	{
		SetMissileFire(true);
		_acc = 0.f;
	}
	else
		SetMissileFire(false);


	SetPos(curPos);
}

void CMonster::render(HDC dc)
{
	int width = static_cast<int>(_texture->GetWidth());
	int height = static_cast<int>(_texture->GetHeight());

	Vector2 pos = GetPos();

	TransparentBlt
	(
		dc,
		static_cast<int>(pos._x - static_cast<float>((width / 2))),
		static_cast<int>(pos._y - static_cast<float>((height / 2))),
		width,
		height,
		_texture->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255)
	);
}

void CMonster::CreateMonsterMissile()
{
	Vector2 monsterPos = GetPos();
	Vector2 monsterScale = GetScale();

	// 미사일 생성
	_missile = new MonsterMissile();

	// 미사일 크기
	_missile->SetScale(Vector2(monsterScale._x / 2.f, monsterScale._y / 2.f));

	// 미사일 위치
	monsterPos._y += (GetScale()._y / 2.f) + (_missile->GetScale()._y / 2.f);
	_missile->SetPos(monsterPos);

	//// 미사일 방향
	//_missile->SetTheta(90.f);
	//_missile->SetTheta(PI / 2.f);
	_missile->SetDir(Vector2{ 0.f, 1.f });

	CScene* curScene = CSceneManager::GetInstance()->GetcurScene();
	curScene->AddObject(_missile, GROUP_TYPE::MONSTERMISSILE);
	

}

