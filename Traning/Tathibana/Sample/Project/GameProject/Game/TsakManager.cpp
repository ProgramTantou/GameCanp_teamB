#include "TsakManager.h"
#include"Task.h"
#include"ObjectBase.h"

//タスクのリストを定義
std::list<Task*> TaskManager::m_taskList;
//オブジェクトのリストを定義
std::list<Task*>TaskManager::m_objectList;
//コンストラクタ
TaskManager::TaskManager()
{

}
//デストラクタ
TaskManager::~TaskManager() 
{

}
//タスクをリストに追加
void TaskManager::Add(Task* add, bool isSort)
{
	if (!isSort)
	{
		//追加する優先度がオブジェクト用ならオブジェクトリストに追加
		if (add->m_prio == (int)TaskPrio::Object)
		{
			m_objectList.push_back(add);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while(itr!=end)
	{
		Task* task = *itr;
		//追加するタスクの優先度＜現在のタスク
		//その位置にタスクを追加
		if(add->m_prio<task->m_prio)
		{
			m_taskList.insert(itr, add);
			return;
		}
		//追加するタスクと現在のタスクの優先度が同じなら
		else if (add->m_prio == task->m_prio) 
		{
			//処理順番が小さい順に並べる
			if (add->m_sortOrder < task->m_sortOrder) 
			{
				m_taskList.insert(itr, add);
				return;
			}
		}
		itr++;
	}
	//最後まで追加する場所が見つからない場合
	//リストの最後尾に追加する
	m_taskList.push_back(add);
}
//タスクをリストから除く
void TaskManager::Remove(Task* remove, bool isSort)
{
	//ソートの呼び出し時ではない
	if (!isSort) 
	{
		//優先度がオブジェクト用であれば、オブジェクトリストからも取り除く
		if (remove->m_prio == (int)TaskPrio::Object) 
		{
			m_objectList.remove(remove);
		}
	}
	m_taskList.remove(remove);
}
//タスクを削除
void TaskManager::Delet(Task* del)
{
	//双方向リスト
	// 削除するタスクがオブジェクト用であれば、オブジェクトリストから取り除く
	if (del->m_prio == (int)TaskPrio::Object) {
		m_objectList.remove(del);
	 }
	 
	
	//削除の際、先にリストから除外してから削除する
	m_taskList.remove(del);
	delete del;
}
//リスト内のタスクをすべて削除
void TaskManager::DeleteAll()
{
	//オブジェクトリストとの中身をすべてクリアする
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



//リスト内の全タスクの更新処理を呼び出す
void TaskManager::Update()
{
	//削除フラグが立っているタスクを削除
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr!=end) 
	{
		Task* task = *itr;
		//削除フラグが立っていれば削除
		if (task->m_isKill)
		{
			itr = m_taskList.erase(itr);
			delete task;
		}
		else {
			itr++;
		}
	}

		itr = m_taskList.begin();
		end = m_taskList.end();
	while (itr != end) 
	{
		Task* task = *itr;
		//タスクが有効であれば、更新処理を呼び出す
		if (task->m_isEnable)
		{
			task->Update();
		}
		itr++;
	}
}
//リスト内の全タスクの描画処理を呼び出す
void TaskManager::Render()
{
	m_objectList.sort
	(
		[](const Task*taskA,const Task*taskB)
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
	while (itr != end)
	{
		Task* task = *itr;
		//タスクが有効かつ表示する設定であれば、描画処理を呼び出す
		if (task->m_isEnable&&task->m_isShow)
		{
			task->Render();
		}
		itr++;
	}
}
