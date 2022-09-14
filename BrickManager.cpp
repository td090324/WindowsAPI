#include "Framework.h"
#include "BrickManager.h"

BrickManager::BrickManager(UINT poolCOunt)
{
	//2중for문으로 벽돌 생성
	//직관적이지는 못하다.
	//시간도 더 걸림
	//for (UINT j = 0; j < 2; j++)
	//{
	//	for (UINT i = 0; i < poolCOunt; i++)
	//	{
	//		bricks.push_back(new Brick(Vector2(100 + 50.0 * i, 100+20.0*j), Vector2(50, 20)));
	//	}
	//}

	Stage1();
}

BrickManager::~BrickManager()
{
	for (Brick* brick : bricks)
		delete brick;

	bricks.clear();
}


void BrickManager::Render(HDC hdc)
{
	int a = 0;
	for (Brick* brick : bricks)
		brick->Render(hdc);
}

void BrickManager::Stage1()
{
	UINT nX = 1;
	UINT nY = 1;
	UINT nBricks = nX * nY;

	Vector2 pos  = WIN_CENTER;
	Vector2 size = {  200, 200 };

	for (UINT i = 0; i < nBricks; i++)
	{
		UINT x = i % nX;
		UINT y = i / nX;

		bricks.push_back(new Brick(Vector2(pos.x + size.x * x, pos.y + size.y * y), size));
	}
}

void BrickManager::Stage2()
{
	UINT nX = 8;
	UINT nY = 5;
	UINT nBricks = nX * nY;

	Vector2 pos = { 100, 100 };
	Vector2 size = { 50,  20 };

	for (UINT i = 0; i < nBricks; i++)
	{
		UINT x = i % nX;
		UINT y = i / nX;

		bricks.push_back(new Brick(Vector2(pos.x + size.x * x, pos.y + size.y * y), size, y + 1));
	}
}

void BrickManager::ClearStage()
{
	for (Brick* brick : bricks)
		delete brick;

	bricks.clear();
}

bool BrickManager::IsClear()
{
	for (Brick* brick : bricks)
	{
		if (brick->GetHP() > 0)
			return false;
	}

	return true;
}
