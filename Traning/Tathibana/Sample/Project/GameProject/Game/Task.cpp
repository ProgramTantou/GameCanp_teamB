#include "Task.h"
#include"TsakManager.h"

//�R���X�g���N�^
Task::Task(int prio):m_prio(prio),m_sortOrder(0),m_isEnable(true),m_isShow(true),m_isKill(false)
{
	//�^�X�N�̐����Ɠ�����TaskManager�Ƀ��X�g�Ɏ��g��ǉ�
	TaskManager::Add(this);
}
//�f�X�g���N�^
Task::~Task()
{
	//�^�X�N�̍폜�Ɠ�����TaskMansger�̃��X�g���玩�g����菜��
	TaskManager::Remove(this);
}
//�D��x��ݒ�
void Task::SetPriority(int prio)
{
	m_prio = prio;
	//�P��^�X�N�̃��X�g���玩�g�����o��
	//���̌�^�X�N�̃��X�g�Ɏ��g��ǉ�
	//�V�����D��x�̏ꏊ�ɕύX
	TaskManager::Remove(this,true);
	TaskManager::Add(this,true);
}
//�D��x���擾
int Task::GetPriorty() const
{
	return m_prio;
}
//�������Ԃ�ݒ�
void Task::SetSortOrder(int order)
{
	//�������ԕύX��A���X�g���̕��ёւ����s��
	m_sortOrder = order;
	TaskManager::Remove(this,true);
	TaskManager::Add(this,true);
}
//�������Ԃ��擾
int Task::GetSortOrder() const
{
	return m_sortOrder;
}
//�L���̐ݒ�
void Task::SetEnable(bool enable)
{
	m_isEnable = enable;
}
//�L���̐^�U
bool Task::IsEnable() const
{
	return m_isEnable;
}
//�\���̐ݒ�
void Task::SetShow(bool show)
{
	m_isShow = show;
}
//�\���̐^�U
bool Task::IsShow() const
{
	return m_isKill;
}
//�^�X�N���폜
void Task::Kill()
{
	m_isKill = true;
}
//�^�X�N�̍폜�t���O
bool Task::IsKill() const
{
	return m_isKill;
}

//�X�V
void Task::Update()
{
}
//�`��
void Task::Render()
{
}
