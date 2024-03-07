#pragma once
#include "Task.h"

//全てのオブジェクトの影を描画する
class ShadowManager :public Task
{
public:
	//コンストラクタ
	ShadowManager();
	//デストラクタ
	~ShadowManager();

	//更新
	void Update() override;
	//描画
	void Render() override;

private:
	CImage* mp_image;		//影のデータ
};