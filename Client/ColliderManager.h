#pragma once
class ColliderManager
{
	SINGLE(ColliderManager)

private:
	// 충돌체간의 이전 프레임의 충돌 정보
	UINT _arrCheck[static_cast<UINT>(GROUP_TYPE::END)]; // 그룹간의 충돌 메트릭스
	

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

