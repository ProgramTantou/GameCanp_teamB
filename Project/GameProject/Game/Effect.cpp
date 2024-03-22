#include "Effect.h"

Effect::Effect(const char* name, const CVector3D& pos, bool flip):ObjectBase(eType_Effect)
{
	m_img = COPY_RESOURCE(name, CImage);
	m_pos = pos;
	m_img.SetSize(512 / 2, 512 / 2);
	m_img.SetCenter(512 / 4, 512 / 4);
	m_img.ChangeAnimation(0, false);
	m_flip = flip;
}

void Effect::Update()
{
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd())
	{
		Kill();
	}
}

void Effect::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}
