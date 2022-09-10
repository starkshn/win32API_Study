#pragma once
#include "CObject.h"
#include "CTimeManager.h"

class MonsterMissile;
class Texture;

class CMonster : public CObject
{
private :
	float			_speed;
	float			_loopDistance;
	float			_acc;
	int				_dir; // 1, -1
	int				_id;
	bool			_missileFire = true;
	Vector2			_centerAnchor;

	MonsterMissile*	_missile = nullptr;
	Texture* _texture;
	Texture* _missileTexture;

public :
	CMonster();
	~CMonster();

public :
	virtual void update() override;
	virtual void render(HDC dc) override;

public:
	void CreateMonsterMissile();

	void MissileCoroutine(float deltaTime_f)
	{
		SetAcc(deltaTime_f);
		
		if (GetAcc() > 1.f)
		{
			SetMissileFire(true);
			SetAcc(0.f);
		}
		else
		{
			SetMissileFire(false);
		}
	}

public:
	void SetSpeed(float speed) { _speed = speed; }
	void SetCenterAnchor(Vector2 anchor) { _centerAnchor = anchor; }
	void SetLoopDistance(float loopDis) { _loopDistance = loopDis; }
	void SetMoveDistance(float dis) { _loopDistance = dis; }
	void SetMonsterId(int id) { _id = id; }
	void SetMissileFire(bool fire) { _missileFire = fire; }
	void SetAcc(float deltaTime) { _acc += deltaTime; }
	
	float GetSpeed() { return _speed; }
	Vector2 GetCenterAnchor() { return _centerAnchor; }
	float GetLoopDistance() { return _loopDistance; }
	int GetMonsterId() { return _id; }
	bool GetMissileFire() { return _missileFire; }
	float GetAcc() { return _acc; }
};

