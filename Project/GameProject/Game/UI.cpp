#include "UI.h"
#include "Player.h"

UI::UI() : Base(eType_UI),
m_UI_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("HP",CImage);
};