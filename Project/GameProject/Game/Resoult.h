#pragma once
#include "ObjectBase.h"
#include "TaskManager.h"

class Resoult : public ObjectBase
{
private:
	CImage m_img; //画像オブジェクト
	CFont m_font; //文字オブジェクト大
	CFont m_font2; //文字オブジェクト小
	int coro = 0; //1でゲームオーバー、2でゲームクリア

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="CorO">ゲームオーバーかゲームクリアか</param>
	Resoult(int CorO);
	//デストラクタ
	~Resoult();
	//更新処理
	void Update() override;
	//描画処理
	void Render() override;
};