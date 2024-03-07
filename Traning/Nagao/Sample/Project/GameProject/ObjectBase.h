#pragma once
#include "Task.h"

//GAME���̃I�u�W�F�N�g�̃x�[�X�N���X
class ObjectBase : public Task
{
public:
	ObjectBase(const CVector2D& pos);
	~ObjectBase();

	/// <summary>
	/// 
	/// </summary> 

	void SetPos(const CVector2D& pos);

	/// <summary>
	/// 
	/// </summary>

	const CVector2D& GetPos() const;

	virtual void Update();
	virtual void Render();

protected:
	CVector2D m_pos;
};