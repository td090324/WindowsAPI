#include "Framework.h"
#include "Collision.h"


bool Collision::Collision(Rect* rect, Vector2 point)
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

bool Collision::Collision(Vector2 point, Rect* rect)
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

bool Collision::Collision(Circle* circle, Vector2 point)
{
	//double a = circle1->Pos().x - point.x;
	//double b = circle1->Pos().y - point.y;

	//double distance = sqrt(pow(a,2) + pow(b,2));

	double distance = Math::Distance(circle->Pos(), point);

	return circle->Radius() > distance;
}

bool Collision::Collision(Vector2 point, Circle* circle)
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

	if //원(사각형)과 사각형의 충돌
		(
			(circle->Pos().x > rect->Left() && circle->Pos().x < rect->Right()) ||
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

bool Collision::Collision(Circle* circle, Rect* rect)
{
	return Collision(rect,circle);
}
