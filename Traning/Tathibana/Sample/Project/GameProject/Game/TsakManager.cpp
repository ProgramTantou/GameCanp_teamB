#include "TsakManager.h"
#include"Task.h"
#include"ObjectBase.h"

//�^�X�N�̃��X�g���`
std::list<Task*> TaskManager::m_taskList;
//�I�u�W�F�N�g�̃��X�g���`
std::list<Task*>TaskManager::m_objectList;
//�R���X�g���N�^
TaskManager::TaskManager()
{

}
//�f�X�g���N�^
TaskManager::~TaskManager() 
{

}
//�^�X�N�����X�g�ɒǉ�
void TaskManager::Add(Task* add, bool isSort)
{
	if (!isSort)
	{
		//�ǉ�����D��x���I�u�W�F�N�g�p�Ȃ�I�u�W�F�N�g���X�g�ɒǉ�
		if (add->m_prio == (int)TaskPrio::Object)
		{
			m_objectList.push_back(add);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while(itr!=end)
	{
		Task* task = *itr;
		//�ǉ�����^�X�N�̗D��x�����݂̃^�X�N
		//���̈ʒu�Ƀ^�X�N��ǉ�
		if(add->m_prio<task->m_prio)
		{
			m_taskList.insert(itr, add);
			return;
		}
		//�ǉ�����^�X�N�ƌ��݂̃^�X�N�̗D��x�������Ȃ�
		else if (add->m_prio == task->m_prio) 
		{
			//�������Ԃ����������ɕ��ׂ�
			if (add->m_sortOrder < task->m_sortOrder) 
			{
				m_taskList.insert(itr, add);
				return;
			}
		}
		itr++;
	}
	//�Ō�܂Œǉ�����ꏊ��������Ȃ��ꍇ
	//���X�g�̍Ō���ɒǉ�����
	m_taskList.push_back(add);
}
//�^�X�N�����X�g���珜��
void TaskManager::Remove(Task* remove, bool isSort)
{
	//�\�[�g�̌Ăяo�����ł͂Ȃ�
	if (!isSort) 
	{
		//�D��x���I�u�W�F�N�g�p�ł���΁A�I�u�W�F�N�g���X�g�������菜��
		if (remove->m_prio == (int)TaskPrio::Object) 
		{
			m_objectList.remove(remove);
		}
	}
	m_taskList.remove(remove);
}
//�^�X�N���폜
void TaskManager::Delet(Task* del)
{
	//�o�������X�g
	// �폜����^�X�N���I�u�W�F�N�g�p�ł���΁A�I�u�W�F�N�g���X�g�����菜��
	if (del->m_prio == (int)TaskPrio::Object) {
		m_objectList.remove(del);
	 }
	 
	
	//�폜�̍ہA��Ƀ��X�g���珜�O���Ă���폜����
	m_taskList.remove(del);
	delete del;
}
//���X�g���̃^�X�N�����ׂč폜
void TaskManager::DeleteAll()
{
	//�I�u�W�F�N�g���X�g�Ƃ̒��g�����ׂăN���A����
	m_objectList.clear();
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end) 
	{
		Task* del = *itr;
		itr = m_taskList.erase(itr);
		delete del;
	}
}

const std::list<Task*>& TaskManager::GetObjectList() 
{
	return m_objectList;
}



//���X�g���̑S�^�X�N�̍X�V�������Ăяo��
void TaskManager::Update()
{
	//�폜�t���O�������Ă���^�X�N���폜
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr!=end) 
	{
		Task* task = *itr;
		//�폜�t���O�������Ă���΍폜
		if (task->m_isKill)
		{
			itr = m_taskList.erase(itr);
			delete task;
		}
		else {
			itr++;
		}
	}

		itr = m_taskList.begin();
		end = m_taskList.end();
	while (itr != end) 
	{
		Task* task = *itr;
		//�^�X�N���L���ł���΁A�X�V�������Ăяo��
		if (task->m_isEnable)
		{
			task->Update();
		}
		itr++;
	}
}
//���X�g���̑S�^�X�N�̕`�揈�����Ăяo��
void TaskManager::Render()
{
	m_objectList.sort
	(
		[](const Task*taskA,const Task*taskB)
		{
			const ObjectBase* objA = dynamic_cast<const ObjectBase*>(taskA);
			const ObjectBase* objB = dynamic_cast<const ObjectBase*>(taskB);
			return objA->GetPos().y < objB->GetPos().y;
		}
	);

	int sortOrder = 0;
	for (auto& obj : m_objectList)
	{
		obj->SetSortOrder(sortOrder);
		sortOrder++;
	}
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* task = *itr;
		//�^�X�N���L�����\������ݒ�ł���΁A�`�揈�����Ăяo��
		if (task->m_isEnable&&task->m_isShow)
		{
			task->Render();
		}
		itr++;
	}
}
