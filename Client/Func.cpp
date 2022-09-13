#include "pch.h"
#include "Func.h"
#include "EventManager.h"

void CreateObjectEvent(CObject* obj, GROUP_TYPE groupType)
{
	Event evt = {};
	evt._eventType = EVENT_TYPE::CREATE_OBJECT;
	evt._objectPtr = (DWORD_PTR)obj;
	evt._groupType = (DWORD_PTR)groupType;
	// DWORD_PTR������ �ȿ� �������� ��ü�� �˰��ִ�.

	EventManager::GetInstance()->AddEvent(evt);

}