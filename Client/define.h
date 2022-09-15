#pragma once
#include "pch.h"

// Singletone
#define SINGLE(type) public : static type* GetInstance() { static type mgr; return &mgr; } private : type(); ~type();

#define DeltaTime_F CTimeManager::GetInstance()->GetfDeltaTime()
#define DeltaTime CTimeManager::GetInstance()->GetDeltaTime()

// �Ͻ��� ��������� ȣ���� ��� �θ� ��������� ȣ���Ѵ�.
#define CLONE(type) type* Clone() { return new type(*this); }

#define KEY_CHECK(key, state) CKeyManager::GetInstance()->GetKeyState(key) == state

#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

#define PI 3.1415926535f

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MONSTER,
	PROJ_PLAYER,
	PROJ_MONSTER,
	MISSILE,
	CHARGEMISSILE,
	THREEMISSILE,
	MONSTERMISSILE,


	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END,
};

enum class MISSILE_TYPE
{
	DEFAULT,
	CHARINGMISSILE,
	THREEMISSILE,
	MONSTERMISSILE,

	END = 8,
};

enum class HBRUSH_TYPE
{
	HOLLOW,

	END,
};

enum class HPEN_TYPE
{
	RED,
	GREEN,
	BLUE,

	END,
};

// ����ó�� �ؾ��� �κе�
enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,


	END,
};
