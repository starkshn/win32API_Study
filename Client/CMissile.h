#pragma once
#include "CObject.h"
class CMissile : public CObject
{
private :
	float		_theta; // πÊ«‚
	Vector2  _dir;

public:
	CMissile();
	~CMissile();
public:
	void SetTheta(float theta) { _theta = theta; }
	void SetDir(Vector2 dir)
	{ 
		_dir = dir;
		_dir.Normalize();
	}

	float GetTheta() { return _theta; }

public:
	virtual void update() override;
	virtual void render(HDC dc) override;
};

