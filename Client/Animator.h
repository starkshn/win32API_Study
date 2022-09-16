#pragma once

class CObject;
class Animation;
class Texture;

class Animator
{
private:
	CObject* p_owner; // 애니매이션 소유 오브젝트
	map<wstring, Animation*> _mapAnimations; // 모든 애니매이션
	Animation* p_curAnimation; // 현재 애니매이션

public:
	Animator();
	Animator(const Animator& other);
	~Animator();

public:
	void update(); // 현재 진행중인 애니매이션 update
	void finalUpdate();
	void render(HDC dc);

public:
	void CreateAnimation(const wstring& animationName, Texture* texture, Vector2 startPos, Vector2 sliceSize, Vector2 step, int frameCount);
	Animation* FindAnimation(const wstring& animName);
	void AnimationPlay();

	friend class CObject;
};

