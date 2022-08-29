#include "Framework.h"
#include "AvoidGameScene.h"

AvoidGameScene::AvoidGameScene()
{
	srand((UINT)time(NULL));


}

AvoidGameScene::~AvoidGameScene()
{
	for (Poo* poo : objects)
	{
		delete poo;
	}
}

void AvoidGameScene::Update()
{
	if (cooltime > randomTime)
	{
		cooltime = 0;
		randomTime = rand() % 50 + 200;

		Poo* poo = new Poo();
		objects.push_back(poo);
	}

	cooltime++;

	for (Poo* poo : objects)
	{
		poo->Update();
	}
}

void AvoidGameScene::Render(HDC hdc)
{
	for (Poo* poo : objects)
	{
		poo->Render(hdc);
	}
}


