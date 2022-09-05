#include "pch.h"
#include "MonsterMissile.h"
#include "CMissile.h"
#include "CTimeManager.h"

MonsterMissile::MonsterMissile()
{
	SetTheta(PI / 2.f);
}

MonsterMissile::~MonsterMissile()
{
	
}

void MonsterMissile::update()
{
	Vector2 pos = GetPos();

	pos._x += 600.f * GetTheta() * DeltaTime_F;
	pos._y -= 600.f * GetTheta() * DeltaTime_F;

	SetPos(pos);
}

void MonsterMissile::render(HDC dc)
{

}