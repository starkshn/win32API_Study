#pragma once
#include "Resources.h"

class Texture : public Resources
{
private :
	HDC _dc; // Ŀ�� ������Ʈ id
	HBITMAP _bitMap;
	BITMAP _objectInfo;

private :
	Texture();
	~Texture();
	
	friend class ResourceManager; 
public :
	void Load(const wstring& path);

	void SetWidthInfo(LONG width) { _objectInfo.bmWidth = width; }
	void SetHeightInfo(LONG height) { _objectInfo.bmHeight = height; }

	HDC	 GetDC() { return _dc; }
	LONG GetWidth() { return _objectInfo.bmWidth; }
	LONG GetHeight() { return _objectInfo.bmHeight; }
	BITMAP GetInfo() { return _objectInfo; }

	
};

