#include "Field.h"


//コンストラクタ
Field::Field(int Field_Nunber) : Task(eType_Field, (int)TaskPrio::Field)
	//,mp_image(nullptr)
{
	Field_number = Field_Nunber;
	switch (Field_number)
	{
	case 1:
		mp_image = COPY_RESOURCE("Field_1", CImage);
		break;
	case 2:
		mp_image = COPY_RESOURCE("Field_2", CImage);
		break;
	}
	
	m_ground_y = 800;
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
void Field::Render() {
	float sc;
	sc = ObjectBase::m_scroll.x;
	mp_image.SetRect(sc, 0, sc + 1920, 1080);
	mp_image.Draw();
}