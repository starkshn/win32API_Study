#include "pch.h"
#include "Collider.h"
#include "CObject.h"
#include "CCore.h"
#include "SelectGDI.h"

Collider::Collider() : _id(g_id++), p_owner(nullptr)
{

}

Collider::Collider(const Collider& origin) 
	: 
	_id(g_id++),
	p_owner(nullptr),
	_offsetPos(origin._offsetPos),
	_colliderScale(origin._colliderScale)
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

void Collider::OnCollisonStay(Collider* other)
{

}


void Collider::OnCollisionEnter(Collider* other)
{

}

void Collider::OnCollisionExit(Collider* other)
{

}
