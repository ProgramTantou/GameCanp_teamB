#pragma once
#include "ObjectBase.h"

class Casol :public  ObjectBase{
private:
	CImage m_img;

public:
	int select_mode=1;//���ݑI�𒆂̃��[�h
	int cnt = 0;//���̐������P�ȏゾ�ƁA�J�[�\���𑀍�ł��Ȃ��B

	bool selectOK = true;//���ꂪtrue�̊ԃ��[�h��I���ł���B

	Casol(const CVector2D& pos);
	void Update() override;
	void Render() override;
};