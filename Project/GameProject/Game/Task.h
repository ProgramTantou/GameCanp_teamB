#pragma once
class TaskManager;

enum {
	eType_Field,
	eType_Door,
	eType_AreaChange,
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Goal,
	eType_Scene,
	eType_Screen,//ゲームオーバーなどのスクリーンのタイプ名。
	eType_Title,
	eType_UI,//画面のUI。
	eType_Enemy_Attack,
	eType_Fish,
	eType_FishManager
};

enum
{
	eFish_1,
	eFish_2,
	eFish_3
};

//処理の優先順
enum  class TaskPrio
{
	Scene,
	Field,
	Shadow,
	Object,
	UI,
	Fade,
};

//オブジェクトの種類


class Task
{
	friend TaskManager;

public:


	Task(int type,int prio);
	virtual ~Task();

	/// <summary>
	/// 優先度設定
	/// </summary>
	/// <param name="prio">設定する優先度</param>
	void SetPriority(int prio);

	void SetType(int type);

	/// <summary>
	///優先度を取得 
	/// </summary>
	/// <returns></returns>
	int GetPriority() const;

	void SetSortOrder(int order);

	int GetSortOrder() const;

	//void SetType(int type);

	int GetType() const;

	/// <summary>
	/// 有効かどうかを設定
	/// </summary>
	/// <param name="enable">trueならば有効</param>
	void SetEnable(bool enable);


	bool IsEnable() const;

	void SetShow(bool show);

	bool IsShow() const;

	void Kill();

	bool IsKill() const;

	virtual void Update();
	//virtual void Draw();
	virtual void Render();
	virtual void Collision(Task* b);


//private:
	int m_prio;
	int m_sortOrder;
	int m_type;

	bool m_is_Enable;
	bool m_is_Show;
	bool m_is_Kill;

};