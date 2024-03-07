#include"Shadow.h"
#include"TsakManager.h"
#include"ObjectBase.h"

Shadow::Shadow():Task((int)TaskPrio::Shadow),mp_image(nullptr)
{

	mp_image = CImage::CreateImage("shadow.png");
	mp_image->SetCenter(52.0f, 16.0f);
}

Shadow::~Shadow() 
{
	delete mp_image;
}

void Shadow::Update() 
{

}

void Shadow::Render() 
{
	auto& objects = TaskManager::GetObjectList();
	for (Task* task : objects) {
		ObjectBase* obj = dynamic_cast<ObjectBase*>(task);
		//�e�I�u�W�F�N�g�̍��W�ɉe�̉摜��`��
		mp_image->SetPos(obj->GetPos());
		mp_image->Draw();
	}
}