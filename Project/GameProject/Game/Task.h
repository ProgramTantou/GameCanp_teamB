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
	eType_Screen,//�Q�[���I�[�o�[�Ȃǂ̃X�N���[���̃^�C�v���B
	eType_Title,
	eType_UI,//��ʂ�UI�B
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

//�����̗D�揇
enum  class TaskPrio
{
	Scene,
	Field,
	Shadow,
	Object,
	UI,
	Fade,
};

//�I�u�W�F�N�g�̎��


class Task
{
	friend TaskManager;

public:


	Task(int type,int prio);
	virtual ~Task();

	/// <summary>
	/// �D��x�ݒ�
	/// </summary>
	/// <param name="prio">�ݒ肷��D��x</param>
	void SetPriority(int prio);

	void SetType(int type);

	/// <summary>
	///�D��x���擾 
	/// </summary>
	/// <returns></returns>
	int GetPriority() const;

	void SetSortOrder(int order);

	int GetSortOrder() const;

	//void SetType(int type);

	int GetType() const;

	/// <summary>
	/// �L�����ǂ�����ݒ�
	/// </summary>
	/// <param name="enable">true�Ȃ�ΗL��</param>
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