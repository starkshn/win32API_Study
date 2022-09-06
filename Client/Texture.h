#pragma once
#include "Resources.h"
class Texture : public Resources
{
private :
	HDC _dc; // Ŀ�� ������Ʈ id
	HBITMAP _bitMap;
	BITMAP _objectInfo;

public :
	Texture();
	~Texture();
	
public :
	void Load(const wstring& path);
	HDC	 GetDC() { return _dc; }
	LONG GetWidth() { return _objectInfo.bmWidth; }
	LONG GetHeight() { return _objectInfo.bmHeight; }
};

