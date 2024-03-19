#include "Fade.h"

//コンストラクタ
Fade::Fade() : Task(eType_Scene, (int)TaskPrio::Fade) {
	//タイムの初期化
	time = 0;
	//アルファ値の初期化
	Arufa = 0.00;
	//アルファ値制御用のフラグ
	Arufa_flag = false;
}

//更新処理
void Fade::Update() {
	//アルファフラグが立っておらずアルファ値が1より小さいなら
	if(Arufa_flag == false && Arufa < 1.00){
		//1フレーム毎にアルファ値+0.05
		Arufa += 0.05;
	}
	//アルファ値が1以上なら
	if (Arufa >= 1.0) {
		//1フレーム毎にtime+1
		time++;
		//2秒経ったら
		if (time == 120){
			//アルファフラグを立て
			Arufa_flag = true;
			//timeを初期化
			time = 0;
		}
	}
	//アルファフラグが立っていたら
	if (Arufa_flag == true) {
		//1フレーム毎にアルファ値-0.05
		Arufa -= 0.05;
		//アルファ値が0になったら
		if (Arufa <= 0.00) {
			//Fadeクラスを削除
			Kill();
		}
	}
}

//描画処理
void Fade::Render() {
	//黒の描画
	Utility::DrawQuad(CVector2D(0, 0), CVector2D(SCREEN_WIDTH, SCREEN_HEIGHT), CVector4D(0, 0, 0, Arufa));
}