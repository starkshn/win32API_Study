#include "pch.h"
#include "Animation.h"
#include "Animator.h"
#include "Texture.h"

Animation::Animation(): p_animator(nullptr), _animationName()
{

}

Animation::~Animation()
{

}

void Animation::update()
{

}

void Animation::render(HDC dc)
{

}

void Animation::Create
(   Texture* texture, 
	Vector2 startPos, Vector2 sliceSize, Vector2 step,
	float duration, UINT frameCount )
{
	p_texture = texture;

	AnimFrame frm = {};
	// frameCount : 만들어내야할 프레임 갯수
	for (UINT i = 0; i < frameCount; ++i)
	{
		frm._duration = duration;
		frm._sliceSize = sliceSize;
		frm._leftTop = startPos + (step * i);

		_vecAnimFrame.push_back(frm);
	}

}
