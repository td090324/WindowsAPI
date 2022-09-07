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

	//왼쪽 벽에 부딪히면 공이 튕기게 적용
	if (circle->Left() <= 0)
	{
		dir.x *= -1;

		//값을 보정해준다. (예외처리)
		//보정을 안해주면 벽에 계속 갇히는 상황이 나올수도있다.
		circle->Pos().x = circle->Radius();
	}

	//오른쪽 벽
	if (circle->Right() >= WIN_WIDTH)
	{
		dir.x *= -1;
		circle->Pos().x = WIN_WIDTH - circle->Radius();
	}

	//위쪽 벽
	if (circle->Top() <= 0)
	{
		dir.y *= -1;
		circle->Pos().y = circle->Radius();
	}

	//아랫 벽
	if (circle->bottom() >= WIN_HEIGHT)
	{
		isPlay = false;

		dir = Vector2(+1, -1).Normal();
	}
}

void Ball::CoolisionPlayer()
{
	if
	(
			circle->Left() >= player->GetRect()->Left() &&
			circle->Right() <= player->GetRect()->Right() &&
			circle->bottom() >= player->GetRect()->Top()
	)
	{
		Vector2 tmep = (Vector2(player->GetRect()->Pos().x, player->GetRect()->Top())- circle->Pos()).Normal();
		dir = tmep * -1;
	}
}




