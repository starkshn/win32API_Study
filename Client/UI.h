#pragma once
#include "CObject.h"

class UI : public CObject
{
private:
	CLONE(UI);

	vector<UI*> _vecUI;
	UI*			p_parentUI;

	Vector2		_finalPos; // 최종 위치

public:
	UI();
	~UI();

public:
	virtual void update() override;
	virtual void finalUpdate() override;
	virtual void render(HDC dc) override;

	void updateChild();
	void finalUpdateChild();
	void renderChild(HDC dc);

public:
	void AddChild(UI* ui)
	{
		_vecUI.push_back(ui);
		ui->p_parentUI = this;
	}

public:
	UI*		GetParentUI() { return p_parentUI; }
	Vector2 GetFinalPos() { return _finalPos; }


};

