#include "pch.h"
#include "CObject.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "Collider.h"

CObject::CObject() 
	: 
	_pos{},
	_scale{},
	p_collider(nullptr)
{


}
CObject::~CObject()
{
	if (nullptr != p_collider)
		delete p_collider;
}

void CObject::finalUpdate()
{
	if (p_collider != nullptr)
	{
		p_collider->finalUpdate();
	}
}

void CObject::render(HDC dc)
{
	Rectangle
	(dc,
		static_cast<int>(_pos._x - _scale._x / 2.f),
		static_cast<int>(_pos._y - _scale._y / 2.f),
		static_cast<int>(_pos._x + _scale._x / 2.f),
		static_cast<int>(_pos._y + _scale._y / 2.f)
	);

	ComponentRender(dc);
}

void CObject::ComponentRender(HDC dc)
{
	if (nullptr != p_collider)
		p_collider->render(dc);
}

void CObject::CreateCollider()
{
	p_collider = new Collider;
	p_collider->p_owner = this;
}
