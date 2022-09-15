#pragma once

class CObject;
class Animation;

class Animator
{
private:
	CObject* p_owner;
	map<wstring, Animation*> _mapAnimations;
	 
public:
	Animator();
	~Animator();

	friend class COjbect;

public:
	void CreateAnimation();
	void FindAnimation();
	void AnimationPlay();

};

