#pragma once
#include "CharaBase.h"

class Slime : public CharaBase
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

	void Update() override;

	void Render() override;
	/// <summary>
	/// プレイヤーの座標を決定
	/// </summary>
	/// <returns>プレイヤーの座標を取得</returns>

	/// <summary>
	/// プレイヤーの座標を決定
	/// </summary>
	/// <param name="pos"></param>
	//アクセス修飾子
	//自分自身のクラスしかアクセスできない。
private:
	TexAnimData* mp_anim;
	CImage* mp_image;//プレイヤーの画像
	int m_type;
	//自分と自クラスを継承したクラスからアクセス可能
};