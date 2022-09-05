#pragma once

#define MAX_POWER 650.0

class Tank
{
public:
	Tank();
	~Tank();

	void Update();
	void Render(HDC hdc);

	void RotateBarrel();
	void MoveBody();
	void FireBall();

private:
	Rect* body;
	Line* barrel;

	double barrelLength = 200;	//���� ����
	double barrelAngle	=   0;	//���� ����
	double speed		=	5;	//��ũ �ӵ�
	double power        = 200;	//��������(�Ŀ�)

	//CannonBall* ball;
	CannonBallManager* balls;

	HBRUSH rBrush;

	Rect* barFront;
	Rect* barBack;

	bool isCharging = false;
};

