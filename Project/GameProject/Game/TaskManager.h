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

	static const std::list<Task*>& GetObjectList();

	static void Update();
	static void Render();
	static void CollisionAll();
/*	static void Collision(Task* b);
	static bool CollisionCircle(Task* b1, Task* b2);
	static bool CollisionRect(Task* b1, Task* b2);*/

	//static void Add(Task* b);


	static Task* FindObject(int type);
	static void SelectKill(int type);
	static void KillAll();

	static std::list<Task*> FindObjects(int type);

private:
	TaskManager();
	~TaskManager();
	static std::list<Task*> m_taskList;
	static std::list<Task*> m_objectList;
};