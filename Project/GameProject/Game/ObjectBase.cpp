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
	//b1�̋�`
	CRect rect1 = CRect(
		b1->m_pos.x + b1->m_rect.m_left,
		b1->m_pos.y + b1->m_rect.m_top,
		b1->m_pos.x + b1->m_rect.m_right,
		b1->m_pos.y + b1->m_rect.m_bottom);
	//b2�̋�`
	CRect rect2 = CRect(
		b2->m_pos.x + b2->m_rect.m_left,
		b2->m_pos.y + b2->m_rect.m_top,
		b2->m_pos.x + b2->m_rect.m_right,
		b2->m_pos.y + b2->m_rect.m_bottom);

	//��`���m�̔���
	if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
		rect1.m_top <= rect2.m_bottom && rect1.m_bottom >= rect2.m_top)
		return true;

	return false;
}

void ObjectBase::DrawRect()
{
	//�f�o�b�O�p�@��`�̕\��
	CRect rect = CRect(
		m_pos.x + m_rect.m_left,
		m_pos.y + m_rect.m_top,
		m_pos.x + m_rect.m_right,
		m_pos.y + m_rect.m_bottom);
	Utility::DrawQuad(
		GetScreenPos(CVector3D(rect.m_left, rect.m_top, m_pos.z)),
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(1, 0, 0, 0.5f));
}