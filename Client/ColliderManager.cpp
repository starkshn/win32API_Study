#include "pch.h"
#include "ColliderManager.h"
#include "CSceneManager.h"
#include "CScene.h"
#include "CObject.h"
#include "Collider.h"

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
	map<ULONGLONG, bool>::iterator iter;

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
			
			Collider* leftCollider = vecLeft[i]->GetCollider();
			Collider* rightCollider = vecRight[j]->GetCollider();


			// 두 충돌체 조합 아이디 생성
			COLLIDER_ID id;
			id._leftID = leftCollider->GetID();
			id._rightID = rightCollider->GetID();

			// auto iter = _mapCollisionInfo.find(id.ID);
			iter = _mapCollisionInfo.find(id.ID);

			// 충돌 정보가 미 등록 상태인 경우 등록 (충돌하지 않았다 로)
			if (_mapCollisionInfo.end() == iter)
			{
				_mapCollisionInfo.insert(make_pair(id.ID, false));
				iter = _mapCollisionInfo.find(id.ID);
			}
			
			// 진짜 충돌 검사
			if (IsCollision(leftCollider, rightCollider))
			{
				// 현재 충돌 중이다.
				
				if (iter->second)
				{
					// 이전에도 충돌하고 있었다. Stay
					leftCollider->OnCollisonStay(rightCollider);
					rightCollider->OnCollisonStay(leftCollider);
				}
				else
				{
					// 이전에는 충돌하지 않았다. (딱 처음 충돌한 경우) Enter
					leftCollider->OnCollisionEnter(rightCollider);
					rightCollider->OnCollisionEnter(leftCollider);
					iter->second = true;
				}
			}
			else
			{
				// 현재 충돌중 이지 않다.
				if (iter->second)
				{
					// 이전에는 충돌하고 있었다. Exit
					leftCollider->OnCollisionExit(rightCollider);
					rightCollider->OnCollisionExit(leftCollider);
					iter->second = false;
				}
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


