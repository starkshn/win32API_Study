#pragma once

class CObject;

class Collider
{
private:
	CObject* p_owner; // collider를 소유하고 있는 오브젝트
	Vector2 _offsetPos; // 오브젝트로 부터 상대적인 위치
	Vector2 _finalPos; // finalUpdate에서 매 프레임마다 계산
	Vector2 _colliderScale; // 충돌체 크기
	
public:
	Collider();
	~Collider();

public:
	void finalUpdate();
	void render(HDC dc);

public:
	void SetOffsetPos(Vector2 pos) { _offsetPos = pos; }
	void SetColliderScale(Vector2 scale) { _colliderScale = scale; }

	Vector2 GetOffsetPos() { return _offsetPos; }
	Vector2 GetColliderScale() { return _colliderScale; }

	friend class CObject;
};

