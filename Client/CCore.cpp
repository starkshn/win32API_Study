#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "PathManager.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "ColliderManager.h"
#include "EventManager.h"
#include "CameraManager.h"

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

	// �ػ󵵿� �°� ������ ũ�� ����
	RECT rt = { 0, 0, _resolution.x, _resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(h_wnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); // window�� ������ ��ġ�� ũ�⸦ �������ִ� �Լ�

	h_dc = GetDC(h_wnd);

	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����.
	h_bitmap = CreateCompatibleBitmap(h_dc, _resolution.x, _resolution.y);
	h_memDC = CreateCompatibleDC(h_dc);

	HBITMAP hPrevBit = static_cast<HBITMAP>(SelectObject(h_memDC, h_bitmap));
	DeleteObject(hPrevBit);

	// Manager �ʱ�ȭ
	PathManager::GetInstance()->init();
	CTimeManager::GetInstance()->init();
	CKeyManager::GetInstance()->init();
	CSceneManager::GetInstance()->init();

	return S_OK;
}

void CCore::progress()
{
	// ===============
	// Managers update
	// ===============
	CTimeManager::GetInstance()->update(); // DT���
	CKeyManager::GetInstance()->update(); // Key���°� üũ
	CameraManager::GetInstance()->update();

	// ============
	// Scene Update
	// ============
	CSceneManager::GetInstance()->update();

	// ===============
	// Collider Update
	// ===============
	ColliderManager::GetInstance()->update(); // �浹üũ

	// =============
	// Randering...
	// =============
	Rectangle(h_memDC, -1, -1, _resolution.x + 1, _resolution.y + 1); // ȭ�� clear
	CSceneManager::GetInstance()->render(h_memDC); // ������ update�� �κ� �׸��� 
	BitBlt(h_dc, 0, 0, _resolution.x, _resolution.y, h_memDC, 0, 0, SRCCOPY);

	// ===============
	// �̺�Ʈ ���� ó��
	// ===============
	EventManager::GetInstance()->update();
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
