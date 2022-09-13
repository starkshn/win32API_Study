#pragma once

class CObject;

class Collider
{
private:
	static UINT g_ID;

	UINT _ID = 0; // �浹ü�� ������ ID��
	
	CObject* p_owner; // collider�� �����ϰ� �ִ� ������Ʈ

	Vector2 _offsetPos; // ������Ʈ�� ���� ������� ��ġ
	Vector2 _finalPos; // finalUpdate���� �� �����Ӹ��� ���
	Vector2 _colliderScale; // �浹ü ũ��

	UINT	_colCount;

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
	Vector2 GetFinalPos() { return _finalPos ; }
	UINT GetID() { return _ID; }
	CObject* GetOwner() { return p_owner; }
	
	friend class CObject;
};

//UINT Collider::g_ID = 0;

