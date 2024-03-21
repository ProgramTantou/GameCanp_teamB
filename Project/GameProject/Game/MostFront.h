#pragma once
#include "ObjectBase.h"

class MostFront : public ObjectBase {
public:
	//光オブジェクトの画像データ
	CImage mp_image_Light;
	//水中オブジェクトの画像データ
	CImage mp_image_Underwater;
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="Field_Number">表示画像の分岐</param>
	MostFront(int Field_Number);
private:
	//更新処理
	void Update() override;
	//描画処理
	void Render() override;
	//読み込み画像分岐用の変数
	int Field_number;
	//水中の表現用変数
	int count;
	//光の表現用変数
	int count2;
};
