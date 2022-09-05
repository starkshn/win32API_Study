#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"

CCore::CCore()
	:
	_hWnd(0),
	_resolution{},
	_hDC(0),
	_hBitmap(0),
	_memDC(0)
{}

CCore::~CCore()
{
	ReleaseDC(_hWnd, _hDC);

	DeleteDC(_memDC);
	DeleteObject(_hBitmap);
}

int CCore::init(HWND hWnd, POINT resolution)
{
	_hWnd = hWnd;
	_resolution = resolution;

	// �ػ󵵿� �°� ������ ũ�� ����
	RECT rt = { 0, 0, _resolution.x, _resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); // window�� ������ ��ġ�� ũ�⸦ �������ִ� �Լ�

	_hDC = GetDC(_hWnd);

	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����.
	_hBitmap = CreateCompatibleBitmap(_hDC, _resolution.x, _resolution.y);
	_memDC = CreateCompatibleDC(_hDC);

	HBITMAP hPrevBit = static_cast<HBITMAP>(SelectObject(_memDC, _hBitmap));
	DeleteObject(hPrevBit);

	// Manager �ʱ�ȭ
	CTimeManager::GetInstance()->init();
	CKeyManager::GetInstance()->init();
	CSceneManager::GetInstance()->init();

	return S_OK;
}

void CCore::progress()
{
	// Managers update
	CTimeManager::GetInstance()->update(); // DT���
	CKeyManager::GetInstance()->update(); // Key���°� üũ

	// Scene Update
	CSceneManager::GetInstance()->update();

	// --------------------
	// Randering...
	// --------------------
	// ȭ�� clear
	Rectangle(_memDC, -1, -1, _resolution.x + 1, _resolution.y + 1);

	// ������ update�� �κ� �׸��� 
	CSceneManager::GetInstance()->render(_memDC);

	BitBlt(_hDC, 0, 0, _resolution.x, _resolution.y, _memDC, 0, 0, SRCCOPY);
}