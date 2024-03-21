#pragma once
#include "ObjectBase.h"
#include <list>

class Casol :public  ObjectBase{
private:
	//画像オブジェクト
	CImage m_img;
	//左側の敵存在フラグ
	bool Enemy_flag_left;
	//右側の敵存在フラグ
	bool Enemy_flag_right;
	//プレイヤーのポインター
	ObjectBase* p;
	//敵のポインター
	ObjectBase* e;
	std::list<ObjectBase*> lst;
public:
	//コンストラクタ
	Casol();
	//更新処理
	void Update() override;
	//描画処理
	void Render() override;
	//画像反転用フラグ
	bool m_flip;
};