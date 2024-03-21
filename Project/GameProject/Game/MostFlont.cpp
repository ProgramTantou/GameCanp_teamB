#include "MostFront.h"

//コンストラクタ
MostFront::MostFront(int Field_Number) : ObjectBase(eType_MostFront) {
	//引数の代入
	Field_number = Field_Number;
	//カウントの初期化
	count = 0;
	count2 = 0;
	//引数による読み込み画像の分岐
	switch (Field_number) {
	case 1:
		mp_image_Light = COPY_RESOURCE("Light_1", CImage);
		mp_image_Underwater = COPY_RESOURCE("Underwater_1", CImage);
		break;
	case 2:
		mp_image_Light = COPY_RESOURCE("Light_2", CImage);
		mp_image_Underwater = COPY_RESOURCE("Underwater_2", CImage);
		break;
	default:
		break;
	}
}

//更新処理
void MostFront::Update() {
	//呼び出し毎にそれぞれのカウントに+1
	count++;
	count2++;
}

//描画処理
void MostFront::Render() {
	//スクロール値
	float sc;
	//波の揺れの表現
	sc = ObjectBase::m_scroll.x + sin(DtoR(count)) * 16;
	mp_image_Underwater.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Underwater.Draw();
	//光の強弱の表現
	sc = ObjectBase::m_scroll.x;
	mp_image_Light.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Light.SetColor(1, 1, 1, 0.2 + sin(DtoR(count2)) * 0.1);
	mp_image_Light.Draw();
}