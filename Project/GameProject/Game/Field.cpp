#include "Field.h"
#include "Enemy.h"
#include "Boss.h"
#include "GameData.h"

bool Field::Next_flag = false;

//コンストラクタ
Field::Field(int stage_number) : Task(eType_Field, (int)TaskPrio::Field)
{
	Stage_number = stage_number;
	//敵の位置制御用変数の初期化
	Enemy_pos_Control = 0;
	//次のステージに行けるかの判定用フラグの初期化
	Field::Next_flag = false;
	//フィールドナンバーによる読み込み画像の分岐
	switch (Stage_number)
	{
	case 1:
	case 2:
	case 3:
		//明るい背景
		mp_image_Back = COPY_RESOURCE("Back_1", CImage);
		mp_image_Field = COPY_RESOURCE("Field_1", CImage);
		mp_image_Pillar = COPY_RESOURCE("Pillar_1", CImage);
		break;
	case 4:
		//暗い背景
		mp_image_Back = COPY_RESOURCE("Back_2", CImage);
		mp_image_Field = COPY_RESOURCE("Field_2", CImage);
		mp_image_Pillar = COPY_RESOURCE("Pillar_2", CImage);
		break;
	}
	//ステージナンバーによる敵生成の分岐
	switch (Stage_number) {
	case 1:
		//敵1を7体,敵2を1体、敵3を1体
		for (int i = 0; i < 7; i++) {
			if (i % 3 == 0) {
				Enemy_pos_Control += 1;
			}
			new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, i * -50), 0, false);
		}
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 7 * -50), 1, false);
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 8 * -50), 2, false);
		break;
	case 2:
		//敵2を7体,敵3を1体、敵1を1体
		for (int i = 0; i < 7; i++) {
			if (i % 3 == 0) {
				Enemy_pos_Control += 1;
			}
			new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, i * -50), 1, false);
		}
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 7 * -50), 2, false);
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 8 * -50), 0, false);
		break;
	case 3:
		//敵3を7体,敵1を1体、敵2を1体
		for (int i = 0; i < 7; i++) {
			if (i % 3 == 0) {
				Enemy_pos_Control += 1;
			}
			new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, i * -50), 2, false);
		}
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 7 * -50), 0, false);
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 8 * -50), 1, false);
		break;
	case 4:
		//ボスを1体
		new Boss(CVector3D(2900, 650, -100),  false);
		break;
	default:
		break;
	}
	//地面の高さ
	m_ground_y = 800;
}

//デストラクタ
Field::~Field() {
	
}

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
	if (!TaskManager::FindObject(eType_Enemy)) {
		Field::Next_flag = true;
	}
	//if (PUSH(CInput::eButton5)) {
		//Field::Next_flag = true;
	//}
}

//描画処理
void Field::Render() {
	float sc;
	sc = ObjectBase::m_scroll.x / 4;
	mp_image_Back.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Back.Draw();

	sc = ObjectBase::m_scroll.x / 2;
	mp_image_Pillar.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Pillar.Draw();

	sc = ObjectBase::m_scroll.x;
	mp_image_Field.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Field.Draw();
}