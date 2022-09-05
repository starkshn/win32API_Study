#pragma once
#include "CObject.h"
#include "CMissile.h"

class MonsterMissile : public CMissile
{
private:
	float		_dir; // 위 아래 방향

public:
	MonsterMissile();
	~MonsterMissile();
public:

private:
	virtual void update() override;
	virtual void render(HDC dc) override;

};

