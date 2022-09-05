#pragma once
class CannonBall
{
public:
	CannonBall();
	~CannonBall();

	void Update();
	void Render(HDC hdc);

	//�߻� ��ġ, �߻� ����, �߻� ��(�ӵ�)
	void Fire(Vector2 pos, double angle, double power);
	void Fire(Vector2 pos, Vector2 dir, double power);

	void Move();

	bool IsFire() { return isFire; }

private:
	Circle* ball;
	
	double angle = 0;
	double speed = 0;

	Vector2 dir = {};

	double gravity = 0;

	bool isFire = false;
};



