#include "Field.h"

//コンストラクタ
Field::Field()
	:m_pos()
	,mp_image(nullptr)
{
	//フィールドの画像を読み込み
	mp_image = CImage::CreateImage("Field.png");
	mp_image->SetCenter(960.0f,540.0f);
	m_ground_y = 540;
}

//デストラクタ
Field::~Field() {
	//画像データを削除
	delete mp_image;
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
	//イメージに座標を設定
	mp_image->SetPos(m_pos);
}

//描画処理
void Field::Draw() {
	float sc;
	mp_image->Draw();
	//sc = m_scroll.x
}