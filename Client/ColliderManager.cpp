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
		// �浹ü�� �������� �ʴ� ���
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			// �浹ü�� �������� �ʴ� ���� || �� �ڽ��� ���
			if (nullptr == vecRight[j]->GetCollider() || vecLeft[i] == vecRight[j])
				continue;
			
			// ��¥ �浹 �˻�
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
	// �� ���� ���� �׷� Ÿ���� ������,
	// �� ū ���� ��(��Ʈ) �� ����Ѵ�.
	
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


