#pragma once
#include "CObject.h"

class MonsterMissile;
class Texture;

class CMonster : public CObject
{
private :
	float					_speed;
	float					_loopDistance;
	Vector2				_centerAnchor;
	int						_dir; // 1, -1
	int						_id;
	bool					_missileFire = false;
	MonsterMissile*	_missile = nullptr;
	Texture* _texture;
public :
	CMonster();
	~CMonster();

public :
	virtual void update() final;
	virtual void render() final;

public:
	void CreateMonsterMissile();

public:
	void SetSpeed(float speed) { _speed = speed; }
	void SetCenterAnchor(Vector2 anchor) { _centerAnchor = anchor; }
	void SetLoopDistance(float loopDis) { _loopDistance = loopDis; }
	void SetMoveDistance(float dis) { _loopDistance = dis; }
	void SetMonsterId(int id) { _id = id; }
	void SetMissileFire(bool fire) { _missileFire = fire; }

	float GetSpeed() { return _speed; }
	Vector2 GetCenterAnchor() { return _centerAnchor; }
	float GetLoopDistance() { return _loopDistance; }
	int GetMonsterId() { return _id; }
	bool GetMissileFire() { return _missileFire; }
};

