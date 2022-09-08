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
		CollisionPlayer();
		CollisionBrick();
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

void Ball::CollisionPlayer()
{
	if (Collision::Collision(this->circle, player->GetRect()))
	{
		dir = circle->Pos() - Vector2(player->GetRect()->Pos().x, player->GetRect()->Bottom() + 1);
		dir.Normalize();
	}
}

void Ball::CollisionBrick()
{
	for (UINT i = 0; i < bricks->capacity(); i++)
	{
		if (Collision::Collision(this->circle, bricks->at(i)->GetRect()))
		{
			//���� ���� ���ʿ� �ε��� ��
			if (this->circle->Right() >= bricks->at(i)->GetRect()->Left())
			{
				dir.x *= -1;
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
	}

}






