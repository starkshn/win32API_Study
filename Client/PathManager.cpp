#include "pch.h"
#include "PathManager.h"
#include "CCore.h"

PathManager::PathManager() : _contentsPath()
{

}
PathManager::~PathManager()
{

}

void PathManager::init() // ��� ã�Ƴ����Ѵ�.
{
	GetCurrentDirectory(255, _contentsPath);

	int len = wcslen(_contentsPath);

	for (int i = len - 1; i >= 0; --i)
	{
		if ('\\' == _contentsPath[i])
		{
			_contentsPath[i] = '\0';
			break;
		}
	}

	wcscat_s(_contentsPath, 255, L"\\bin\\Contents\\");
	
	// SetWindowText(CCore::GetInstance()->GetMainHwnd(), _contentsPath);
}