#include "Casol.h"
#include "Game.h"

Casol::Casol() : ObjectBase(eType_UI) {
	//�摜�ǂݍ���
	m_img = COPY_RESOURCE("Cursor", CImage);
	//���S�ʒu�ݒ�
	m_img.SetCenter(100, 100);
	//�G���݃t���O�̏�����
	Enemy_flag_left = false;
	Enemy_flag_right = false;
	//���]�p�t���O�̏�����
	m_flip = false;
	//�v���C���[�̃|�C���^�[
	p = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Player));
}

void Casol::Update() {
	//�t���O�̏�����
	Enemy_flag_left = false;
	Enemy_flag_right = false;
	//���X�g�̎擾
	enemy_list = (TaskManager::FindObjects(eType_Enemy));
	for (auto& v : enemy_list) {
		//�v���C���[�̍��W�̎擾
		CVector3D Player_pos = p->GetPos();
		//�G�̍��W�̎擾
		e = dynamic_cast<ObjectBase*>(v);
		CVector3D Enemy_pos = e->GetPos();
		if (Player_pos.x > Enemy_pos.x) {
			Enemy_flag_left = true;
		}
		if (Player_pos.x < Enemy_pos.x) {
			Enemy_flag_right = true;
		}
	}
}

void Casol::Render() {
	if (Enemy_flag_left == true) {
		m_flip = true;
		m_img.SetFlipH(m_flip);
		m_img.SetPos(CVector2D(100, 540));
		m_img.Draw();
	}
	if (Enemy_flag_right == true) {
		m_flip = false;
		m_img.SetFlipH(m_flip);
		m_img.SetPos(CVector2D(1800, 540));
		m_img.Draw();
	}
}