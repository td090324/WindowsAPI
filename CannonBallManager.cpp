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

	//�����Ⱚ�� ����� ���� ���� ���� Ŭ����
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

void CannonBallManager::Fire(Point pos, double angle, double power)
{
	for (CannonBall* cannonBall : cannonBalls)
	{
		//��ź�� �ϳ��� ���̰Բ� ������ �ɾ�д�.
		if (!cannonBall->IsFire())
		{
			cannonBall->Fire(pos, angle, power);
			return;
		}
	}
}
