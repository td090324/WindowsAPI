#include "Framework.h"
#include "AngleScene.h"

AngleScene::AngleScene()
{
	tank = new Tank();
}

AngleScene::~AngleScene()
{
	delete tank;
}

void AngleScene::Update()
{
	tank->Update();
}

void AngleScene::Render(HDC hdc)
{
	tank->Render(hdc);
}
