#pragma once
#include "Task.h"

#define GRAVITY (9.8f/20)
class ObjectBase : public Task
{
public:
	ObjectBase(int type);
	~ObjectBase();

	void SetPos(const CVector3D& pos);

	const CVector3D& GetPos() const;

	static CVector2D GetScreenPos(const CVector3D& pos);

	virtual void Update();
	virtual void Render();
	
	virtual bool CollisionCircle(ObjectBase* b1, ObjectBase* b2);
	virtual bool CollisionRect(ObjectBase* b1, ObjectBase* b2);
	void DrawRect();

	static CVector2D m_scroll;
	CVector3D m_pos;
	CVector3D m_vec;
	float m_rad;
	CRect m_rect;
	
};