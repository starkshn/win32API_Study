#pragma once
#include "CObject.h"
#include "CMissile.h"

class MonsterMissile : public CMissile
{
private:
	float		_dir; // �� �Ʒ� ����

public:
	MonsterMissile();
	~MonsterMissile();
public:

private:
	virtual void update() override;
	virtual void render(HDC dc) override;

};

