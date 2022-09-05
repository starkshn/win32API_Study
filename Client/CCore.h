#pragma once

class CCore
{
	SINGLE(CCore);

private:
	HWND		_hWnd; // ���� ������ �ڵ�
	POINT		_resolution; // ���� ������  �ػ�
	HDC			_hDC; // ���� �����쿡 Draw�� DC

	HBITMAP		_hBitmap;
	HDC				_memDC;

public:
	int init(HWND hWnd, POINT resolution);
	void progress();

private:
	void update();
	void render();

public :
	HWND	GetMainHwnd() { return _hWnd; }
	POINT	GetResolution() { return _resolution; }
};