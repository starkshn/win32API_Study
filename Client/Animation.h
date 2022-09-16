#pragma once

class Animator;
class Texture;

struct AnimFrame
{
	Vector2 _leftTop;
	Vector2 _sliceSize;
};

class Animation
{
private:
	Animator*			p_animator;
	wstring				_animationName;
	Texture*			p_texture; //애니매이션이 사용하는 texture
	vector<AnimFrame>	_vecAnimFrame; // 애니매이션의 모든 프레임 정보
	
public:
	Animation();
	~Animation();

public:
	void update();
	void render(HDC dc);

public:
	void Create(Texture* texture, Vector2 startPos, Vector2 sliceSize, Vector2 step, int frameCount);

private:
	// 같은 이름 중복 방지를 위해 private
	void SetAnimName(const wstring& animationName) { _animationName = animationName; }

public:
	void SetAnimator(Animator* animator) { p_animator = animator; }

public:
	const wstring& GetAnimName() { return _animationName; }
	Animator* GetAnimator() { return p_animator; }

	friend class Animator;
};

