#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	//업캐스팅
	//scene = new TutorialScene();

	//scene = new PaintScene();

	//scene = new CollisionScene();
	//scene = new AvoidGameScene();
	
	//scene = new AngleScene();
	scene = new ArkanoidScene();
}

MainGame::~MainGame()
{

}

void MainGame::Update()
{
	scene->Update();
}

void MainGame::Render(HDC hdc)
{
	scene->Render(hdc);

	//MousePos
	wstring str = L"MousePos : " + to_wstring((int)mousePos.x) + L", " + to_wstring((int)mousePos.y);
	TextOut(hdc, 0,0,str.c_str(), str.size());
}
