#pragma once
#include "ObjectBase.h"
#include <list>

class Casol :public  ObjectBase{
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�����̓G���݃t���O
	bool Enemy_flag_left;
	//�E���̓G���݃t���O
	bool Enemy_flag_right;
	//�v���C���[�̃|�C���^�[
	ObjectBase* p;
	//�G�̃|�C���^�[
	ObjectBase* e;
	std::list<ObjectBase*> lst;
public:
	//�R���X�g���N�^
	Casol();
	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;
	//�摜���]�p�t���O
	bool m_flip;
};