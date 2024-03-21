#include "Title/Title.h"
#include "Game/Casol.h"
#include "Game/Player.h"
#include"Game/Fish.h"
#include "Game/Enemy.h"
#include "Game/Task.h"
#include "Game/TaskManager.h"
#include "Game/Field.h"
#include"Game/Game.h"
#include "Game/Shadow.h"
#include"Game/AnimData.h"
#include "Game/Boss.h"
#include "Game/FrontObject.h"
//--------------------------------------------
//グローバル変数領域
//--------------------------------------------

Player* p_player = nullptr;




void MainLoop(void) {
	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------
	/*
	Base::CheckKillAll();
	Base::UpdateAll();
	Base::CollisionAll();
	Base::DrawAll();
	*/

	TaskManager::Update();
	TaskManager::Render();
	TaskManager::CollisionAll();
}
void Init(void)




{

	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'W');
	CInput::SetButton(0, CInput::eButton2, 'A');
	CInput::SetButton(0, CInput::eButton3, 'S');
	CInput::SetButton(0, CInput::eButton4, 'D');
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);
	CInput::SetButton(0, CInput::eButton6, 'C');
	CInput::SetButton(0, CInput::eButton7, 'V');
	CInput::SetButton(0, CInput::eButton8, 'B');
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, VK_UP);
	CInput::SetButton(0, CInput::eDown, VK_DOWN);
	CInput::SetButton(0, CInput::eLeft, VK_LEFT);
	CInput::SetButton(0, CInput::eRight, VK_RIGHT);
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);
	//	CInput::SetMouseInside(true);
	//	CInput::ShowCursor(false);
	CInput::Update();
	CInput::Update();

		

	SetCurrentDirectory("data");
	CSound::GetInstance();

	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	//画像の読み込みと登録　”リソース名”　　　　”ファイル名” , アニメーションデータ , 幅 , 高さ
	ADD_RESOURCE("Player", CImage::CreateImage("Image/Player.png", player_anim_data, 512, 512));
	ADD_RESOURCE("Fish_1", CImage::CreateImage("Image/fish_1.png", fish_anim_data, 512, 512));
	ADD_RESOURCE("Fish_2", CImage::CreateImage("Image/fish_2.png"));
	ADD_RESOURCE("Fish_3", CImage::CreateImage("Image/fugu.png"));
	ADD_RESOURCE("Enemy1", CImage::CreateImage("Image/dennkiusagi.png", enemy_anim_data, 512, 512));
	ADD_RESOURCE("Enemy2", CImage::CreateImage("Image/eEnemy1.png", enemy_anim_data, 512, 512));
	ADD_RESOURCE("Enemy3", CImage::CreateImage("Image/tyoutinnneko.png", enemy_anim_data, 512, 512));
	ADD_RESOURCE("Field_1", CImage::CreateImage("Image/Field_1_.png"));
	ADD_RESOURCE("Field_2", CImage::CreateImage("Image/Field_2_.png"));
	ADD_RESOURCE("Back_1", CImage::CreateImage("Image/Back_1.png"));
	ADD_RESOURCE("Back_2", CImage::CreateImage("Image/Back_2.png"));
	ADD_RESOURCE("Pillar_1", CImage::CreateImage("Image/Pillar_1.png"));
	ADD_RESOURCE("Pillar_2", CImage::CreateImage("Image/Pillar_2.png"));
	ADD_RESOURCE("Light_1", CImage::CreateImage("Image/Light_1.png"));
	ADD_RESOURCE("Light_2", CImage::CreateImage("Image/Light_2.png"));
	ADD_RESOURCE("Underwater_1", CImage::CreateImage("Image/Underwater_1.png"));
	ADD_RESOURCE("Underwater_2", CImage::CreateImage("Image/Underwater_2.png"));
	ADD_RESOURCE("HP", CImage::CreateImage("Image/HP.png"));
	ADD_RESOURCE("Box", CImage::CreateImage("Image/Frame.png"));
	ADD_RESOURCE("Cursor", CImage::CreateImage("Image/cursor.png"));
	ADD_RESOURCE("Title", CImage::CreateImage("Image/title.png"));
	ADD_RESOURCE("Resoult", CImage::CreateImage("Image/Resoult_frame.png"));
	ADD_RESOURCE("Shadow", CImage::CreateImage("Image/shadow.png"));
	//ADD_RESOURCE("Seaweed", CImage::CreateImage("Image/seaweed.png"));
	ADD_RESOURCE("Seaweed_1", CImage::CreateImage("Image/Seaweed_1.png", seaweedA,2048/4,512));
	ADD_RESOURCE("Boss", CImage::CreateImage("Image/Boss.png",boss_anim_data,512,512));
	ADD_RESOURCE("FrontObject", CImage::CreateImage("Image/jellyfish.png"));
	ADD_RESOURCE("Fish1_UI", CImage::CreateImage("Image/unagi.png"));
	ADD_RESOURCE("Fish2_UI", CImage::CreateImage("Image/tako.png"));
	ADD_RESOURCE("Fish3_UI", CImage::CreateImage("Image/fugu.png"));
	ADD_RESOURCE("EnemyBullet", CImage::CreateImage("Image/eEnemy2.png",enemy_anim_data,512,512));
	//ADD_RESOURCE("Effect", CImage::CreateImage("Image/Effect.png"));
	//ADD_RESOURCE("Sky", CImage::CreateImage("Image/Sky.png"));
	//ADD_RESOURCE("Town", CImage::CreateImage("Image/Town.png"));
	//ADD_RESOURCE("ForeGround", CImage::CreateImage("Image/ForeGround.png"));
	//ADD_RESOURCE("MapTip", CImage::CreateImage("Image/MapTip.png"));
	//ADD_RESOURCE("Effect_Slash", CImage::CreateImage("Image/Effect_Slash.png", effect_slash_anim_data, 128, 128));
	//ADD_RESOURCE("Effect_Smoke", CImage::CreateImage("Image/Effect_Smoke.png", effect_smoke_anim_data, 128, 128));
	//ADD_RESOURCE("Effect_Blood", CImage::CreateImage("Image/Effect_Blood.png", effect_blood_anim_data, 128, 128));
	//ADD_RESOURCE("Goal", CImage::CreateImage("Image/Goal.png"));
	//ADD_RESOURCE("Title", CImage::CreateImage("Image/Title.png"));

	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	new Title();

	

	//Base::Add(new Title(CVector2D(950, 600)));
	//Base::Add(new light(CVector2D(950, 600)));
	//Base::Add(new Enemy(CVector2D(1000,500)));
	


}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//画面解像度変動
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//画面解像度固定
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	Init();
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//各バッファーをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "summer");
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}