#include "Task.h"
#include "TaskManager.h"
#include "ObjectBase.h"



Task::Task(int type, int prio)
: m_prio(prio)
, m_sortOrder(0)
, m_is_Enable(true)
, m_is_Show(true)
, m_is_Kill(false)
, m_type(type)
{
	//タスクマネージャー追加
	TaskManager::Add(this);
}

Task::~Task()
{
	TaskManager::Remove(this);
}

void Task::SetPriority(int prio)
{
	m_prio=prio;
	TaskManager::Remove(this, true);
	TaskManager::Add(this, true);
}

int Task::GetPriority() const
{
	return m_prio;
}

void Task::SetSortOrder(int order)
{
	m_sortOrder = order;
	TaskManager::Remove(this, true);
	TaskManager::Add(this, true);

}

int Task::GetSortOrder() const
{
	return m_sortOrder;
}

void Task::SetType(int type)
{
	m_type = type;
}

int Task::GetType() const
{
	return m_type;
}

void Task::SetEnable(bool enable)
{
	m_is_Enable=enable;
}

bool Task::IsEnable() const
{
	return m_is_Enable;
}

void Task::SetShow(bool show)
{
	m_is_Show = show;
}

bool Task::IsShow() const
{
	return m_is_Show;
}

void Task::Kill()
{
	m_is_Kill = true;
}

bool Task::IsKill() const
{
	return m_is_Kill;
}

void Task::Update()
{

}

void Task::Render()
{

}

void Task::Collision(Task* b)
{

}

