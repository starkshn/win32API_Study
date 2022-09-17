#include "pch.h"
#include "Animator.h"
#include "Animation.h"

Animator::Animator()
	:
	p_owner(nullptr),
	p_curAnimation(nullptr),
	_animRepeat(false)
{

}

Animator::Animator(const Animator& other)
{

}

Animator::~Animator()
{
	// �����ϰ��ִ� �ִϸ��̼� �ϴ� ����.
	SafeDeleteMap(_mapAnimations);
}

void Animator::update()
{
	if (nullptr != p_curAnimation)
	{
		p_curAnimation->update();

		if (_animRepeat && p_curAnimation->IsFinish())
		{
			p_curAnimation->SetAnimFrame(0);
		}
	}
}

void Animator::finalUpdate()
{

}

void Animator::render(HDC dc)
{
	if (nullptr != p_curAnimation)
		p_curAnimation->render(dc);
}

void Animator::CreateAnimation ( 
	const wstring& animName, 
	Texture* texture, Vector2 startPos,
	Vector2 sliceSize, Vector2 step,
	float duration, UINT frameCount )
{
	Animation* anim = FindAnimation(animName);
	assert(nullptr == anim);

	anim = new Animation();

	anim->SetAnimName(animName);
	anim->SetAnimator(this);
	anim->Create(texture, startPos, sliceSize, step, duration ,frameCount);

	_mapAnimations.insert(make_pair(animName, anim));
}

Animation* Animator::FindAnimation( const wstring& animName)
{
	// auto iter = _mapAnimations.find(animName);
	map<wstring, Animation*>::iterator iter = _mapAnimations.find(animName);

	if (iter == _mapAnimations.end())
		return nullptr;

	return iter->second;
}

void Animator::PlayAnimation(const wstring& animName, bool animRepeat)
{
	p_curAnimation = FindAnimation(animName);
	_animRepeat = animRepeat;
}

