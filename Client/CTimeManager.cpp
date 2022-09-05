#include "pch.h"
#include "CTimeManager.h"
#include "CCore.h"

CTimeManager::CTimeManager()
	:
	_curCount {},
	_frequency{},
	_callCount{},
	_deltaTime(0),
	_acc(0),
	_fps(0)
{

}

CTimeManager::~CTimeManager()
{
	
}

void CTimeManager::init()
{
	// ���� ī��Ʈ
	QueryPerformanceCounter(&_prevCount);

	// �ʴ� ī��Ʈ Ƚ��
	QueryPerformanceFrequency(&_frequency);

}

void CTimeManager::update() 
{
	QueryPerformanceCounter(&_curCount);

	// ���� �������� ī���ð�, ���� ������ ī���� ���� ���̸� ���Ѵ�.
	_deltaTime = static_cast<double>(_curCount.QuadPart - _prevCount.QuadPart) / static_cast<double>(_frequency.QuadPart);

	// ���� ī��Ʈ ���� ���� ������ ����(�������� ����� ���ؼ�)
	_prevCount = _curCount;

	++_callCount; // 1�ʰ� �� ������ ���� �˾ƾ��Ѵ�.
	_acc += _deltaTime; // DT����

	if (_acc >= 1.)
	{
		_fps = _callCount;
		_acc = 0;
		_callCount = 0;

		wchar_t buffer[255] = {};
		swprintf_s(buffer, L"FPS : %d, DT : %f", _fps, _deltaTime);
		SetWindowText(CCore::GetInstance()->GetMainHwnd(), buffer);
	}

}
