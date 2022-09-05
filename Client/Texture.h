#pragma once
#include "Resources.h"
class Texture : public Resources
{
private :
	HDC _dc; // 커널 오브젝트 id
	HBITMAP _bitMap;

public :
	Texture();
	~Texture();
	
public :
	void Load(const wstring& path);
};

