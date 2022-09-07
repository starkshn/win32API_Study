#pragma once
#include "CObject.h"
#include "CCharingMissile.h"

class Texture;

class CPlayer : public CObject
{
private:
	float _chargeMS = 1.f;
	Texture* _myObject;

public :
	CPlayer();
	~CPlayer();

public:
	virtual void update() final;
	virtual void render(HDC dc) final;

public :
	void CreateMissile();
	void CreateThreeMissile();

	void ChargingMissile();
	void ShootMissile();

public :

	void SetChargeMS(float value) { _chargeMS = value; }
	void AccChargeMS(float value) { _chargeMS += value; }

	float GetChargeMS() { return _chargeMS; }

};