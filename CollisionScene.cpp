#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	rBrush = CreateSolidBrush(COLOR_RED);
	gBrush = CreateSolidBrush(COLOR_GREEN);
	bBrush = CreateSolidBrush(COLOR_BLUE);

	rect1 = new Rect(Point(500, 500), Point(100, 100));
	rect2 = new Rect(Point(100, 100), Point(100, 100));
}

CollisionScene::~CollisionScene()
{
	delete rect1;
	delete rect2;
}

void CollisionScene::Update()
{
	if (GetAsyncKeyState('A'))
	{
		rect1->Pos().x -= speed;
	}
	if (GetAsyncKeyState('D'))
	{
		rect1->Pos().x += speed;
	}
	if (GetAsyncKeyState('W'))
	{
		rect1->Pos().y -= speed;
	}
	if (GetAsyncKeyState('S'))
	{
		rect1->Pos().y += speed;
	}
}

void CollisionScene::Render(HDC hdc)
{
	if (Collision(rect1, rect2))
		SelectObject(hdc, rBrush);
	else
		SelectObject(hdc, gBrush);

	rect1->Render(hdc);
	rect2->Render(hdc);
}

bool CollisionScene::Collision(Rect* rect, Point point)
{
	if
	(
		point.x > rect->Left()	&& 
		point.x < rect->Right() &&
		point.y > rect->Top()	&&
		point.y < rect->Bottom()
	)
	{
		return true;
	}

	return false;
}

bool CollisionScene::Collision(Rect* r1, Rect* r2)
{
	if
	(
		r1->Right() > r2->Left() &&
		r1->Left() < r2->Right() &&
		r1->Bottom() > r2->Top() &&
		r1->Top() < r2->Bottom()
	)
	{
		return true;
	}

	return false;
}
