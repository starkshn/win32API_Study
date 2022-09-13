#pragma once

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);

private :
	CScene* _scenes[static_cast<unsigned int>(SCENE_TYPE::END)]; // ��� �� ���
	CScene* _curScene; // ���� ��

public : 
	void init();
	void update();
	void render(HDC sceneDC);
	
public:
	CScene* GetCurScene() { return _curScene; }

};

