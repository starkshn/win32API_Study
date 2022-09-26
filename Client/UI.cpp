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
	// 부모의 finalUpdate호출 해야한다.
	// UI가 애니매이션 가질 수도 있기 때문에
	CObject::finalUpdate();

	// UI의 최종좌표를 구한다.
	_finalPos = GetPos(); // 부모 좌표를 finalPos로 인식

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