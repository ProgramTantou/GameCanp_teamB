#pragma once

class TaskManager;

//タスクの優先度
enum class TaskPrio
{
	Field,		//フィールド
	Object,		//ゲーム中のオブジェクト

	UI,			//画面に表示するHUDなどのUI

};

//タスククラス
class Task
{
	friend TaskManager;

public:
	Task(int prio);
	virtual ~Task();

	/// <summary>
	/// 優先度を設定
	/// </summary>
	/// <param name="prio">設定する優先度</param>
	void SetPriority(int prio);

	/// <summary>
	///優先度を取得 
	/// </summary>
	/// /// <param name="prio"></param>
	int GetPriority() const;

	void SetSortOrder(int order);

	int GetSortOrder() const;
	
	/// <summary>
	/// 有効かどうかを設定
	/// </summary>
	/// <param name="enable">trueならば有効</param>
	void SetEnable(bool enable);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool IsEnable() const;

	void SetShow(bool show);

	bool IsShow() const;

	void Kill();

	bool IsKill() const;

	virtual void Update();
	virtual void Render();

private:
	int m_prio; //タスクの優先度
	int m_sortOrder;//同じ優先度内の処理順番
	bool m_is_Enable;
	bool m_is_Show;
	bool m_is_Kill;
};