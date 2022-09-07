#include "Framework.h"
#include "Ball.h"

Ball::Ball()
{
	circle = new Circle(WIN_CENTER,10);
	dir = Vector2(+1, -1).Normal();
}

Ball::~Ball()
{
	delete circle;
}

void Ball::Update()
{
	if (GetAsyncKeyState(VK_SPACE))
		isPlay = true;

	if (isPlay)
	{
		circle->Pos() += dir * speed;
		CollisionWall();
		CoolisionPlayer();
	}
	else
	{
		circle->Pos().x = player->GetRect()->Pos().x;
		circle->Pos().y = player->GetRect()->Top() - circle->Radius();
	}
}

void Ball::Render(HDC hdc)
{
	circle->Render(hdc);
}

void Ball::CollisionWall()
{

	//���� ���� �ε����� ���� ƨ��� ����
	if (circle->Left() <= 0)
	{
		dir.x *= -1;

		//���� �������ش�. (����ó��)
		//������ �����ָ� ���� ��� ������ ��Ȳ�� ���ü����ִ�.
		circle->Pos().x = circle->Radius();
	}

	//������ ��
	if (circle->Right() >= WIN_WIDTH)
	{
		dir.x *= -1;
		circle->Pos().x = WIN_WIDTH - circle->Radius();
	}

	//���� ��
	if (circle->Top() <= 0)
	{
		dir.y *= -1;
		circle->Pos().y = circle->Radius();
	}

	//�Ʒ� ��
	if (circle->bottom() >= WIN_HEIGHT)
	{
		isPlay = false;

		dir = Vector2(+1, -1).Normal();
	}
}

void Ball::CoolisionPlayer()
{
	if(Collision::Collision(circle, player->GetRect()))
	{
		dir = (Vector2(circle->Pos().x, player->GetRect()->Top())- Vector2(player->GetRect()->Pos().x, player->GetRect()->Bottom())).Normal();
	}
}




