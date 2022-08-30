#include "Framework.h"
#include "Collision.h"


bool Collision::Collision(Rect* rect, Point point)
{
	if
		(
			point.x > rect->Left() &&
			point.x < rect->Right() &&
			point.y > rect->Top() &&
			point.y < rect->Bottom()
			)
	{
		return true;
	}

	return false;
}

bool Collision::Collision(Point point, Rect* rect)
{
	return Collision(rect, point);
}

bool Collision::Collision(Rect* r1, Rect* r2)
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

bool Collision::Collision(Circle* circle, Point point)
{
	//double a = circle1->Pos().x - point.x;
	//double b = circle1->Pos().y - point.y;

	//double distance = sqrt(pow(a,2) + pow(b,2));

	double distance = Math::Distance(circle->Pos(), point);

	return circle->Radius() > distance;
}

bool Collision::Collision(Point point, Circle* circle)
{
	return Collision(circle, point);
}

bool Collision::Collision(Circle* c1, Circle* c2)
{
	double distance = Distance(c1->Pos(), c2->Pos());

	return c1->Radius() + c2->Radius() > distance;
}

bool Collision::Collision(Rect* rect, Circle* circle)
{

	if //��(�簢��)�� �簢���� �浹
		(
			(circle->Pos().x > rect->Left() && circle->Pos().x < rect->Right()) ||
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

bool Collision::Collision(Circle* circle, Rect* rect)
{
	return Collision(rect,circle);
}
