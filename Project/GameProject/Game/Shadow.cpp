#include "Shadow.h"
#include "Game.h"

Shadow::Shadow(const CVector2D& p) : ObjectBase(eType_UI) {
	m_img = COPY_RESOURCE("Cursor", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	select_mode = 1;
	m_pos.x = 600;
	m_pos.y = 900;
}

void Shadow::Update() {
	//ƒ‚[ƒh‘I‘ğˆ—
	
}

void Shadow::Render() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}