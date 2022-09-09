#pragma once

class CObject;
class Texture;

class CScene
{
private :
	vector<CObject*> _objects[static_cast<unsigned int>(GROUP_TYPE::END)]; // 오브젝트들을 저장 및 관리할 벡터를 그룹 갯수만큼 선언
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

	virtual void Enter() abstract; // 해당 Scene 에 진입시 호출
	virtual void Exit() abstract; // 해당 Scene 을 탈출 시 사용

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

