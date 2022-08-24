#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	//��ĳ����
	//scene = new TutorialScene();

	//scene = new PaintScene();

	scene = new CollisionScene();
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
}
