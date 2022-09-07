#pragma once
#include "CObject.h"
class CMissile : public CObject
{
private :
	
public:
	CMissile();
	~CMissile();
public:

public:
	virtual void update() override;
	virtual void render(HDC dc) override;
};

