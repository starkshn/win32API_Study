#pragma once

class CObject;
class Texture;

class CScene
{
private :
	vector<CObject*> _objects[static_cast<unsigned int>(GROUP_TYPE::END)]; // ������Ʈ���� ���� �� ������ ���͸� �׷� ������ŭ ����
	wstring		_sceneName;
	UINT		_tileXCount;
	UINT		_tileYCount;

public:
	CScene();
	virtual ~CScene();

public:
	virtual void update();
	void finalUpdate();
	virtual void render(HDC dc);

	virtual void Enter() abstract; // �ش� Scene �� ���Խ� ȣ��
	virtual void Exit() abstract; // �ش� Scene �� Ż�� �� ���

public:
	void AddObject(CObject* obj, GROUP_TYPE type)
	{
		_objects[static_cast<unsigned int>(type)].push_back(obj);
	}
	void DeleteGroupObjects(GROUP_TYPE groupType);
	void DeleteAllGroups();
	void CreateTile(UINT xCount, UINT yCount);

public:
	void SetName(wstring strName) { _sceneName = strName; }

public:
	const wstring& GetName() const { return _sceneName; }
	const vector<CObject*>& GetGroupObjects(const GROUP_TYPE& type)
	{
		return _objects[static_cast<UINT>(type)];
	}
	UINT GetTileX() { return _tileXCount;  };
	UINT GetTileY() { return _tileYCount;  };
	

};

