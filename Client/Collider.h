#pragma once

class CObject;

class Collider
{
private:
	static UINT g_id;

	UINT _id; // �浹ü�� ������ ID��
	
	CObject* p_owner; // collider�� �����ϰ� �ִ� ������Ʈ
	Vector2 _offsetPos; // ������Ʈ�� ���� ������� ��ġ
	Vector2 _finalPos; // finalUpdate���� �� �����Ӹ��� ���
	Vector2 _colliderScale; // �浹ü ũ��

public:
	Collider();
	Collider(const Collider& origin);
	~Collider();

public:
	void finalUpdate();
	void render(HDC dc);

public :
	// �浹 ���� �Լ�.
	void OnCollisonStay(Collider* other); // �浹���� ��� ȣ��Ǵ� �Լ�.
	void OnCollisionEnter(Collider* other);
	void OnCollisionExit(Collider* other);

	Collider& operator = (const Collider& other) = delete;

public:
	void SetOffsetPos(Vector2 pos) { _offsetPos = pos; }
	void SetColliderScale(Vector2 scale) { _colliderScale = scale; }

	Vector2 GetOffsetPos() { return _offsetPos; }
	Vector2 GetColliderScale() { return _colliderScale; }
	UINT GetID() { return _id; }

	friend class CObject;
};

UINT Collider::g_id = 0;