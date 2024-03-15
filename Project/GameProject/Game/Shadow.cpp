#include "Shadow.h"
#include "Game.h"
#include "TaskManager.h"
#include "ObjectBase.h"

Shadow::Shadow() : Task(eType_UI,(int)TaskPrio::Shadow) {
	m_img = COPY_RESOURCE("Shadow", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
}

void Shadow::Update() {
	
}

void Shadow::Render() {
	auto& object = TaskManager::GetObjectList();
	for (Task* task : object)
	{
		ObjectBase* obj = dynamic_cast<ObjectBase*>(task);
		if (obj == nullptr) continue;
		m_img.SetPos(obj->GetScreenPos(CVector3D(obj->m_pos.x, obj->m_pos.y+100, obj->m_pos.z)));
		m_img.Draw();
	}
}