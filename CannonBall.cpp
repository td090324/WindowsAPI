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

	ball->Pos().y += gravity;

	//중력가속도 적용
	gravity += 0.98;
}
