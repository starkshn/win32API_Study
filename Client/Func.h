#pragma once

class CObject;

void CreateObjectEvent(CObject* obj, GROUP_TYPE groupType);

void DeleteObjectEvent(CObject* objectPtr);

void ChangeScene(SCENE_TYPE changeSceneType);


template <typename T>
void SafeDeleteVector(vector<T>& vector)
{
	for (size_t i = 0; i < vector.size(); ++i)
	{
		if (nullptr != vector[i])
			delete vector[i];
	}
	vector.clear();
}

template <typename T1, typename T2>
void SafeDeleteMap(map<T1, T2>& map)
{
	auto iter = map.begin();
	// typename map<T1, T2>::iterator iter = map.begin(); // 중위순회
	
	for (; iter != map.end;)
	{
		if (nullptr != iter->second)
			delete iter->second;

		map.clear();
	}
}