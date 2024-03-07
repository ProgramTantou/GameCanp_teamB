#pragma once
#include"Task.h"

//�Q�[�����̃I�u�W�F�N�g�̃x�[�X�N���X
class ObjectBase :public Task {
public:
	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos">�����ʒu</param>
	ObjectBase(const CVector2D&pos);
	//�f�X�g���N�^
	virtual ~ObjectBase();
	/// <summary>
	/// �I�u�W�F�N�g�̍��W��ݒ�
	/// </summary>
	/// <param name="pos">�ݒ肷����W</param>
	void SetPos(const CVector2D& pos);
	/// <summary>
	/// �I�u�W�F�N�g�̍��W���擾
	/// </summary>
	/// <returns>�I�u�W�F�N�g�̍��W</returns>
	const CVector2D& GetPos()const ;
	
protected:
	CVector2D m_pos;
};