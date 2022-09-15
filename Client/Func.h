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