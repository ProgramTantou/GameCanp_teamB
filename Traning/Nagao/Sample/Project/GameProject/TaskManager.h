#pragma once
#include<list>

class Task;

class TaskManager
{
public:

	static void Add(Task* add, bool isShort = false);
	static void Remove(Task* remove, bool isShort = false);

	static void Delete(Task* del);
	static void DeleteAll();

	static void Update();
	static void Render();

private:
	TaskManager();
	~TaskManager();
	static std::list<Task*> m_taskList;
	static std::list<Task*> m_objectList;
};