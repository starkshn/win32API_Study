#pragma once

// 1. ������ ����ȭ
// 2. Ű �Է� �̺�Ʈ�� ��ü�� ó��

enum class KEY_STATE
{
	NONE, // ������ �ʾҰ�, �������� ������ ���� ����
	TAP, // �� ���� ����
	HOLD, // ������ �ִ�
	AWAY, // �� �� ����
};

enum class KEY
{
	LEFT,
	UP,
	DOWN,
	RIGHT,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,

	ALT,
	LSHIFT,
	SPACE,
	CTRL,
	ENTER,
	ESC,

	LBTN,
	RBTN,
	
	LAST,
};

struct KeyInfo
{
	KEY_STATE	_state; // Ű�� ����
	bool			_isPrevInput; // ���� �����ӿ� ���ȴ��� ����
};

class CKeyManager
{
	SINGLE(CKeyManager);

private :
	vector<KeyInfo> _vecKey;
	Vector2			_curMousePos;

public :
	void init();
	void update();

public:
	KEY_STATE GetKeyState(KEY key);
	Vector2 GetCurrentMousePos() { return _curMousePos; }


};

