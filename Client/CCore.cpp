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

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = { 0, 0, _resolution.x, _resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); // window의 윈도우 위치와 크기를 변경해주는 함수

	_hDC = GetDC(_hWnd);

	// 이중 버퍼링 용도의 비트맵과 DC를 만든다.
	_hBitmap = CreateCompatibleBitmap(_hDC, _resolution.x, _resolution.y);
	_memDC = CreateCompatibleDC(_hDC);

	HBITMAP hPrevBit = static_cast<HBITMAP>(SelectObject(_memDC, _hBitmap));
	DeleteObject(hPrevBit);

	// Manager 초기화
	CTimeManager::GetInstance()->init();
	CKeyManager::GetInstance()->init();
	CSceneManager::GetInstance()->init();

	return S_OK;
}

void CCore::progress()
{
	// Managers update
	CTimeManager::GetInstance()->update(); // DT계산
	CKeyManager::GetInstance()->update(); // Key상태값 체크

	// Scene Update
	CSceneManager::GetInstance()->update();

	// --------------------
	// Randering...
	// --------------------
	// 화면 clear
	Rectangle(_memDC, -1, -1, _resolution.x + 1, _resolution.y + 1);

	// 씬에서 update한 부분 그리기 
	CSceneManager::GetInstance()->render(_memDC);

	BitBlt(_hDC, 0, 0, _resolution.x, _resolution.y, _memDC, 0, 0, SRCCOPY);
}