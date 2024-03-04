#pragma once

class Player
{
//アクセス修飾子
//自分以外の外部からアクセスし放題
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	/// <summary>
	/// プレイヤーの座標を取得
	/// </summary>
	/// <returns>プレイヤーの座標</returns>
	const CVector2D& GetPos() const;

	/// <summary>
	/// プレイヤーの座標を設定
	/// </summary>
	/// <param name="pos">設定する値</param>
	void SetPos(const CVector2D& pos);

	//更新処理
	void Update();
	//描画処理
	void Render();

//自分自身のクラスしかアクセスできない
//メンバ変数は基本private
private:
	CVector2D m_pos;     //プレイヤーの座標
	TexAnimData* mp_animData;    //アニメーションのデータ
	CImage* mp_image;    //プレイヤーの画像
	int m_hp;            //ぷれいやーのHP


//自分と自クラスの継承したクラスでアクセスできる
protected:

};