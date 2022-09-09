#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "PathManager.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "ColliderManager.h"

CCore::CCore()
	:
	h_wnd(0),
	_resolution{},
	h_dc(0),
	h_bitmap(0),
	h_memDC(0),
	h_brushes{},
	h_pens{}
{
	CreateHBRUSH();
	CreateHPEN();
}

CCore::~CCore()
{
	ReleaseDC(h_wnd, h_dc);

	DeleteDC(h_memDC);
	DeleteObject(h_bitmap);

	for (UINT i = 0; i < static_cast<UINT>(HPEN_TYPE::END); ++i)
	{
		DeleteObject(h_pens[i]);
	}
}

int CCore::init(HWND hWnd, POINT resolution)
{
	h_wnd = hWnd;
	_resolution = resolution;

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = { 0, 0, _resolution.x, _resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(h_wnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); // window의 윈도우 위치와 크기를 변경해주는 함수

	h_dc = GetDC(h_wnd);

	// 이중 버퍼링 용도의 비트맵과 DC를 만든다.
	h_bitmap = CreateCompatibleBitmap(h_dc, _resolution.x, _resolution.y);
	h_memDC = CreateCompatibleDC(h_dc);

	HBITMAP hPrevBit = static_cast<HBITMAP>(SelectObject(h_memDC, h_bitmap));
	DeleteObject(hPrevBit);

	// Manager 초기화
	PathManager::GetInstance()->init();
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
	// 충돌체크
	ColliderManager::GetInstance()->update();

	// --------------------
	// Randering...
	// --------------------
	// 화면 clear
	Rectangle(h_memDC, -1, -1, _resolution.x + 1, _resolution.y + 1);

	// 씬에서 update한 부분 그리기 
	CSceneManager::GetInstance()->render(h_memDC);

	BitBlt(h_dc, 0, 0, _resolution.x, _resolution.y, h_memDC, 0, 0, SRCCOPY);

	// CTimeManager::GetInstance()->render();
}

void CCore::CreateHBRUSH()
{
	// hollow brush
	h_brushes[static_cast<UINT>(HBRUSH_TYPE::HOLLOW)] = static_cast<HBRUSH>(GetStockObject(HOLLOW_BRUSH));
}

void CCore::CreateHPEN()
{
	// red, blue, green
	h_pens[static_cast<UINT>(HPEN_TYPE::RED)] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	h_pens[static_cast<UINT>(HPEN_TYPE::GREEN)] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	h_pens[static_cast<UINT>(HPEN_TYPE::BLUE)] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}
