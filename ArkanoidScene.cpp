#include "Framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	player = new ArkaPlayer();
	ball = new Ball();
	ball->SetPlayer(player);
}

ArkanoidScene::~ArkanoidScene()
{
	delete player;
	delete ball;
}

void ArkanoidScene::Update()
{
	player->Update();
	ball->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	player->Render(hdc);
	ball->Render(hdc);
}
