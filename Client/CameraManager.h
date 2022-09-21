#pragma once

class CObject;

class CameraManager
{
	SINGLE(CameraManager);

private:
	Vector2		_lookAtPos; // ���� ī�޶�� ���� ��ġ
	Vector2		_corLookPos; // ������ġ�� ������ġ�� ������ġ
	Vector2		_prevLookPos; // ī�޶� ���� ���� ������ ��ġ
	Vector2		_diff; // �ػ� �߽���ġ��, ī�޶� LookAt���� ���̰�.

	CObject*	_targetObject; // ī�޶� Ÿ�� ������Ʈ
	
public:
	void update();

public:
	void CalDiff(); // ȭ�� �߾���ǥ�� LookAt ��ǥ���� ���̰����

public:
	void SetLookAtPos(Vector2 pos) { _lookAtPos = pos; };
	void SetTarget(CObject* target) { _targetObject = target; };

public:
	Vector2		GetLookPos() { return _corLookPos; }; // ���� �����ִ� ��ġ
	CObject*	GetTarget() { return _targetObject; };
	Vector2		GetRenderPos(Vector2 objPos) { return (objPos - _diff); }
	Vector2		GetRealPos(Vector2 renderPos) { return (renderPos + _diff); };
	
};

