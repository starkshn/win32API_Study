#pragma once
class CObject
{
private :
	float		_theta; // πÊ«‚
	Vector2		_dir;

	Vector2 _pos;
	Vector2 _scale;

public:
	CObject();
	virtual ~CObject();

public :
	void SetPos(Vector2 pos) { _pos = pos; }
	void SetScale(Vector2 scale) { _scale = scale; }

	Vector2 GetPos() { return _pos; }
	Vector2 GetScale() { return _scale; }

	void SetTheta(float theta) { _theta = theta; }
	void SetDir(Vector2 dir)
	{
		_dir = dir;
		_dir.Normalize();
	}

	float GetTheta() { return _theta; }
	Vector2 GetVector2Dir() { return _dir; }

public :
	virtual void update() abstract;
	virtual void render(HDC dc);

};

