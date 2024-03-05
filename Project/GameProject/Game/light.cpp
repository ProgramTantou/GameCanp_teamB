#include "light.h"

light::light(const CVector2D& p) :Base(eType_Title) {
	m_img.Load("Image/カーソル.png");
	m_rad = 15;
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	m_pos = p;

	typedef struct {
		double x;
		double y;
	}Point;
}

void rotate(Point* p, double theta)
{
	double x = p->x;
	double y = p->y;
	p->x = cos(theta) * x - sin(theta) * y;
	p->y = sin(theta) * x + cos(theta) * y;
}

void light::Update() {
	typedef struct {
		double x;
		double y;
	}Point;
	//モード選択処理
	Point rect[4] =
	{
		{0.0,0.0},
		{1.0,0.0},
		{1.0,1.0},
		{0.0,1.0},
	};
	double theta = M_PI / 4;
	for (int i = 0; i < 4; i++)
	{
		rotate(&rect[i], theta);
		printf("%d:%f,%f\n", i, rect[i].x, rect[i].y);
	}
	
	
}

void light::Draw() {
	m_img.SetPos((m_pos));
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}