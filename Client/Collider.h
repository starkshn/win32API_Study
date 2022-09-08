#pragma once

class CObject;

class Collider
{
private:
	CObject* p_owner; // collider�� �����ϰ� �ִ� ������Ʈ
	Vector2 _offsetPos; // ������Ʈ�� ���� ������� ��ġ
	Vector2 _finalPos; // finalUpdate���� �� �����Ӹ��� ���
	Vector2 _colliderScale; // �浹ü ũ��
	
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

