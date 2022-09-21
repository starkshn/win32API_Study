#pragma once

class CObject;

class CameraManager
{
	SINGLE(CameraManager);

private:
	Vector2		_lookAtPos; // 실제 카메라고 보는 위치
	Vector2		_prevLookPos; // 카메라가 보는 이전 프레임 위치
	Vector2		_diff; // 해상도 중심위치와, 카메라 LookAt간의 차이값.

	CObject*	_targetObject; // 카메라 타겟 오브젝트
	
public:
	void update();

public:
	void CalDiff(); // 화면 중앙좌표와 LookAt 좌표간의 차이값계산

public:
	void SetLookAtPos(Vector2 pos) { _lookAtPos = pos; };
	void SetTarget(CObject* target) { _targetObject = target; };

public:
	Vector2		GetLookPos() { return _lookAtPos; };
	CObject*	GetTarget() { return _targetObject; };
	Vector2		GetRenderPos(Vector2 objPos) { return (objPos - _diff); }
	Vector2		GetRealPos(Vector2 renderPos) { return (renderPos + _diff); };
	
};

