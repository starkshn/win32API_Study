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
	// Object의 위치를 따라간다.
	// 따라간다기 보다 바로 위치를 설정한다.
	Vector2 objectPos = p_owner->GetPos();
	_finalPos = objectPos + _offsetPos;
}

void Collider::render(HDC dc)
{
	// finalUpdate끝나고 render작업 시작한다.
}
