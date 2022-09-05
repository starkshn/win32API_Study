#pragma once

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);

private :
	CScene* _scenes[static_cast<unsigned int>(SCENE_TYPE::END)]; // ¸ðµç ¾À µî·Ï
	CScene* _curScene; // ÇöÀç ¾À

public :

public : 
	void init();
	void update();
	void render(HDC sceneDC);
	
public:
	CScene* GetcurScene() { return _curScene; }

};

