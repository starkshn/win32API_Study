#pragma once

class Animator;
class Texture;

struct AnimFrame
{
	Vector2		_leftTop;
	Vector2		_sliceSize;
	Vector2		_offset; // offset��ġ
	float		_duration;
};

class Animation
{
private:
	Animator*			p_animator;
	wstring				_animationName;
	Texture*			p_texture = nullptr; //�ִϸ��̼��� ����ϴ� texture
	vector<AnimFrame>	_vecAnimFrame = {}; // �ִϸ��̼��� ��� ������ ����
	int					_curFrame; // ���� ������
	float				_accTime; // �ð� ���� ����

	bool				_animFinish; // �ִϸ��̼� �� �˸�.

public:
	Animation();
	~Animation();

public:
	void update();
	void render(HDC dc);

public:
	void Create(Texture* texture, Vector2 startPos, Vector2 sliceSize, Vector2 step, float duration, UINT frameCount);
	bool IsFinish() { return _animFinish; }

private:
	// ���� �̸� �ߺ� ������ ���� private
	void SetAnimName(const wstring& animationName) { _animationName = animationName; }
	void SetAnimFrame(int frame) 
	{
		_animFinish = false;
		_curFrame = frame;
		_accTime = 0.f;
	}

public:
	void SetAnimator(Animator* animator) { p_animator = animator; }

public:
	const wstring& GetAnimName() { return _animationName; }
	Animator* GetAnimator() { return p_animator; }
	AnimFrame& GetAnimFrame(int idx) { return _vecAnimFrame[idx]; }
	UINT GetMaxFrame() { return (UINT)_vecAnimFrame.size(); }

	friend class Animator;
};

