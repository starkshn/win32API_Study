#pragma once

class Collider;

class CObject
{
private :
	wstring		_objectName;

	float		_theta; // 방향

	Vector2		_dir;
	Vector2		_pos;
	Vector2		_scale;

	Collider*	p_collider;

	bool		_alive;
	
public:
	CObject();
	virtual ~CObject();

	friend class EventManager;

public:
	virtual void update() abstract;
	virtual void finalUpdate() final;
	virtual void render(HDC dc);

	void SetDead() { _alive = false; } // 이벤트 처리를 위해서만 사용할 함수

public:
	void ComponentRender(HDC dc);
	void CreateCollider();
	
	virtual void OnCollisionEnter(Collider* other) {}
	virtual void OnCollisionStay(Collider* other) {}
	virtual void OnCollisionExit(Collider* other) {}

public :
	void SetPos(Vector2 pos) { _pos = pos; }
	void SetScale(Vector2 scale) { _scale = scale; }
	void SetTheta(float theta) { _theta = theta; }
	void SetDir(Vector2 dir) { _dir = dir; _dir.Normalize(); }
	void SetObjectName(const wstring& name) { _objectName = name; }


	Vector2 GetPos() { return _pos; }
	Vector2 GetScale() { return _scale; }
	Vector2 GetVector2Dir() { return _dir; }
	float GetTheta() { return _theta; }
	Collider* GetCollider() { return p_collider; }

	const wstring& GetObjectName() { return _objectName; }

	bool IsDead() { return !_alive; }

};

