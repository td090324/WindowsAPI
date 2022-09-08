#include "Framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	player = new ArkaPlayer();
	
	ball = new Ball();
	ball->SetPlayer(player);

	//brick = new Brick(WIN_CENTER, { 50,20 });

	bricks = new BrickManager();
	ball->SetBrickManager(bricks->GetBricks());
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

	 bricks->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	player->Render(hdc);
	  ball->Render(hdc);
	 //brick->Render(hdc);

	 bricks->Render(hdc);
}
