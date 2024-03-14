#include "ObjectBase.h"
CVector2D ObjectBase::m_scroll(0, 0);

ObjectBase::ObjectBase(int type)
	:Task(type,(int)TaskPrio::Object)
	, m_pos(0,0,0)
{

}

ObjectBase::~ObjectBase()
{

}

void ObjectBase::SetPos(const CVector3D& pos)
{
	m_pos = pos;
}

const CVector3D& ObjectBase::GetPos() const
{
	return m_pos;
}

CVector2D ObjectBase::GetScreenPos(const CVector3D& pos)
{
	return CVector2D(pos.x - m_scroll.x + pos.z, pos.y - m_scroll.y - pos.z);
}



void ObjectBase::Update()
{

}

void ObjectBase::Render()
{

}

bool ObjectBase::CollisionCircle(ObjectBase* b1, ObjectBase* b2)
{
	CVector3D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	if (l < b1->m_rad + b2->m_rad)
	{
		return true;
	}
	return false;
}

bool ObjectBase::CollisionRect(ObjectBase* b1, ObjectBase* b2)
{
	//b1の矩形
	CRect3D rect1 = CRect3D(
		b1->m_pos.x + b1->m_rect.m_left,
		b1->m_pos.y + b1->m_rect.m_top,
		b1->m_pos.x + b1->m_rect.m_right,
		b1->m_pos.y + b1->m_rect.m_bottom,
		b1->m_pos.z + b1->m_rect.m_oku,
		b1->m_pos.z + b1->m_rect.m_temae);
	//b2の矩形
	CRect3D rect2 = CRect3D(
		b2->m_pos.x + b2->m_rect.m_left,
		b2->m_pos.y + b2->m_rect.m_top,
		b2->m_pos.x + b2->m_rect.m_right,
		b2->m_pos.y + b2->m_rect.m_bottom,
		b2->m_pos.z + b2->m_rect.m_oku,
		b2->m_pos.z + b2->m_rect.m_temae);

	//矩形同士の判定
	if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
		rect1.m_top <= rect2.m_bottom && rect1.m_bottom >= rect2.m_top &&
		rect1.m_oku >= rect2.m_temae && rect1.m_temae<=rect2.m_oku
		)
		return true;

	return false;
}

void ObjectBase::DrawRect()
{
	//デバッグ用　矩形の表示
	CRect3D rect = CRect3D(
		m_pos.x + m_rect.m_left,
		m_pos.y + m_rect.m_top,
		m_pos.x + m_rect.m_right,
		m_pos.y - m_rect.m_bottom,
		m_pos.z + m_rect.m_oku,
		m_pos.z + m_rect.m_temae);
	Utility::DrawQuad(
		GetScreenPos(CVector3D(rect.m_left, rect.m_top, m_pos.z)),
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(1, 0, 0, 0.5f));
}