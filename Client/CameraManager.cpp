#include "pch.h"
#include "CameraManager.h"
#include "CObject.h"
#include "CCore.h"

CameraManager::CameraManager()
	:
	_lookAtPos{},
	_targetObject()
{

}

CameraManager::~CameraManager()
{

}

void CameraManager::update()
{
	if (_targetObject)
	{
		if (_targetObject->IsDead())
			_targetObject = nullptr;
		else
		{
			_lookAtPos = _targetObject->GetPos();
		}
	}

	// È­¸é Áß¾ÓÁÂÇ¥¿Í LookAt ÁÂÇ¥°£ÀÇ Â÷ÀÌ°ª°è»ê
	CalDiff();
}

void CameraManager::CalDiff()
{
	Vector2 resolution = CCore::GetInstance()->GetResolution();
	Vector2 centerPos = resolution / 2.f;

	_diff = _lookAtPos - centerPos;

}

