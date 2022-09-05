#pragma once

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);

private :
	CScene* _scenes[static_cast<unsigned int>(SCENE_TYPE::END)]; // ��� �� ���
	CScene* _curScene; // ���� ��

public :

public : 
	void init();
	void update();
	void render(HDC sceneDC);
	
public:
	CScene* GetcurScene() { return _curScene; }

};

