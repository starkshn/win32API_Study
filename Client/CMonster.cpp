#include "pch.h"
#include "CMonster.h"
#include "CTimeManager.h"
#include "CMissile.h"
#include "CScene.h"
#include "CSceneManager.h"
#include "MonsterMissile.h"
#include "CCore.h"
#include "ResourceManager.h"

CMonster::CMonster() 
	: 
	_speed(100.f), 
	_loopDistance(50.f),
	_centerAnchor{0.f, 0.f},
	_missile(nullptr),
	_dir(1)
{
	_texture = ResourceManager::GetInstance()->LoadTexture(L"MonsterTexture", L"Textures\\monsterPlane.bmp");
}

CMonster::~CMonster()
{

}

void CMonster::update()
{
	Vector2 curPos = GetPos();

	// ���� �������� �ʴ� _speed ��ŭ �̵�
	curPos._x += _speed * _dir * DeltaTime_F;

	// ��ȸ �Ÿ� ���ط��� �Ѿ���� Ȯ��

	float difDis = abs(_centerAnchor._x - curPos._x) - _loopDistance;

	if (0.f < difDis)
	{
		_dir *= -1;
		curPos._x += difDis * _dir;
	}

	if (GetMonsterId() % 2 == 0)
	{
		if (GetMissileFire() == false)
		{
			CreateMonsterMissile();
		}
		
		Vector2 missilePos = _missile->GetPos();

		missilePos._y += 600.f * (PI / 2.f) * DeltaTime_F;
		missilePos._x += 600.f * (PI / 2.f) * DeltaTime_F;

		if (missilePos._y > CCore::GetInstance()->GetResolution().y)
		{
			SetMissileFire(false);
		}
		
		SetPos(missilePos);
	}

	SetPos(curPos);
}

void CMonster::render()
{
	/*int width = static_cast<int>(_texture->GetWidth());
	int height = static_cast<int>(_texture->GetHeight());

	Vector2 pos = GetPos();*/



}

void CMonster::CreateMonsterMissile()
{
	SetMissileFire(true);

	if (GetMissileFire())
	{
		Vector2 monsterPos = GetPos();
		Vector2 monsterScale = GetScale();

		// �̻��� ����
		_missile = new MonsterMissile();

		// �̻��� ũ��
		_missile->SetScale(Vector2(monsterScale._x / 2.f, monsterScale._y / 2.f));

		// �̻��� ��ġ
		monsterPos._y += (GetScale()._y / 2.f) + (_missile->GetScale()._y / 2.f);
		_missile->SetPos(monsterPos);

		//// �̻��� ����
		//_missile->SetTheta(90.f);
		_missile->SetTheta(PI / 2.f);

		CScene* curScene = CSceneManager::GetInstance()->GetcurScene();
		curScene->AddObject(_missile, GROUP_TYPE::MONSTERMISSILE);
	}

}

