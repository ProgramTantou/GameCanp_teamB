#include "Field.h"

//コンストラクタ
Field::Field() :Base(eType_Field)
	,m_pos(960.0f,540.0f)
	//,mp_image(nullptr)
{
	mp_image = COPY_RESOURCE("Field", CImage);
	
	m_ground_y = 540;
}

//デストラクタ
Field::~Field() {
	
}

//フィールドの座標を取得
/*const CVector2D& Field::GetPos() const {
	
}*/

//フィールドの座標を設定
void Field::SetPos(const CVector2D& pos) {
	m_pos = pos;
}

//フィールドの高さを取得
const float Field::GetGroundY(){
	return m_ground_y;
}

//更新処理
void Field::Update() {
	
}

//描画処理
void Field::Draw() {
	float sc;
	mp_image.Draw();
	//sc = m_scroll.x
}