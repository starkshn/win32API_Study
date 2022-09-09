#include "pch.h"
#include "ColliderManager.h"

ColliderManager::ColliderManager()
{

}

ColliderManager::~ColliderManager()
{

}

void ColliderManager::update()
{
	



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

void ColliderManager::ResetGroup()
{

}
