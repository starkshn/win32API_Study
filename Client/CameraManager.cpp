#include "pch.h"
#include "CameraManager.h"
#include "CObject.h"
#include "CCore.h"
#include "CKeyManager.h"
#include "CTimeManager.h"

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

	// camera이동 테스트
	if (KEY_HOLD(KEY::UP))
		_lookAtPos._y -= 500.f * DeltaTime_F;
	if (KEY_HOLD(KEY::DOWN))
		_lookAtPos._y += 500.f * DeltaTime_F;
	if (KEY_HOLD(KEY::LEFT))
		_lookAtPos._x -= 500.f * DeltaTime_F;
	if (KEY_HOLD(KEY::RIGHT))
		_lookAtPos._x += 500.f * DeltaTime_F;

	
	// 화면 중앙좌표와 LookAt 좌표간의 차이값계산
	CalDiff();
}

void CameraManager::CalDiff()
{
	// prevLookAt과 현재 LootAt 의 차이값을 보정해서 현재의 LooAt의 구한다.

	Vector2 resolution = CCore::GetInstance()->GetResolution();
	Vector2 centerPos = resolution / 2.f;

	_diff = _lookAtPos - centerPos;

}

