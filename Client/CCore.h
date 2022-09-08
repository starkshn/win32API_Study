#pragma once

class CCore
{
	SINGLE(CCore);

private:
	HWND		h_wnd; // ���� ������ �ڵ�
	POINT		_resolution; // ���� ������  �ػ�
	HDC			h_dc; // ���� �����쿡 Draw�� DC

	HBITMAP		h_bitmap;
	HDC			h_memDC;

	// ���� ����ϴ� GDI Object (Ŀ�ο�����Ʈ)
	HBRUSH h_brushes[static_cast<UINT>(HBRUSH_TYPE::END)];
	HPEN h_pens[static_cast<UINT>(HPEN_TYPE::END)];

public:
	int init(HWND hWnd, POINT resolution);
	void progress();

private:
	void CreateHBRUSH();
	void CreateHPEN();

public :
	HWND	GetMainHwnd() { return h_wnd; }
	POINT	GetResolution() { return _resolution; }
	HDC		GetMainDC() { return h_dc; }

	HBRUSH	GetHBRUSH(HBRUSH_TYPE type) { return h_brushes[static_cast<UINT>(type)]; }
	HPEN	GetHPEN(HPEN_TYPE type) { return h_pens[static_cast<UINT>(type)]; }
};