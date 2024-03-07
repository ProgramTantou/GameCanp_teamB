#pragma once

class TaskManager;

enum class TaskPrio {
	Field,      //�t�B�[���h
	Shadow,     //�I�u�W�F�N�g�̉e
	Object,     //�Q�[�����̃I�u�W�F�N�g

	UI,         //��ʂɕ\������HUD�Ȃǂ�UI
};

//�^�X�N�N���X
class Task {

	friend TaskManager;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="prio">�D��x</param>
	Task(int prio);
	//�f�X�g���N�^
	virtual ~Task();

	/// <summary>
	/// �D��x��ݒ�
	/// </summary>
	/// <param name="prio">�ݒ肷��D��x</param>
	void SetPriority(int prio);

	/// <summary>
	/// �D��x���擾
	/// </summary>
	/// <returns></returns>
	int GetPriority() const;

	/// <summary>
	/// �������Ԃ�ݒ�
	/// </summary>
	/// <param name="order"></param>
	void SetSortOrder(int order);

	/// <summary>
	/// �������Ԃ��擾
	/// </summary>
	/// <returns>�ݒ肷�鏈������</returns>
	int GetSortOrder() const;

	/// <summary>
	/// �L�����ǂ�����ݒ�
	/// </summary>
	/// <param name="enable">true�Ȃ�ΗL��</param>
	void SetEnable(bool enable);

	/// <summary>
	/// �L�����ǂ������擾
	/// </summary>
	/// <returns>true�Ȃ�ΗL��</returns>
	bool IsEnable() const;

	/// <summary>
	/// �\�����邩�ǂ�����ݒ�
	/// </summary>
	/// <param name="show">true�Ȃ�Ε\������</param>
	void SetShow(bool show);

	/// <summary>
	/// �\�����邩�ǂ������擾
	/// </summary>
	/// <returns>true�Ȃ�Ε\������</returns>
	bool IsShow() const;

	//�^�X�N���폜
	void Kill();
	//�^�X�N�̍폜�t���O�������Ă��邩�ǂ���
	bool IsKill() const;

	//�X�V
	virtual void Update();
	//�`��
	virtual void Render();

private:
	int m_prio;      //�^�X�N�̗D��x
	int m_sortOrder; //�����D��x���̏�������
	bool m_isEmable; //�^�X�N���L�����ǂ���
	bool m_isShow;   //�^�X�N��`�悷�邩�ǂ���
	bool m_isKill;   //�^�X�N�̍폜�t���O
};
