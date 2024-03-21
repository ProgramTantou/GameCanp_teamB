#pragma once
#include "Task.h"
#include "TaskManager.h"
#include "ObjectBase.h"

class Field : public Task {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="Field_Nunber">フィールド画像の分岐</param>
	Field(int Field_Nunber);
	//デストラクタ
	~Field();
	//更新処理
	void Update() override;
	//描画処理
	void Render() override;

	/// <summary>
	/// フィールドの高さを取得
	/// </summary>
	/// <returns>フィールドの高さ</returns>
	const float GetGroundY();

	static bool Next_flag; //次のステージに行けるかの判定用フラグ
private:
	CVector2D m_pos;  //フィールドの座標
	CImage mp_image_Back; //背景の画像
	CImage mp_image_Field; //フィールドの画像
	CImage mp_image_Pillar; //柱の画像
	float m_ground_y; //フィールドの当たり判定
	int Field_number; //フィールドの種類判別用変数
	int Stage_number = 1; //ステージの判別用の変数
	int Enemy_pos_Control; //敵の位置制御用の変数
protected:

};
