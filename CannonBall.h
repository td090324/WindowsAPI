#pragma once
class CannonBall
{
public:
	CannonBall();
	~CannonBall();

	void Update();
	void Render(HDC hdc);

	//발사 위치, 발사 각도, 발사 힘(속도)
	void Fire(Point pos, double angle, double power);

	void Move();

private:
	Circle* ball;
	
	double angle = 0;
	double speed = 0;

	bool isFire = false;
};



