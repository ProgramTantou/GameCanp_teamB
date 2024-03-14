#pragma once
#include "Task.h"

struct CRect3D
{
	float m_left;
	float m_top;
	float m_right;
	float m_bottom;
	float m_oku;
	float m_temae;

	float m_width;
	float m_height;
	float m_Zhaba;
	CRect3D()
	{
		memset(this, 0, sizeof(CRect3D));
	}

	CRect3D(float l, float t, float r, float b, float o, float te)
	{
		m_left = l;
		m_top = t;
		m_right = r;
		m_bottom = b;
		m_oku = o;
		m_temae = te;

		m_width = m_right - m_left;
		m_height = m_bottom - m_top;
		m_Zhaba = m_oku - m_temae;
	}
};

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
		CRect3D m_rect;

	};