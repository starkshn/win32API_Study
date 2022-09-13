#pragma once

struct EVENT
{
	EVENT_TYPE	_event;
	DWORD		_lParam;
	DWORD		_wParam;
};

class EventManager
{
	SINGLE(EventManager)

private:
	vector<EVENT> _vecEvents;

public:
	void update();
};

