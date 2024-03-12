#pragma once


class TaskManager;

//タスクの優先度
enum class TaskPrio 
{
	Field,				//フィールド
	Shadow,				//オブジェクトの影
	Object,				//ゲーム中のオブジェクト	
	UI,					//ユーザーインターフェイス	
};



class Task
{

	friend TaskManager;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="prio">優先度</param>
	Task(int prio);
	virtual ~Task();
	/// <summary>
	/// 優先度を設定
	/// </summary>
	/// <param name="prio">設置する優先度</param>
	void SetPriority(int prio);
	/// <summary>
	/// 優先度を取得
	/// </summary>
	/// <returns></returns>
	int GetPriorty()const;
	/// <summary>
	/// 処理順番を設定
	/// </summary>
	/// <param name="order">設定する処理順番</param>
	void SetSortOrder(int order);
	/// <summary>
	/// 処理順番を取得
	/// </summary>
	/// <returns></returns>
	int GetSortOrder()const;
	/// <summary>
	/// 有効かどうかを設定
	/// </summary>
	/// <param name="enable">trueならば有効</param>
	void SetEnable(bool enable);
	/// <summary>
	/// 有効かどうかを取得
	/// </summary>
	/// <returns>trueなら有効</returns>
	bool IsEnable()const;
	/// <summary>
	/// 表示するかを設定
	/// </summary>
	/// <param name="show">trueなら表示</param>
	void SetShow(bool show);
	/// <summary>
	/// 表示するかを取得
	/// </summary>
	/// <returns>tureなら表示</returns>
	bool IsShow()const;
	//タスクを削除
	void Kill();
	//タスク削除の真偽
	bool IsKill()const;

	
	//更新
	virtual void Update();
	//描画
	virtual void Render();

private:
	//タスクの優先度
	int m_prio;
	//同じ優先度の処理順番
	int m_sortOrder;
	//タスクの有効
	bool m_isEnable;
	//タスクの描画
	bool m_isShow;
	//タスクの削除フラグ
	bool m_isKill;
};
