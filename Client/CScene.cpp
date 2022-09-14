#include "pch.h"
#include "CScene.h"
#include "CObject.h"
#include "CCore.h"

CScene::CScene()
{
	
}

CScene::~CScene()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(GROUP_TYPE::END); ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			if (nullptr != _objects[i][j])
				delete _objects[i][j];
		}
	}
}

void CScene::update()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(GROUP_TYPE::END); ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			if (!_objects[i][j]->IsDead())
			{
				_objects[i][j]->update();
			}
		}
	}
}

void CScene::finalUpdate()
{
	for (UINT i = 0; i < static_cast<UINT>(GROUP_TYPE::END); ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			_objects[i][j]->finalUpdate();
		}
	} 
}

void CScene::render(HDC dc)
{	
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		vector<CObject*>::iterator iter = _objects[i].begin();
		// auto iter = _objects[i].begin();

		for (iter = _objects[i].begin(); iter != _objects[i].end();)
		{
			if (!(*iter)->IsDead())
			{
				(*iter)->render(dc);
				++iter;
			}
			else
			{
 				iter = _objects[i].erase(iter);
			}
		}
	}
}




