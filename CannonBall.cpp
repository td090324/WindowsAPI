#include "Framework.h"
#include "CannonBall.h"

CannonBall::CannonBall()
{
	ball = new Circle(Vector2(0, 0),10);
}

CannonBall::~CannonBall()
{
	delete ball;
}

void CannonBall::Update()
{
	if (!isFire)
		return;

	Move();
}

void CannonBall::Render(HDC hdc)
{
	if (!isFire)
		return;

	ball->Render(hdc);

}

void CannonBall::Fire(Vector2 pos, double angle, double power)
{
	isFire = true;

	ball->Pos() = pos;
	this->angle = angle;
	this->speed = power * 0.1;

	//중력 초기화
	gravity = 0;
}

void CannonBall::Fire(Vector2 pos, Vector2 dir, double power)
{
	isFire = true;

	ball->Pos() = pos;
	this->dir = dir;
	this->speed = power * 0.1;

	//중력 초기화
	gravity = 0;
}

void CannonBall::Move()
{
	//ball->Pos().x += cos(angle) * speed;
	//ball->Pos().y -= sin(angle) * speed;

	ball->Pos() += dir * speed;


	//왼쪽 벽에 부딪히면 공이 튕기게 적용
	if (ball->Left() <= 0)
	{
		dir.x *= -1;

		//값을 보정해준다. (예외처리)
		//보정을 안해주면 벽에 계속 갇히는 상황이 나올수도있다.
		ball->Pos().x = ball->Radius();
	}

	//오른쪽 벽
	if (ball->Right() >= WIN_WIDTH)
	{
		dir.x *= -1;
		ball->Pos().x = WIN_WIDTH - ball->Radius();
	}

	//위쪽 벽
	if (ball->Top() <= 0)
	{
		dir.y *= -1;
		ball->Pos().y = ball->Radius();
	}

	//아랫 벽
	if (ball->bottom() >= WIN_HEIGHT)
	{
		dir.y *= -1;
		ball->Pos().y = WIN_HEIGHT - ball->Radius();
	}


	//ball->Pos().y += gravity;
	//중력가속도로 중력을 적용
	//gravity += 0.98;
}
