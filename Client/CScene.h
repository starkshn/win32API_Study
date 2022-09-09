#pragma once

class CObject;
class Texture;

class CScene
{
private :
	vector<CObject*> _objects[static_cast<unsigned int>(GROUP_TYPE::END)]; // ������Ʈ���� ���� �� ������ ���͸� �׷� ������ŭ ����
	wstring		_sceneName;
	Texture*	p_backGroundTexture;

public:
	CScene();
	virtual ~CScene();

public :
	void SetName(wstring strName) { _sceneName = strName; }
	const wstring& GetName() const { return _sceneName; }

	void update();
	void finalUpdate();
	virtual void render(HDC dc);

	virtual void Enter() abstract; // �ش� Scene �� ���Խ� ȣ��
	virtual void Exit() abstract; // �ش� Scene �� Ż�� �� ���

public :
	void AddObject(CObject* obj, GROUP_TYPE type)
	{
		_objects[static_cast<unsigned int>(type)].push_back(obj);
	}

	const vector<CObject*>& GetGroupObjects(const GROUP_TYPE& type)
	{
		return _objects[static_cast<UINT>(type)];
	}

};

