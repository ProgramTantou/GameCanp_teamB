#include "TaskManager.h"
#include "Task.h"
#include "ObjectBase.h"

std::list<Task*>TaskManager::m_taskList;

std::list<Task*>TaskManager::m_objectList;

TaskManager::TaskManager()
{
	
}

TaskManager::~TaskManager()
{

}

void TaskManager::Add(Task* add, bool IsShort)
{
	if (!IsShort)
	{
		if (add->m_prio == (int)TaskPrio::Object)
		{
			m_objectList.push_back(add);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* task = *itr;
		if (add->m_prio < task->m_prio)
		{
			m_taskList.insert(itr, add);
			return;
		}
		else if (add->m_prio == task->m_prio)
		{
			if (add->m_sortOrder < task->m_sortOrder)
			{
				m_taskList.insert(itr, add);
				return;
			}
		}

		/*if (add->GetPriority() < task->GetPriority())
		{
			m_taskList.insert(itr, add);
			return;
		}*/
		itr++;
	}
	//最後まで追加する場所が見つからなかった場合は、
	//リストの最後に追加する。
	m_taskList.push_back(add);
}

void TaskManager::Remove(Task* remove, bool isShort)
{
	if (!isShort)
	{
		if (remove->m_prio == (int)TaskPrio::Object)
		{
			m_objectList.remove(remove);
		}
	}
	m_taskList.remove(remove);
}

void TaskManager::Delete(Task* del)
{
	if (del->m_prio == (int)TaskPrio::Object)
	{
		m_objectList.remove(del);
	}
	//削除するときは、先にリストから取り除いてから削除する。
	m_taskList.remove(del);
	delete del;
}

void TaskManager::DeleteAll()
{
	//全て削除
	m_objectList.clear();

	/*int* p = new int[5];
	delete[] p;
	p = new int[6];*/
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr!=end)
	{
		Task* del = *itr;
		itr = m_taskList.erase(itr);
		delete del;
	}
}

void TaskManager::Update()
{
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr!=end)
	{
		Task* task = *itr;
		if (task->m_is_Kill)
		{
			itr = m_taskList.erase(itr);
			delete task;
		}
		else
		{
			itr++;
		}
	}

	itr = m_taskList.begin();
	end = m_taskList.end();
	while (itr!=end)
	{
		Task* task = *itr;
		if (task->m_is_Enable)
		{
			task->Update();
		}
		itr++;
	}
}

void TaskManager::Render()
{
	m_objectList.sort
	(
		//ラムダ式
		[](const Task* taskA, const Task* taskB)
		{
			const ObjectBase* objA = dynamic_cast<const ObjectBase*>(taskA);
			const ObjectBase* objB = dynamic_cast<const ObjectBase*>(taskB);
			return objA->GetPos().y < objB->GetPos().y;
		}
	);
	
	int sortOrder = 0;
	for (auto& obj : m_objectList)
	{
		obj->SetSortOrder(sortOrder);
		sortOrder++;
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr!=end)
	{
		Task* task = *itr;

		if (task->m_is_Enable && task->m_is_Show)
		{
			task->Render();
		}
		itr++;
	}
}