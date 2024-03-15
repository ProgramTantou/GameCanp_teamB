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
		if (obj->m_type == eType_Fish)
		{
		m_img.SetSize(50, 50);
		m_img.SetCenter(25, 25);
		m_img.SetPos(obj->GetScreenPos(CVector3D(obj->m_pos.x, 800, obj->m_pos.z)));
		m_img.Draw();
		}
		else
		{
			m_img.SetSize(200, 200);
			m_img.SetCenter(100, 100);
			m_img.SetPos(obj->GetScreenPos(CVector3D(obj->m_pos.x, 750, obj->m_pos.z)));
			m_img.Draw();
		}
	}
}