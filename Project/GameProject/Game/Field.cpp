#include "Field.h"
#include "Enemy.h"
#include "Boss.h"

int Field::Stage_number = 1;

//コンストラクタ
Field::Field(int Field_Nunber) : Task(eType_Field, (int)TaskPrio::Field)
	//,mp_image(nullptr)
{
	//フィールドナンバーの代入
	Field_number = Field_Nunber;
	//フィールドナンバーによる読み込み画像の分岐
	switch (Field_number)
	{
	case 1:
		//明るい背景
		mp_image = COPY_RESOURCE("Field_1", CImage);
		break;
	case 2:
		//暗い背景
		mp_image = COPY_RESOURCE("Field_2", CImage);
		break;
	}
	//ステージナンバーによる敵生成の分岐
	switch (Field::Stage_number) {
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	default:
		break;
	}
	//地面の高さ
	m_ground_y = 800;
}

//デストラクタ
Field::~Field() {
	//削除される度にステージナンバー+1
	Field::Stage_number += 1;
	//ステージナンバーが4より小さいなら
	if (Field::Stage_number < 4) {
		//明るい背景のステージを生成
		new Field(1);
	}
	//ステージナンバーが4なら
	else if(Field::Stage_number == 4) {
		//暗い背景のステージを生成
		new Field(2);
	}
	//それ以外のナンバーなら
	else {
		//何もしない
	}
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