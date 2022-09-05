#pragma once
#include "CObject.h"
#include "CMissile.h"

class CPlayer;

class ThreeMissile : public CMissile
{
private:
	int			_id = 0;

public:
	ThreeMissile();
	~ThreeMissile();
public:
	void SetId(int id) { _id = id; }
	int GetId() { return _id; }

public:
	virtual void update() override;
	virtual void render(HDC dc) override;

};

