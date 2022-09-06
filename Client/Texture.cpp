#include "pch.h"
#include "Texture.h"

Texture::Texture() : _dc(0), _bitMap{0}
{
	
}

Texture::~Texture()
{
	DeleteDC(_dc);
	DeleteObject(_bitMap);
}

void Texture::Load(const wstring& path)
{
	_bitMap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	if (_bitMap == nullptr)
		assert(_bitMap);

}

