#include "pch.h"
#include "Animator.h"
#include "Animation.h"

Animator::Animator()
	:
	p_owner(nullptr),
	p_curAnimation(nullptr)
{

}

Animator::Animator(const Animator& other)
{

}

Animator::~Animator()
{
	// 관리하고있는 애니매이션 싹다 삭제.
	SafeDeleteMap(_mapAnimations);
}

void Animator::update()
{
	if (nullptr != p_curAnimation)
		p_curAnimation->update();
}

void Animator::finalUpdate()
{

}

void Animator::render(HDC dc)
{
	if (nullptr != p_curAnimation)
		p_curAnimation->render(dc);
}

void Animator::CreateAnimation(const wstring& animName, Texture* texture, Vector2 startPos, Vector2 sliceSize, Vector2 step, int frameCount)
{
	Animation* anim = FindAnimation(animName);
	assert(nullptr == anim);

	anim = new Animation();

	anim->SetAnimName(animName);
	anim->SetAnimator(this);
	anim->Create(texture, startPos, sliceSize, step, frameCount);

	_mapAnimations.insert(make_pair(animName, anim));

}

Animation* Animator::FindAnimation(const wstring& animName)
{
	// auto iter = _mapAnimations.find(animName);
	map<wstring, Animation*>::iterator iter = _mapAnimations.find(animName);

	if (iter == _mapAnimations.end())
		return nullptr;

	return iter->second;
}

void Animator::AnimationPlay()
{

}
