#pragma once
class ColliderManager
{
	SINGLE(ColliderManager)

private:
	UINT _arrCheck[static_cast<UINT>(GROUP_TYPE::END)];


public:
	void update();
	void CheckGroup(GROUP_TYPE left, GROUP_TYPE right);
	void ResetGroup()
	{
		memset(_arrCheck, 0, sizeof(UINT) * static_cast<UINT>(GROUP_TYPE::END));
	}


};

