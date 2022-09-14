#include "pch.h"
#include "Func.h"
#include "EventManager.h"

void CreateObjectEvent(CObject* objectPtr, GROUP_TYPE groupType)
{
	Event evt = {};
	evt._eventType = EVENT_TYPE::CREATE_OBJECT;
	evt._objectPtr = (DWORD_PTR)objectPtr;
	evt._groupType = (DWORD_PTR)groupType;
	// DWORD_PTR������ �ȿ� �������� ��ü�� �˰��ִ�.

	EventManager::GetInstance()->AddEvent(evt);

}

void DeleteObjectEvent(CObject* objectPtr)
{
	Event evt = {};
	evt._eventType = EVENT_TYPE::DELETE_OBJECT;
	evt._objectPtr = (DWORD_PTR)objectPtr;

	EventManager::GetInstance()->AddEvent(evt);
}