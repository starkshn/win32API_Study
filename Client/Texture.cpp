#include "pch.h"
#include "Texture.h"

Texture::Texture() : _dc(0), _bitMap{0}
{
	
}

Texture::~Texture()
{
	
}

void Texture::Load(const wstring& path)
{
	_bitMap = static_cast<HBITMAP>(LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE));

	if (_bitMap == nullptr)
		assert(_bitMap);

}

