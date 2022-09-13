#include "Framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	player = new ArkaPlayer();
	
	bricks = new BrickManager();

	ball = new Ball();
	ball->SetPlayer(player);
	ball->SetBricks(bricks);
}

ArkanoidScene::~ArkanoidScene()
{
	delete player;
	delete ball;
	//delete brick;
	delete bricks;
}

void ArkanoidScene::Update()
{
	player->Update();
	  ball->Update();
	 //brick->Update();

}

void ArkanoidScene::Render(HDC hdc)
{
	player->Render(hdc);
	  ball->Render(hdc);
	 //brick->Render(hdc);

	 bricks->Render(hdc);
}
