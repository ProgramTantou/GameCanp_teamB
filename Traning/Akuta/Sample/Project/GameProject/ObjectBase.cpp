#include "ObjectBase.h"

//�R���X�g���N�^
ObjectBase::ObjectBase(const CVector2D& pos) 
	:m_pos(pos)
{

}

//�f�X�g���N�^
ObjectBase::~ObjectBase() 
{

}

//�I�u�W�F�N�g�̍��W��ݒ�
void ObjectBase::SetPos(const CVector2D& pos) 
{
	m_pos = pos;
}

//�I�u�W�F�N�g�̍��W���擾
const CVector2D& ObjectBase::GetPos() const
{
	return m_pos;
}

void ObjectBase::Update() 
{

}

void ObjectBase::Render() 
{

}