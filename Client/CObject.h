#pragma once

class Collider;

class CObject
{
private :
	wstring		_objectName;

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

};

