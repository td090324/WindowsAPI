#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
	plane = new Plane();
	enemy = new Ufo();
}

ShootingScene::~ShootingScene()
{
	delete plane;
	delete enemy;
}

void ShootingScene::Update()
{
	plane->Update();
	enemy->Update();
}

void ShootingScene::Render(HDC hdc)
{
	plane->Render();
	enemy->Render();
}
