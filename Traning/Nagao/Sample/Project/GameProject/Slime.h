#pragma once

class Slime
{

	//自分自身の外部からアクセス可能
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="type">スライムの種類</param>
	/// <param name="pos">初期位置</param>
	Slime(int type, const CVector2D& pos);
	//コンストラクタ
	const CVector2D& GetPos() const;
	//デストラクタ
	~Slime();

	void Update();

	void Render();
	/// <summary>
	/// プレイヤーの座標を決定
	/// </summary>
	/// <returns>プレイヤーの座標を取得</returns>
	void GetStatus(int* hp, int* atk);

	/// <summary>
	/// プレイヤーの座標を決定
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(CVector2D pos);
	//アクセス修飾子
	//自分自身のクラスしかアクセスできない。
private:
	CVector2D m_pos;//プレイヤーの座標
	TexAnimData* mp_anim;
	CImage* mp_image;//プレイヤーの画像
	int m_hp;
	int m_type;
	//自分と自クラスを継承したクラスからアクセス可能
};