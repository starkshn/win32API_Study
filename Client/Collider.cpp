#include "pch.h"
#include "Collider.h"
#include "CObject.h"

Collider::Collider()
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
	// finalUpdate������ render�۾� �����Ѵ�.
}
