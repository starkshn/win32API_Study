#pragma once
#include "Resources.h"
class Texture : public Resources
{
private :
	HDC _dc; // Ŀ�� ������Ʈ id
	HBITMAP _bitMap;

public :
	Texture();
	~Texture();
	
public :
	void Load(const wstring& path);
};

