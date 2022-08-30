#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	rBrush = CreateSolidBrush(COLOR_RED);
	gBrush = CreateSolidBrush(COLOR_GREEN);
	bBrush = CreateSolidBrush(COLOR_BLUE);

	rect1 = new Rect(Point(500, 500), Point(100, 100));
	rect2 = new Rect(Point(100, 100), Point(100, 100));

	circle1 = new Circle(Point(300, 100), 50);
	circle2 = new Circle(Point(500, 100), 50);
}

CollisionScene::~CollisionScene()
{
	delete rect1;
	delete rect2;

	delete circle1;
	delete circle2;
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

	//Circle1�� ���콺 ��ġ�� ����ٴϰ�
	circle1->Pos() = mousePos;
}


void CollisionScene::Render(HDC hdc)
{
	if (Collision(rect1, circle1))
		SelectObject(hdc, rBrush);
	else
		SelectObject(hdc, gBrush);

	//rect1->Render(hdc);
	//rect2->Render(hdc);

	circle1->Render(hdc);
	circle2->Render(hdc);
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

bool CollisionScene::Collision(Circle* circle, Point point)
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

	if //��(�簢��)�� �簢���� �浹
	(
		(circle->Pos().x > rect->Left() && circle->Pos().x < rect->Right())||
		(circle->Pos().y > rect->Top() && circle->Pos().y < rect->Bottom())
	)
	{
		Rect cRect(circle->Pos(), Point(circle->Radius() * 2, circle->Radius() * 2));
		return Collision(rect, &cRect);
	}
	else //���� �������� �浹
	{
		Point edges[4];

		edges[0] = Point(rect->Left(), rect->Top());
		edges[1] = Point(rect->Left(), rect->Bottom());
		edges[2] = Point(rect->Right(), rect->Top());
		edges[3] = Point(rect->Right(), rect->Bottom());

		for (UINT i = 0; i < 4; i++)
		{
			if (Collision(circle, edges[i]))
				return true;

			//�̷��� �ϸ�ȵ�. ù��° �������� üũ�Ҽ��� �ֱ� ����.
			//return (Collision(circle, edges[i]));
		}
	}

	return false;
}
