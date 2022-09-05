#pragma once
#include <assert.h>

struct Vector2
{
	float _x;
	float _y;


public :
	Vector2()
		:
		_x(0.f),
		_y(0.f)
	{}
	Vector2(float x, float y)
		:
		_x(x),
		_y(y)
	{}
	Vector2(int x, int y)
		:
		_x(float(x)),
		_y(float(y))
	{}
	Vector2(const POINT& pt) : 
		_x(static_cast<float>(pt.x)), _y(static_cast<float>(pt.y))
	{}

public :
	float Length()
	{
		return sqrt(_x * _x + _y * _y);
	}

	Vector2& Normalize()
	{
		float len = Length();

		assert(len != 0.f);

		_x /= len;
		_y /= len;

		return *this;
	}

public :
	Vector2& operator = (POINT& pt)
	{
		_x = static_cast<float>(pt.x);
		_y = static_cast<float>(pt.y);
	}

};