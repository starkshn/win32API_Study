#pragma once

class CObject;
class Animation;
class Texture;

class Animator
{
private:
	CObject* p_owner; // �ִϸ��̼� ���� ������Ʈ
	map<wstring, Animation*> _mapAnimations; // ��� �ִϸ��̼�
	Animation* p_curAnimation; // ���� �ִϸ��̼�

public:
	Animator();
	Animator(const Animator& other);
	~Animator();

public:
	void update(); // ���� �������� �ִϸ��̼� update
	void finalUpdate();
	void render(HDC dc);

public:
	void CreateAnimation(const wstring& animationName, Texture* texture, Vector2 startPos, Vector2 sliceSize, Vector2 step, int frameCount);
	Animation* FindAnimation(const wstring& animName);
	void AnimationPlay();

	friend class CObject;
};

