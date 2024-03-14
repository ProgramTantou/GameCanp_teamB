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
		itr++;
	}

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

	m_taskList.remove(del);
	delete del;
}

void TaskManager::DeleteAll()
{
	m_objectList.clear();

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* del = *itr;
		itr = m_taskList.erase(itr);
		delete del;
	}
}

const std::list<Task*>& TaskManager::GetObjectList()
{
	return m_objectList;
}

Task* TaskManager::FindObject(int type)
{
	for (auto& b : m_taskList)
	{
		if (b->m_type == type)
		{
			return b;
		}
	}
}

std::list<Task*> TaskManager::FindObjects(int type)
{
	std::list<Task*> ret;

	for (auto& b : m_taskList)
	{
		if (b->m_type == type)
		{
			ret.push_back(b);
		}
	}
	return ret;
}

void TaskManager::Update()
{
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
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
		[](const Task* taskA, const Task* taskB)
		{
			const ObjectBase* objA = dynamic_cast<const ObjectBase*>(taskA);
			const ObjectBase* objB = dynamic_cast<const ObjectBase*>(taskB);
			return objB->GetPos().z < objA->GetPos().z;
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
	while (itr != end)
	{
		Task* task = *itr;

		if (task->m_is_Enable && task->m_is_Show)
		{
			task->Render();
		}
		itr++;
	}
}

void TaskManager::KillAll()
{
	for (auto& b : m_taskList)
	{
			b->Kill();
	}
}

void TaskManager::SelectKill(int type)
{
	for (auto& b : m_taskList)
	{
		if (b->m_type == type)
		{
			b->Kill();
		}
	}
}

/*void TaskManager::DrawRect(Task* b1, Task* b2)
{
	//デバッグ用　矩形の表示
	CRect rect = CRect(
		b1->m_pos.x + b2->m_rect.m_left,
		b1->m_pos.y + b2->m_rect.m_top,
		b1->m_pos.x + b2->m_rect.m_right,
		b1->m_pos.y + b2->m_rect.m_bottom);
	Utility::DrawQuad(
		CVector2D(rect.m_left, rect.m_top) - m_scroll,
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(1, 0, 0, 0.5f));
}*/

/*void TaskManager::Collision(Task* b)
{

}

bool TaskManager::CollisionCircle(Task* b1, Task* b2)
{
	CVector3D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	if (l < b1->m_rad + b2->m_rad)
	{
		return true;
	}
	return false;
}

bool TaskManager::CollisionRect(Task* b1, Task* b2)
{
	//b1の矩形
	CRect rect1 = CRect(
		b1->m_pos.x + b1->m_rect.m_left,
		b1->m_pos.y + b1->m_rect.m_top,
		b1->m_pos.x + b1->m_rect.m_right,
		b1->m_pos.y + b1->m_rect.m_bottom);
	//b2の矩形
	CRect rect2 = CRect(
		b2->m_pos.x + b2->m_rect.m_left,
		b2->m_pos.y + b2->m_rect.m_top,
		b2->m_pos.x + b2->m_rect.m_right,
		b2->m_pos.y + b2->m_rect.m_bottom);

	//矩形同士の判定
	if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
		rect1.m_top <= rect2.m_bottom && rect1.m_bottom >= rect2.m_top)
		return true;

	return false;
}*/

void TaskManager::CollisionAll()
{
	auto it1 = m_taskList.begin();
	auto last = m_taskList.end();
	while (it1 != last) {
		auto it2 = it1;
		it2++;
		while (it2 != last) {
			(*it1)->Collision(*it2);
			(*it2)->Collision(*it1);
			it2++;
		}
		it1++;
	}
}