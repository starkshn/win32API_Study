#pragma once
#include "CObject.h"
#include "CCharingMissile.h"
#include "Collider.h"

class Texture;

class CPlayer : public CObject
{
private:
	Texture*	p_myObject;

public :
	CPlayer();
	~CPlayer();

public:
	virtual void update() final;
	virtual void render(HDC dc) final;

public :
	void CreateMissile();
	void CreateThreeMissile();

public :

};