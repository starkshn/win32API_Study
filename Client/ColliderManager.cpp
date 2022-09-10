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
		// �浹ü�� �������� �ʴ� ���
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			// �浹ü�� �������� �ʴ� ���� || �� �ڽ��� ���
			if (nullptr == vecRight[j]->GetCollider() || vecLeft[i] == vecRight[j])
				continue;
			
			Collider* leftCollider = vecLeft[i]->GetCollider();
			Collider* rightCollider = vecRight[j]->GetCollider();


			// �� �浹ü ���� ���̵� ����
			COLLIDER_ID id;
			id._leftID = leftCollider->GetID();
			id._rightID = rightCollider->GetID();

			// auto iter = _mapCollisionInfo.find(id.ID);
			iter = _mapCollisionInfo.find(id.ID);

			// �浹 ������ �� ��� ������ ��� ��� (�浹���� �ʾҴ� ��)
			if (_mapCollisionInfo.end() == iter)
			{
				_mapCollisionInfo.insert(make_pair(id.ID, false));
				iter = _mapCollisionInfo.find(id.ID);
			}
			
			// ��¥ �浹 �˻�
			if (IsCollision(leftCollider, rightCollider))
			{
				// ���� �浹 ���̴�.
				
				if (iter->second)
				{
					// �������� �浹�ϰ� �־���. Stay
					leftCollider->OnCollisonStay(rightCollider);
					rightCollider->OnCollisonStay(leftCollider);
				}
				else
				{
					// �������� �浹���� �ʾҴ�. (�� ó�� �浹�� ���) Enter
					leftCollider->OnCollisionEnter(rightCollider);
					rightCollider->OnCollisionEnter(leftCollider);
					iter->second = true;
				}
			}
			else
			{
				// ���� �浹�� ���� �ʴ�.
				if (iter->second)
				{
					// �������� �浹�ϰ� �־���. Exit
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


