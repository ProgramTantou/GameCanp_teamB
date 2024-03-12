#pragma once
#include "Task.h"
#include "ObjectBase.h"

class Field : public Task {
public:
	//コンストラクタ
	Field();
	//デストラクタ
	~Field();

	/// <summary>
	/// フィールドの座標を取得
	/// </summary>
	/// <returns>フィールドの座標</returns>
	//const CVector2D& GetPos() const;

	/// <summary>
	/// フィールドの座標を設定
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(const CVector2D& pos);

	//更新処理
	void Update() override;
	//描画処理
	void Render() override;

	/// <summary>
	/// フィールドの高さを取得
	/// </summary>
	/// <returns>フィールドの高さ</returns>
	const float GetGroundY();

private:
	CVector2D m_pos;  //フィールドの座標
	CImage mp_image; //フィールドの画像
	float m_ground_y; //フィールドの当たり判定

protected:

};
