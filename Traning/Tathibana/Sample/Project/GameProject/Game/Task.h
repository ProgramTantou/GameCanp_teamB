#pragma once


class TaskManager;

//�^�X�N�̗D��x
enum class TaskPrio 
{
	Field,				//�t�B�[���h
	Shadow,				//�I�u�W�F�N�g�̉e
	Object,				//�Q�[�����̃I�u�W�F�N�g	
	UI,					//���[�U�[�C���^�[�t�F�C�X	
};



class Task
{

	friend TaskManager;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="prio">�D��x</param>
	Task(int prio);
	virtual ~Task();
	/// <summary>
	/// �D��x��ݒ�
	/// </summary>
	/// <param name="prio">�ݒu����D��x</param>
	void SetPriority(int prio);
	/// <summary>
	/// �D��x���擾
	/// </summary>
	/// <returns></returns>
	int GetPriorty()const;
	/// <summary>
	/// �������Ԃ�ݒ�
	/// </summary>
	/// <param name="order">�ݒ肷�鏈������</param>
	void SetSortOrder(int order);
	/// <summary>
	/// �������Ԃ��擾
	/// </summary>
	/// <returns></returns>
	int GetSortOrder()const;
	/// <summary>
	/// �L�����ǂ�����ݒ�
	/// </summary>
	/// <param name="enable">true�Ȃ�ΗL��</param>
	void SetEnable(bool enable);
	/// <summary>
	/// �L�����ǂ������擾
	/// </summary>
	/// <returns>true�Ȃ�L��</returns>
	bool IsEnable()const;
	/// <summary>
	/// �\�����邩��ݒ�
	/// </summary>
	/// <param name="show">true�Ȃ�\��</param>
	void SetShow(bool show);
	/// <summary>
	/// �\�����邩���擾
	/// </summary>
	/// <returns>ture�Ȃ�\��</returns>
	bool IsShow()const;
	//�^�X�N���폜
	void Kill();
	//�^�X�N�폜�̐^�U
	bool IsKill()const;

	
	//�X�V
	virtual void Update();
	//�`��
	virtual void Render();

private:
	//�^�X�N�̗D��x
	int m_prio;
	//�����D��x�̏�������
	int m_sortOrder;
	//�^�X�N�̗L��
	bool m_isEnable;
	//�^�X�N�̕`��
	bool m_isShow;
	//�^�X�N�̍폜�t���O
	bool m_isKill;
};
