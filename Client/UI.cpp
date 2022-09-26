#include "pch.h"
#include "UI.h"

UI::UI()
	:
	_vecUI{},
	p_parentUI(nullptr),
	_finalPos{}
{

}

UI::~UI()
{
	SafeDeleteVector(_vecUI);
}

void UI::update()
{
	// child update
	updateChild();
}

void UI::finalUpdate()
{
	// �θ��� finalUpdateȣ�� �ؾ��Ѵ�.
	// UI�� �ִϸ��̼� ���� ���� �ֱ� ������
	CObject::finalUpdate();

	// UI�� ������ǥ�� ���Ѵ�.
	_finalPos = GetPos(); // �θ� ��ǥ�� finalPos�� �ν�

	if (GetParentUI())
	{
		Vector2 parentPos = GetParentUI()->GetFinalPos();
		_finalPos += parentPos;
	}

	finalUpdateChild();
}

void UI::render(HDC dc)
{
	Vector2 pos = GetFinalPos();
	Vector2 scale = GetScale();

	Rectangle
	(
		dc,					  
		int(pos._x			  ),
		int(pos._y			  ),
		int(pos._x + scale._x ),
		int(pos._y + scale._y )
	);

	// child render
	renderChild(dc);
}

void UI::updateChild()
{
	for (size_t i = 0; i < _vecUI.size(); ++i)
	{
		_vecUI[i]->update();
	}
}

void UI::finalUpdateChild()
{
	for (size_t i = 0; i < _vecUI.size(); ++i)
	{
		_vecUI[i]->finalUpdate();
	}
}

void UI::renderChild(HDC dc)
{
	for (size_t i = 0; i < _vecUI.size(); ++i)
	{
		_vecUI[i]->render(dc);
	}
}