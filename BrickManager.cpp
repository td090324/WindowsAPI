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

	////////////////////////////
	//1중 for문으로 벽돌 생성
	//나눗셈, 나머지 연산자를 활용
	UINT nX = 1;
	UINT nY = 1;
	UINT nBricks = nX * nY;

	for (UINT i = 0; i < nBricks; i++)
	{
		UINT x = i % nX;
		UINT y = i / nX;

		bricks.push_back(new Brick(Vector2(100 + 50.0 * x, 100 + 20.0 * y), Vector2(50, 20)));
	}
}

BrickManager::~BrickManager()
{
	for (Brick* brick : bricks)
		delete brick;

	bricks.clear();
}


void BrickManager::Render(HDC hdc)
{
	for (Brick* brick : bricks)
		brick->Render(hdc);
}
