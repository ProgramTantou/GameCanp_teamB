#pragma once

class Player
{

	//自分自身の外部からアクセス可能
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	void Update();

	void Render();
	/// <summary>
	/// プレイヤーの座標を決定
	/// </summary>
	/// <returns>プレイヤーの座標を取得</returns>
	const CVector2D& GetPos();

	/// <summary>
	/// プレイヤーの座標を決定
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(CVector2D& pos);

	void GetStatus(int* hp, int* atk);
	//アクセス修飾子
	//自分自身のクラスしかアクセスできない。
private:
	CVector2D m_pos;//プレイヤーの座標
	TexAnimData* mp_anim;
	CImage* mp_image;//プレイヤーの画像
	int m_hp;
	//自分と自クラスを継承したクラスからアクセス可能
};