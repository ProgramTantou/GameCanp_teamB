#pragma once
#include<list>

class Task;
//�^�X�N���Ǘ�����N���X
class TaskManager
{
public:
	/// <summary>
	/// �^�X�N�����X�g�ɒǉ�
	/// </summary>
	/// <param name="add">�ǉ�����^�X�N�̃|�C���^�[</param>
	/// <param name="isSort">�\�[�g���̌Ăяo���^�U</param>
	static void Add(Task* add,bool isSort=false);
	/// <summary>
	/// �^�X�N�����X�g�����菜��
	/// </summary>
	/// <param name="remove">��菜���^�X�N�̃|�C���^�\</param>
	/// <param name="isSort">�\�[�g���̌Ăяo���^�U</param>
	static void Remove(Task* remove,bool isSort=false);
	/// <summary>
	/// �^�X�N���폜
	/// </summary>
	/// <param name="del">�폜�X�^�X�N�̃|�C���^�[</param>
	static void Delet(Task* del);
	//���X�g���̃^�X�N�����ׂč폜
	static void DeleteAll();
	/// <summary>
	/// �I�u�W�F�N�g���X�g���擾
	/// </summary>
	/// <returns></returns>
	static const std::list<Task*>& GetObjectList();

	//���X�g���̑S�^�X�N�̍X�V�������Ăяo��
	static void Update();
	//���X�g���̑S�^�X�N�̕`�揈�����Ăяo��
	static void Render();



private:
	//�R���X�g���N�^
	TaskManager();
	//�f�X�g���N�^
	~TaskManager();
	//���ݐ�������Ă���^�X�N�̃��X�g
	static std::list<Task*>m_taskList;
	//���ݐ�������Ă���I�u�W�F�N�g�̃��X�g
	static std::list<Task*> m_objectList;
};
