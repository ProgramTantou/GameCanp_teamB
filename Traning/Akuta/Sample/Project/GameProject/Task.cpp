#include "Task.h"
#include "TaskManager.h"

//�R���X�g���N�^
Task::Task(int prio)
	:m_prio(prio)
	,m_sortOrder(0)
	,m_isEnable(true)
	,m_isShow(true)
	,m_isKill(false)
{
//�^�X�N�̐����Ɠ�����TaskManager�̃��X�g�Ɏ��g��ǉ�
	TaskManager::Add(this);
}

//�f�X�g���N�^
Task::~Task()
{
	//�^�X�N�̍폜�Ɠ�����TaskManager�̃��X�g���玩�g����菜��
	TaskManager::Remove(this);
}

//�D��x��ݒ�
void Task::SetPriority(int prio)
{
	m_prio = prio;
	//1��^�X�N�̃��X�g���玩�g����菜��
	//���̌����1�x�^�X�N�̃��X�g�ɒǉ�����֐����Ăяo�����Ƃ�
	//�V�����D��x�̏ꏊ�Ƀ^�X�N��ύX����B
	TaskManager::Remove(this,true);
	TaskManager::Add(this,true);
}

//�D��x���擾
int Task::GetPriority()const
{
	return m_prio;
}

//�������Ԃ�ݒ�
void Task::SetSortOrder(int order)
{
	m_sortOrder = order;
	TaskManager::Remove(this, true);
	TaskManager::Add(this, true);
}

//�������Ԃ��擾
int Task::GetSortOrder() const
{
	return m_sortOrder;
}

//�L�����ǂ�����ݒ�
void Task::SetEnable(bool enable)
{
	m_isEnable = enable;
}

//�L�����ǂ������擾
bool Task::IsEnable() const
{
	return m_isEnable;
}

//�\������邩�ǂ�����ݒ�
void Task::SetShow(bool show)
{
	m_isShow = show;
}

//�\�����邩�ǂ������擾
bool Task::IsShow() const
{
	return m_isShow;
}

//�^�X�N���폜
void Task::Kill()
{
	m_isKill = true;
}

//�^�X�N�̍폜�t���O�������Ă��邩
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
