#include "pch.h"
#include "CObject.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "Collider.h"

CObject::CObject() 
	: 
	_pos{},
	_scale{},
	p_collider(nullptr),
	p_animator(nullptr),
	_alive(true)
{

}

CObject::CObject(const CObject& origin)
	:
	_objectName(origin._objectName),
	_pos(origin._pos),
	_scale(origin._scale),
	p_collider(nullptr),
	p_animator(nullptr),
	_alive(true)
{
	// Collider있는 경우만 복사를 받는다.
	if (origin.p_collider)
	{
		p_collider = new Collider(*origin.p_collider);
		p_collider->p_owner = this;
	}
	
	// TODO : Animator 깊은복사
}

CObject::~CObject()
{
	if (nullptr != p_collider)
		delete p_collider;

	if (nullptr != p_animator)
		delete p_animator;
	
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
