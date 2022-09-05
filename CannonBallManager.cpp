#include "Framework.h"
#include "CannonBallManager.h"

CannonBallManager::CannonBallManager(UINT poolCount)
{
	for (UINT i= 0; i < poolCount; i++)
	{
		//CannonBall* cannonball = new CannonBall();
		//cannonBalls.push_back(cannonball);

		cannonBalls.push_back(new CannonBall());
	}
}

CannonBallManager::~CannonBallManager()
{
	for (CannonBall* cannonBall : cannonBalls)
		delete cannonBall;

	//쓰레기값을 지우기 위한 벡터 내부 클리어
	cannonBalls.clear();
}

void CannonBallManager::Update()
{
	for (CannonBall* cannonBall : cannonBalls)
		cannonBall->Update();
}

void CannonBallManager::Render(HDC hdc)
{
	for (CannonBall* cannonBall : cannonBalls)
		cannonBall->Render(hdc);
}

void CannonBallManager::Fire(Vector2 pos, double angle, double power)
{
	for (CannonBall* cannonBall : cannonBalls)
	{
		//포탄이 하나만 보이게끔 조건을 걸어둔다.
		if (!cannonBall->IsFire())
		{
			cannonBall->Fire(pos, angle, power);
			return;
		}
	}
}

void CannonBallManager::Fire(Vector2 pos, Vector2 dir, double power)
{
	for (CannonBall* cannonBall : cannonBalls)
	{
		//포탄이 하나만 보이게끔 조건을 걸어둔다.
		if (!cannonBall->IsFire())
		{
			cannonBall->Fire(pos, dir, power);
			return;
		}
	}
}
