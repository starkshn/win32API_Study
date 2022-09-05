#pragma once

class CCore
{
	SINGLE(CCore);

private:
	HWND		_hWnd; // 메인 윈도우 핸들
	POINT		_resolution; // 메인 윈도우  해상도
	HDC			_hDC; // 메인 윈도우에 Draw할 DC

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