#pragma once

class CObject;

class CScene
{
private :
	vector<CObject*> _objects[static_cast<unsigned int>(GROUP_TYPE::END)]; // ������Ʈ���� ���� �� ������ ���͸� �׷� ������ŭ ����
	wstring				_sceneName;

public:
	CScene();
	virtual ~CScene();

public :
	void SetName(wstring strName) { _sceneName = strName; }
	const wstring& GetName() const { return _sceneName; }

	void update();
	void render(HDC dc);

	virtual void Enter() abstract; // �ش� Scene �� ���Խ� ȣ��
	virtual void Exit() abstract; // �ش� Scene �� Ż�� �� ���

public :
	void AddObject(CObject* obj, GROUP_TYPE type)
	{
		_objects[static_cast<unsigned int>(type)].push_back(obj);
	}
	//void EraseObject(CObject* go, GROUP_TYPE type)
	//{
	//	auto typeVector = _objects[static_cast<UINT>//(type)];
	//	for (int i = 0; i < typeVector.size(); ++i)
	//	{
	//		if (typeVector[i] == go)
	//			delete go;
	//	}
	//}
};

