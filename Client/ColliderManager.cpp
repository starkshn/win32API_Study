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

void ColliderManager::ResetGroup()
{

}
