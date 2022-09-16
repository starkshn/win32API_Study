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
	Texture*			p_texture; //�ִϸ��̼��� ����ϴ� texture
	vector<AnimFrame>	_vecAnimFrame; // �ִϸ��̼��� ��� ������ ����
	
public:
	Animation();
	~Animation();

public:
	void update();
	void render(HDC dc);

public:
	void Create(Texture* texture, Vector2 startPos, Vector2 sliceSize, Vector2 step, int frameCount);

private:
	// ���� �̸� �ߺ� ������ ���� private
	void SetAnimName(const wstring& animationName) { _animationName = animationName; }

public:
	void SetAnimator(Animator* animator) { p_animator = animator; }

public:
	const wstring& GetAnimName() { return _animationName; }
	Animator* GetAnimator() { return p_animator; }

	friend class Animator;
};

