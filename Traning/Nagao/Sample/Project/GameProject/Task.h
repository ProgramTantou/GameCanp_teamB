#pragma once

class TaskManager;

//�^�X�N�̗D��x
enum class TaskPrio
{
	Field,		//�t�B�[���h
	Object,		//�Q�[�����̃I�u�W�F�N�g

	UI,			//��ʂɕ\������HUD�Ȃǂ�UI

};

//�^�X�N�N���X
class Task
{
	friend TaskManager;

public:
	Task(int prio);
	virtual ~Task();

	/// <summary>
	/// �D��x��ݒ�
	/// </summary>
	/// <param name="prio">�ݒ肷��D��x</param>
	void SetPriority(int prio);

	/// <summary>
	///�D��x���擾 
	/// </summary>
	/// /// <param name="prio"></param>
	int GetPriority() const;

	void SetSortOrder(int order);

	int GetSortOrder() const;
	
	/// <summary>
	/// �L�����ǂ�����ݒ�
	/// </summary>
	/// <param name="enable">true�Ȃ�ΗL��</param>
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
	int m_prio; //�^�X�N�̗D��x
	int m_sortOrder;//�����D��x���̏�������
	bool m_is_Enable;
	bool m_is_Show;
	bool m_is_Kill;
};