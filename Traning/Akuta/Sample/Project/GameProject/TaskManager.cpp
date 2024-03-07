#include "TaskManager.h"
#include "Task.h"
#include "ObjectBase.h"

//�^�X�N�̃��X�g���`
std::list<Task*>TaskManager::m_taskList;
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
	//�\�[�g���̃^�X�N�ǉ��̌Ăяo���łȂ���΁A
	if (!isSort)
	{
		//�ǉ�����^�X�N�̗D��x���I�u�W�F�N�g�p�ł���΁A
		//�I�u�W�F�N�g���X�g�ɒǉ�
		if (add->m_prio == (int)TaskPrio::Object)
		{
			m_objectList.push_back(add);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* task = *itr;
		//�ǉ�����^�X�N�̗D��x�����݂̃^�X�N�̗D��x�Ȃ�΁A
		//���̈ʒu�Ƀ^�X�N��ǉ��B
		if (add->m_prio < task->m_prio)
		{
			m_taskList.insert(itr, add);
			return;
		}
		//�ǉ�����^�X�N�̗D��x�ƌ��݂̃^�X�N�̗D��x�������Ȃ�΁A
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
	//�Ō�܂Œǉ�����ꏊ��������Ȃ������ꍇ�́A
	//���X�g�̈�Ԍ��ɒǉ�����
	m_taskList.push_back(add);
}

//�^�X�N�����X�g�����菜��
void TaskManager::Remove(Task* remove, bool isSort)
{
	//�\�[�g���̌Ăяo���ł͂Ȃ�
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
void TaskManager::Delete(Task* del)
{
	//�폜����^�X�N���I�u�W�F�N�g�ł���΁A�I�u�W�F�N�g���X�g�����菜��
	if (del->m_prio == (int)TaskPrio::Object)
	{
		m_objectList.remove(del);
	}

	//�폜����Ƃ��́A��Ƀ��X�g�����菜���Ă���폜����B
	m_taskList.remove(del);
	delete del;
}

//���X�g���̃^�X�N�����ׂč폜
void TaskManager::DeleteAll()
{
	//�S�č폜����̂ŁA�I�u�W�F�N�g���X�g�̒��g��S�ăN���A����
	m_objectList.clear();

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* del = *itr;
		//���X�g�����菜���Ă���A�^�X�N���폜
		itr = m_taskList.erase(itr);
		delete del;
	}
}


const std::list<Task*>& TaskManager::GetObjectList()
{
	return m_objectList;
}

//�X�V
void TaskManager::Update()
{
	//�폜�t���O�̗����Ă���^�X�N���폜
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* task = *itr;
		if (task->m_isKill)
		{
			itr = m_taskList.erase(itr);
			delete task;
		}
		//�폜�t���O�������Ă��Ȃ���΁A���̃^�X�N��
		else
		{
			itr++;
		}
	}

	//���ׂẴ^�X�N���X�V
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

//�`��
void TaskManager::Render()
{
	//�I�u�W�F�N�g���X�g�̒��̃I�u�W�F�N�g��
	//���s�̍��W�ŕ��ёւ���
	m_objectList.sort
	(
		//�����_��
		[](const Task* taskA, const Task* taskB)
		{
			const ObjectBase* objA = dynamic_cast<const ObjectBase*>(taskA);
			const ObjectBase* objB = dynamic_cast<const ObjectBase*>(taskB);
			return objA->GetPos().y < objB->GetPos().y;
		}
	);

	//�I�u�W�F�N�g���X�g�̏��Ԃɏ������Ԃ̔ԍ���ݒ肷��
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
		if (task->m_isEnable && task->m_isShow)
		{
			task->Render();
		}
		itr++;
	}
}