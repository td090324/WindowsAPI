#pragma once
class CannonBall
{
public:
	CannonBall();
	~CannonBall();

	void Update();
	void Render(HDC hdc);

	//�߻� ��ġ, �߻� ����, �߻� ��(�ӵ�)
	void Fire(Point pos, double angle, double power);

	void Move();

private:
	Circle* ball;
	
	double angle = 0;
	double speed = 0;

	bool isFire = false;
};



