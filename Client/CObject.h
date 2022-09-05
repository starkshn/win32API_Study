#pragma once
class CObject
{
private :
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

public :
	virtual void update() abstract;
	virtual void render(HDC dc);

};

