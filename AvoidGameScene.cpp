#include "Framework.h"
#include "AvoidGameScene.h"

AvoidGameScene::AvoidGameScene()
{
	srand((UINT)time(NULL));

	player = new AvoidPlayer();
}

AvoidGameScene::~AvoidGameScene()
{
	for (Poo* poo : objects)
	{
		delete poo;
	}

	delete player;
}

void AvoidGameScene::Update()
{
	if (!isPlay)
		return;

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

	player->Update();

	Collision();
}

void AvoidGameScene::Render(HDC hdc)
{
	if (!isPlay)
	{
		wstring str = L"GAME OVER";
		TextOut(hdc, 600, 400,str.c_str(), str.size());

		return;
	}

	for (Poo* poo : objects)
	{
		poo->Render(hdc);
	}

	player->Render(hdc);
}

void AvoidGameScene::Collision()
{
	for (Poo* poo : objects)
	{
		if (poo->GetRect() != nullptr)
		{
			if (Collision::Collision(poo->GetRect(), player->GetRect()))
			{
				if (player->HP() > 0)
				{
					player->HP()--;
					poo->GetRect()->Pos().y = -100;
				}
				else
				{
					player->IsActive() = false;
				}
			}
		}
		else
		{
			if (Collision::Collision(poo->GetCircle(), player->GetRect()))
			{
				if (player->HP() > 0)
				{
					player->HP()--;
					poo->GetCircle()->Pos().y = -100;
				}
				else
				{
					player->IsActive() = false;
				}
			}
		}
	}
}


