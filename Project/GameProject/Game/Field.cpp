#include "Field.h"
#include "Enemy.h"
#include "Boss.h"
#include "GameData.h"

bool Field::Next_flag = false;

//コンストラクタ
Field::Field(int Field_Nunber) : Task(eType_Field, (int)TaskPrio::Field)
	//,mp_image(nullptr)
{
	//敵の位置制御用変数の初期化
	Enemy_pos_Control = 0;
	//フィールドナンバーの代入
	Field_number = Field_Nunber;
	//次のステージに行けるかの判定用フラグの初期化
	Field::Next_flag = false;
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
	//ゲームクリアでもなくゲームオーバーでもないなら
	if (GameData::clear_flag == false && GameData::death_flag == false) {
		//削除される度にステージナンバー+1
		Stage_number += 1;
		//ステージナンバーが4より小さいなら
		if (Stage_number < 4) {
			//明るい背景のステージを生成
			new Field(1);
		}
		//ステージナンバーが4なら
		else if (Stage_number == 4) {
			//暗い背景のステージを生成
			new Field(2);
		}
		//それ以外のナンバーなら
		else {
			//何もしない
		}
	}
	//ゲームクリアかゲームオーバーなら
	else {
		//ステージナンバーの初期化
		Stage_number = 1;
	}
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
}

//描画処理
void Field::Render() {
	float sc;
	sc = ObjectBase::m_scroll.x;
	mp_image.SetRect(sc, 0, sc + 1920, 1080);
	mp_image.Draw();
}