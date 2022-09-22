#pragma once

class CObject;

class CameraManager
{
	SINGLE(CameraManager);

private:
	Vector2		_lookAtPos; // ���� ī�޶�� ���� ��ġ
	Vector2		_corLookPos; // ������ġ�� ������ġ�� ������ġ
	Vector2		_prevLookPos; // ī�޶� ���� ���� ������ ��ġ
	
	CObject*	_targetObject; // ī�޶� Ÿ�� ������Ʈ
	Vector2		_diff; // �ػ� �߽���ġ��, ī�޶� LookAt���� ���̰�.

	float		_getTargetTime = 2.f; // Ÿ���� ���󰡴µ� �ɸ��� �ð�
	float		_getTargetSpeed; // Ÿ���� ���󰡴� �ӵ�
	float		_accTime;	// �����ð�
	
public:
	void update();

public:
	void CalDiff(); // ȭ�� �߾���ǥ�� LookAt ��ǥ���� ���̰����

public:
	void SetLookAtPos(Vector2 pos) 
	{ 
		// ��ӵ� ����� �ӵ��� ����.
		_lookAtPos = pos;
		float moveDis = (_lookAtPos - _prevLookPos).Length();

		_getTargetSpeed = moveDis / _getTargetTime;
		_accTime = 0.f;
	}
	void SetTarget(CObject* target) { _targetObject = target; };

public:
	Vector2		GetLookPos() { return _corLookPos; } // ���� �����ִ� ��ġ
	CObject*	GetTarget() { return _targetObject; }
	// ������ ��ǥ
	Vector2		GetRenderPos(Vector2 objPos) { return (objPos - _diff); }
	// ���� ��ǥ
	Vector2		GetRealPos(Vector2 renderPos) { return (renderPos + _diff); }
	
};

