#pragma once
#include "CObject.h"

class Texture;

class CMissile : public CObject
{
private :
	Texture* p_cMissileTexture;

public:
	CMissile();
	~CMissile();
public:

public:
	virtual void update() override;
	virtual void render(HDC dc) override;
};

