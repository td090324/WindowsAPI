#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	rBrush = CreateSolidBrush(COLOR_RED);
	gBrush = CreateSolidBrush(COLOR_GREEN);
	bBrush = CreateSolidBrush(COLOR_BLUE);

	rect1 = new Rect(Vector2(500, 500), Vector2(100, 100));
	rect2 = new Rect(Vector2(100, 100), Vector2(100, 100));

	circle1 = new Circle(Vector2(300, 100), 50);
	circle2 = new Circle(Vector2(500, 100), 50);

	line1 = new Line(Vector2(0, 0), Vector2(100, 100));
	line2 = new Line(Vector2(400, 100), Vector2(100, 400));
}

CollisionScene::~CollisionScene()
{
	delete rect1;
	delete rect2;

	delete circle1;
	delete circle2;

	delete line1;
	delete line2;
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

	//Circle1이 마우스 위치를 따라다니게
	//circle1->Pos() = mousePos;
	line1->End() = mousePos;
}


void CollisionScene::Render(HDC hdc)
{
	rect1->Render(hdc);
	rect2->Render(hdc);

	if (Collision(rect1, circle1))
		SelectObject(hdc, rBrush);
	else
		SelectObject(hdc, gBrush);


	circle1->Render(hdc);
	circle2->Render(hdc);

	line1->Render(hdc);
	line2->Render(hdc);
}

bool CollisionScene::Collision(Rect* rect, Vector2 point)
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

bool CollisionScene::Collision(Circle* circle, Vector2 point)
{
	//double a = circle1->Pos().x - point.x;
	//double b = circle1->Pos().y - point.y;

	//double distance = sqrt(pow(a,2) + pow(b,2));

	double distance =  Math::Distance(circle->Pos(), point);

	return circle->Radius() > distance;
}

bool CollisionScene::Collision(Circle* c1, Circle* c2)
{
	double distance = Distance(c1->Pos(), c2->Pos());

	return c1->Radius() + c2->Radius() > distance;
}

bool CollisionScene::Collision(Rect* rect, Circle* circle)
{

	if //원(사각형)과 사각형의 충돌
	(
		(circle->Pos().x > rect->Left() && circle->Pos().x < rect->Right())||
		(circle->Pos().y > rect->Top() && circle->Pos().y < rect->Bottom())
	)
	{
		Rect cRect(circle->Pos(), Vector2(circle->Radius() * 2, circle->Radius() * 2));
		return Collision(rect, &cRect);
	}
	else //원과 꼭지점의 충돌
	{
		Vector2 edges[4];

		edges[0] = Vector2(rect->Left(), rect->Top());
		edges[1] = Vector2(rect->Left(), rect->Bottom());
		edges[2] = Vector2(rect->Right(), rect->Top());
		edges[3] = Vector2(rect->Right(), rect->Bottom());

		for (UINT i = 0; i < 4; i++)
		{
			if (Collision(circle, edges[i]))
				return true;

			//이렇게 하면안됨. 첫번째 꼭지점만 체크할수도 있기 때문.
			//return (Collision(circle, edges[i]));
		}
	}

	return false;
}
