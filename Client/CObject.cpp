#include "pch.h"
#include "CObject.h"
#include "CKeyManager.h"
#include "CTimeManager.h"


CObject::CObject() 
	: 
	_pos{},
	_scale{}
{


}
CObject::~CObject()
{


}

void CObject::render(HDC dc)
{
	Rectangle
	(	dc,
		static_cast<int>(_pos._x - _scale._x / 2.f), 
		static_cast<int>(_pos._y - _scale._y / 2.f),
		static_cast<int>(_pos._x + _scale._x / 2.f),
		static_cast<int>(_pos._y + _scale._y / 2.f) 
	);
}
