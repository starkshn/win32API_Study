#include "pch.h"
#include "CMissile.h"
#include "CTimeManager.h"

CMissile::CMissile() : _theta(PI / 4.f), _dir(Vector2{1.f, 1.f})
{
	_dir.Normalize();
}
CMissile::~CMissile()
{

}

void CMissile::update()
{
	Vector2 pos = GetPos();

	pos._x += 600.f * cosf(_theta) * DeltaTime_F;
	pos._y -= 600.f * sinf(_theta) * DeltaTime_F;

	// pos._x += 600.f * _dir._x * DeltaTime_F;
	// pos._y += 600.f * _dir._y * DeltaTime_F;

	SetPos(pos);
}

void CMissile::render(HDC dc)
{
	Vector2 pos = GetPos();
	Vector2 scale = GetScale();
	Ellipse
	(	dc,
		static_cast<int>(pos._x - scale._x / 2.f),
		static_cast<int>(pos._y - scale._y / 2.f),
		static_cast<int>(pos._x + scale._x / 2.f),
		static_cast<int>(pos._y + scale._y / 2.f)
	);
}



