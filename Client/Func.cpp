#include "pch.h"
#include "Func.h"
#include "EventManager.h"

void CreateObjectEvent(CObject* obj, GROUP_TYPE groupType)
{
	Event evt = {};
	evt._eventType = EVENT_TYPE::CREATE_OBJECT;
	evt._objectPtr = (DWORD_PTR)obj;
	evt._groupType = (DWORD_PTR)groupType;
	// DWORD_PTR이지만 안에 데이터의 정체를 알고있다.

	EventManager::GetInstance()->AddEvent(evt);

}