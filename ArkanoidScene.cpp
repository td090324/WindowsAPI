#include "Framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	player = new ArkaPlayer();
}

ArkanoidScene::~ArkanoidScene()
{
	delete player;
}

void ArkanoidScene::Update()
{
	player->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	player->Render(hdc);
}
