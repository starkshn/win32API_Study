#pragma once
class CTimeManager
{
	SINGLE(CTimeManager);
private :
	LARGE_INTEGER _curCount;
	LARGE_INTEGER _prevCount;
	LARGE_INTEGER _frequency;
	// FPS
	// 1 �����Ӵ� �ð� (Delta Time)

	double			_deltaTime; // ������ ���� �ð���.
	double			_acc; // 1�� üũ�� ���� �����ð�.
	UINT				_callCount; // update ȣ�� Ƚ�� üũ
	UINT				_fps; // �ʴ� ȣ�� Ƚ��
	

public :
	void init();
	void update();
	void render();

public :
	double GetDeltaTime() { return _deltaTime; }
	float GetfDeltaTime() { return static_cast<float>(_deltaTime); }
	double GetAccTime() { return _acc; }

};

 