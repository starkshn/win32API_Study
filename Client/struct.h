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
	Vector2 operator + (const Vector2& other)
	{
		return Vector2(_x + other._x, _y + other._y);
	}
	/*Vector2 operator += (const Vector2& other)
	{
		Vector2 temp = *this;
		temp = temp + other;
		return temp;
	}*/
	void operator += (const Vector2 other)
	{
		_x += other._x;
		_y += other._y;
	}
	Vector2 operator - (const Vector2& other)
	{
		return Vector2(_x - other._x, _y - other._y);
	}
	Vector2 operator * (const Vector2& other)
	{
		return Vector2(_x * other._x, _y * other._y);
	}
	Vector2 operator / (const Vector2& other)
	{
		assert(!(0.f == other._x || 0.f == other._y));
		return Vector2(_x / other._x, _y / other._y);
	}
	Vector2 operator / (const float& value)
	{
		assert(! (0.f == value) );
		return Vector2(_x / value, _y / value);
	}

	Vector2 operator * (int value)
	{
		return Vector2(_x * float(value), _y * float(value));
	}
	


};