#include "Task.h"
#include"TsakManager.h"

//コンストラクタ
Task::Task(int prio):m_prio(prio),m_sortOrder(0),m_isEnable(true),m_isShow(true),m_isKill(false)
{
	//タスクの生成と同時にTaskManagerにリストに自身を追加
	TaskManager::Add(this);
}
//デストラクタ
Task::~Task()
{
	//タスクの削除と同時にTaskMansgerのリストから自身を取り除く
	TaskManager::Remove(this);
}
//優先度を設定
void Task::SetPriority(int prio)
{
	m_prio = prio;
	//１回タスクのリストから自身を取り出す
	//その後タスクのリストに自身を追加
	//新しい優先度の場所に変更
	TaskManager::Remove(this,true);
	TaskManager::Add(this,true);
}
//優先度を取得
int Task::GetPriorty() const
{
	return m_prio;
}
//処理順番を設定
void Task::SetSortOrder(int order)
{
	//処理順番変更後、リスト内の並び替えを行う
	m_sortOrder = order;
	TaskManager::Remove(this,true);
	TaskManager::Add(this,true);
}
//処理順番を取得
int Task::GetSortOrder() const
{
	return m_sortOrder;
}
//有効の設定
void Task::SetEnable(bool enable)
{
	m_isEnable = enable;
}
//有効の真偽
bool Task::IsEnable() const
{
	return m_isEnable;
}
//表示の設定
void Task::SetShow(bool show)
{
	m_isShow = show;
}
//表示の真偽
bool Task::IsShow() const
{
	return m_isKill;
}
//タスクを削除
void Task::Kill()
{
	m_isKill = true;
}
//タスクの削除フラグ
bool Task::IsKill() const
{
	return m_isKill;
}

//更新
void Task::Update()
{
}
//描画
void Task::Render()
{
}
