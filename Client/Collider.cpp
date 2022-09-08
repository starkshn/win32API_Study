#include "pch.h"
#include "Collider.h"
#include "CObject.h"
#include "CCore.h"
#include "SelectGDI.h"

Collider::Collider() : p_owner(nullptr)
{

}
Collider::~Collider()
{

}

void Collider::finalUpdate()
{
	// Object�� ��ġ�� ���󰣴�.
	// ���󰣴ٱ� ���� �ٷ� ��ġ�� �����Ѵ�.
	Vector2 objectPos = p_owner->GetPos();
	_finalPos = objectPos + _offsetPos;
}

void Collider::render(HDC dc)
{
	SelectGDI b(dc, HBRUSH_TYPE::HOLLOW);
	SelectGDI p(dc, HPEN_TYPE::GREEN);

	Rectangle
	(
		dc,
		static_cast<int>(_finalPos._x - _colliderScale._x / 2.f),
		static_cast<int>(_finalPos._y - _colliderScale._y / 2.f),
		static_cast<int>(_finalPos._x + _colliderScale._x / 2.f),
		static_cast<int>(_finalPos._y + _colliderScale._y / 2.f)
	);
}
