#include "pch.h"
#include "ColliderManager.h"
#include "CSceneManager.h"
#include "CScene.h"
#include "CObject.h"

ColliderManager::ColliderManager()
{

}

ColliderManager::~ColliderManager()
{

}

void ColliderManager::update()
{
	for (UINT row = 0; row < static_cast<UINT>(GROUP_TYPE::END); ++row)
	{
		for (UINT col = row; col < static_cast<UINT>(GROUP_TYPE::END); ++col)
		{
			if (_arrCheck[row] & (1 << col))
			{
				CollisionGroupUpdate((GROUP_TYPE)row, (GROUP_TYPE)col);
			}
		}
	}

}

void ColliderManager::CollisionGroupUpdate(GROUP_TYPE left, GROUP_TYPE right)
{
	CScene* curScene = CSceneManager::GetInstance()->GetCurScene();
	const vector<CObject*>& vecLeft = curScene->GetGroupObjects(left);
	const vector<CObject*>& vecRight = curScene->GetGroupObjects(right);
	
	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		// 충돌체를 보유하지 않는 경우
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			// 충돌체를 보유하지 않는 경유 || 나 자신일 경우
			if (nullptr == vecRight[j]->GetCollider() || vecLeft[i] == vecRight[j])
				continue;
			
			// 진짜 충돌 검사
			if (IsCollision(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider()))
			{

			}
			else
			{

			}
		}
	}

}

bool ColliderManager::IsCollision(Collider* leftCol, Collider* rightCol)
{


	return false;
}


void ColliderManager::CheckGroup(GROUP_TYPE left, GROUP_TYPE right)
{
	// 더 작은 값의 그룹 타입을 행으로,
	// 더 큰 값을 열(비트) 로 사용한다.
	
	UINT row = static_cast<UINT>(left);
	UINT col = static_cast<UINT>(right);

	if (col < row)
	{
		row = static_cast<UINT>(col);
		col = static_cast<UINT>(row);
	}

	if (_arrCheck[row] & (1 << col))
		_arrCheck[row] &= ~(1 << col);
	else
		_arrCheck[row] |= (1 << col);

}


