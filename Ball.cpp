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
		CollisionBricks();
	}
	else
	{
		circle->Pos().x = player->GetRect()->Pos().x;
		circle->Pos().y = player->GetRect()->Top() - circle->Radius();
	}

	if (bricks->IsClear())
	{
		isPlay = false;

		dir = Vector2(+1, -1).Normal();

		player->GetRect()->Pos().x = WIN_CENTER.x;

		bricks->ClearStage();
		bricks->Stage2();
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

		player->GetRect()->Pos().x = WIN_CENTER.x;
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

void Ball::CollisionBricks()
{
	for (Brick* brick : bricks->GetBricks())
	{
		if (brick->GetHP() <= 0)
			continue;

		//������ ���� ������ ���ϴ� ���� ���ϱ�
		Vector2 direction = this->circle->Pos() - brick->GetRect()->Pos();

		Vector2 halfSize = brick->GetRect()->Size() * 0.5;

		//���� ���� ���� �� �𼭸��� ���ϴ� ���� ���ϱ�
		Vector2 LT = Vector2(-halfSize.x, -halfSize.y);
		Vector2 RT = Vector2(+halfSize.x, -halfSize.y);
		Vector2 LB = Vector2(-halfSize.x, +halfSize.y);
		Vector2 RB = Vector2(+halfSize.x, +halfSize.y);

		if (Collision::Collision(this->circle, brick->GetRect()))
		{
			brick->GetHP()--;

			//������ �Ʒ��� ���� ������ �浹�� ��
			if (Vector2::IsBetween(direction, LT, RT))
			{
				dir.y *= -1;
			}
			else if (Vector2::IsBetween(direction, LB, RB))
			{
				dir.y *= -1;
			}
			else if (Vector2::IsBetween(direction, LB, LB))
			{
				dir.x *= -1;
			}
			else if (Vector2::IsBetween(direction, RB, RB))
			{
				dir.x *= -1;
			}
			else
			{
				dir *= -1;
			}

			return;

		}
	}
}






