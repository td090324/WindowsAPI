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

	double barrelLength = 200;	//포신 길이
	double barrelAngle	=   0;	//포신 각도
	double speed		=	5;	//탱크 속도
	double power        = 200;	//게이지바(파워)

	//CannonBall* ball;
	CannonBallManager* balls;

	HBRUSH rBrush;

	Rect* barFront;
	Rect* barBack;

	bool isCharging = false;
};

