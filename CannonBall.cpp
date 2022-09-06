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

	//�߷� �ʱ�ȭ
	gravity = 0;
}

void CannonBall::Fire(Vector2 pos, Vector2 dir, double power)
{
	isFire = true;

	ball->Pos() = pos;
	this->dir = dir;
	this->speed = power * 0.1;

	//�߷� �ʱ�ȭ
	gravity = 0;
}

void CannonBall::Move()
{
	//ball->Pos().x += cos(angle) * speed;
	//ball->Pos().y -= sin(angle) * speed;

	ball->Pos() += dir * speed;


	//���� ���� �ε����� ���� ƨ��� ����
	if (ball->Left() <= 0)
	{
		dir.x *= -1;

		//���� �������ش�. (����ó��)
		//������ �����ָ� ���� ��� ������ ��Ȳ�� ���ü����ִ�.
		ball->Pos().x = ball->Radius();
	}

	//������ ��
	if (ball->Right() >= WIN_WIDTH)
	{
		dir.x *= -1;
		ball->Pos().x = WIN_WIDTH - ball->Radius();
	}

	//���� ��
	if (ball->Top() <= 0)
	{
		dir.y *= -1;
		ball->Pos().y = ball->Radius();
	}

	//�Ʒ� ��
	if (ball->bottom() >= WIN_HEIGHT)
	{
		dir.y *= -1;
		ball->Pos().y = WIN_HEIGHT - ball->Radius();
	}


	//ball->Pos().y += gravity;
	//�߷°��ӵ��� �߷��� ����
	//gravity += 0.98;
}
