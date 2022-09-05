#include "pch.h"
#include "ThreeMissile.h"
#include "CTimeManager.h"
#include "CPlayer.h"
#include "CMissile.h"

ThreeMissile::ThreeMissile()
{

}

ThreeMissile::~ThreeMissile()
{

}

void ThreeMissile::update()
{
	Vector2 myPos = GetPos();

	if ((GetId() % 3) == 0) 
	{
		SetTheta(PI / 2.f);
		myPos._y -= 600.f * sinf(GetTheta()) * DeltaTime_F;
		myPos._x += 600.f * cosf(GetTheta()) * DeltaTime_F;
	}
	else if ((GetId() % 3) == 1)
	{
		SetTheta(PI / 4.f * 3);
		myPos._y -= 600.f * sinf(GetTheta()) * DeltaTime_F;
		myPos._x += 600.f * cosf(GetTheta()) * DeltaTime_F;
	}
	else if ((GetId() % 3) == 2)
	{
		SetTheta(PI / 4.f);
		myPos._y -= 600.f * sinf(GetTheta()) * DeltaTime_F;
		myPos._x += 600.f * cosf(GetTheta()) * DeltaTime_F;
	}

	SetPos(myPos);
}

void ThreeMissile::render(HDC dc)
{
	Vector2 pos = GetPos();
	Vector2 scale = GetScale();
	Ellipse
	(dc,
		static_cast<int>(pos._x - scale._x / 2.f),
		static_cast<int>(pos._y - scale._y / 2.f),
		static_cast<int>(pos._x + scale._x / 2.f),
		static_cast<int>(pos._y + scale._y / 2.f)
	);
}