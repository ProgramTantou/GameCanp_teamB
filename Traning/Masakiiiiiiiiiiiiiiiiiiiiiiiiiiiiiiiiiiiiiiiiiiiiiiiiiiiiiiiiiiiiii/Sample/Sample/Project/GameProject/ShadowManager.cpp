#include "ShadowManager.h"
#include "TaskManager.h"
#include "Game/ObjectBase.h"

//コンストラクタ
ShadowManager::ShadowManager()
	:Task((int)TaskPrio::Shadow) 
	,mp_image(nullptr) {
	//影の画像を読み込む
	mp_image = CImage::CreateImage("shadow.png");
	mp_image->SetCenter(52.0f, 16.0f);
}

//デストラクタ
ShadowManager::~ShadowManager() {
	delete mp_image;
}

//更新
void ShadowManager::Update() {

}

//描画
void ShadowManager::Render() {
	//オブジェクトリストを取得
	auto& objects = TaskManager::GetObjectList();
	for (Task* task : objects) {
		ObjectBase* obj = dynamic_cast<ObjectBase*>(task);
		if (obj == nullptr) continue;

		//各オブジェクトの座標に影の画像を描画
		mp_image->SetPos(obj->GetPos());
		mp_image->Draw();
	}
}