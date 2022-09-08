#pragma once

class Collider;

class CObject
{
private :
	float		_theta; // πÊ«‚
	Vector2		_dir;
	Vector2		_pos;
	Vector2		_scale;
	Collider*	p_collider;

public:
	CObject();
	virtual ~CObject();

public:
	virtual void update() abstract;
	virtual void finalUpdate() final;
	virtual void render(HDC dc);
	void ComponentRender(HDC dc);
	void CreateCollider();

public :
	void SetPos(Vector2 pos) { _pos = pos; }
	void SetScale(Vector2 scale) { _scale = scale; }
	void SetTheta(float theta) { _theta = theta; }
	void SetDir(Vector2 dir) { _dir = dir; _dir.Normalize(); }
	
	Vector2 GetPos() { return _pos; }
	Vector2 GetScale() { return _scale; }
	float GetTheta() { return _theta; }
	Vector2 GetVector2Dir() { return _dir; }


};

