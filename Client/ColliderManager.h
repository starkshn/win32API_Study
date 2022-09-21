#pragma once

class Collider;

union COLLIDER_ID
{
	struct
	{
		UINT _leftID;
		UINT _rightID;
	};

	ULONGLONG ID;
};

class ColliderManager
{
private:
	SINGLE(ColliderManager)

	// �浹ü���� ���� �������� �浹 ����
	map<ULONGLONG, bool> _mapCollisionInfo;

	UINT _arrCheck[static_cast<UINT>(GROUP_TYPE::END)]; // �׷찣�� �浹 ��Ʈ����

private:
	void CollisionGroupUpdate(GROUP_TYPE left, GROUP_TYPE right);
	bool IsCollision(Collider* leftCol, Collider* rightCol);
	
public:
	void update();
	void CheckGroup(GROUP_TYPE left, GROUP_TYPE right);
	void ResetGroup()
	{
		memset(_arrCheck, 0, sizeof(UINT) * static_cast<UINT>(GROUP_TYPE::END));
	}

};

