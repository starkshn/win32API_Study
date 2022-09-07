#pragma once
#include "CObject.h"
#include "CMonster.h"

class Texture;

class MonsterMissile : public CMonster
{
private:
private:
	float		_theta; // ����
	Vector2		_dir;   // Vector
	Texture* _monsterMissileTexture;

public:
	MonsterMissile();
	~MonsterMissile();
public:
	
private:
	virtual void update() final;
	virtual void render(HDC dc) final;

};

