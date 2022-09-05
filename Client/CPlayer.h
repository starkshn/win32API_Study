#pragma once
#include "CObject.h"
#include "CCharingMissile.h"

class CPlayer : public CObject
{
	virtual void update() override;

private:
	float _chargeMS = 1.f;

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