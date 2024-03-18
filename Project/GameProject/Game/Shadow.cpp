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
		if (obj->m_type != eType_Field && obj->m_type != eType_Title && obj->m_type != eType_UI && obj->m_type != eType_Scene && obj->m_type != eType_Door && obj->m_type != eType_FishManager)
		{
			if (obj->m_type == eType_Fish || obj->m_type == eType_Enemy_Attack || obj->m_type == eType_Player_Attack)
			{
				m_img.SetSize(75, 75);
				m_img.SetCenter(25, 25);
				m_img.SetPos(obj->GetScreenPos(CVector3D(obj->m_pos.x+50, 800, obj->m_pos.z)));
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
}