#pragma once
class ColliderManager
{
	SINGLE(ColliderManager)

private:
	// �浹ü���� ���� �������� �浹 ����
	UINT _arrCheck[static_cast<UINT>(GROUP_TYPE::END)]; // �׷찣�� �浹 ��Ʈ����
	

public:
	void update();
	void CheckGroup(GROUP_TYPE left, GROUP_TYPE right);
	void ResetGroup()
	{
		memset(_arrCheck, 0, sizeof(UINT) * static_cast<UINT>(GROUP_TYPE::END));
	}
private:
	void CollisionGroupUpdate(GROUP_TYPE left, GROUP_TYPE right);
	bool IsCollision(Collider* leftCol, Collider* rightCol);
};

