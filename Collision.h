#pragma once
namespace Collision
{
	//사각형과 점의 충돌
	bool Collision(Rect* rect, Point point);
	bool Collision(Point point, Rect* rect);


	//사각형과 사각형의 충돌
	bool Collision(Rect* r1, Rect* r2);

	//원과 점의 충돌
	bool Collision(Circle* circle, Point point);
	bool Collision(Point point, Circle* circle);

	//원과 원의 충돌
	bool Collision(Circle* c1, Circle* c2);

	//원과 사각형의 충돌
	bool Collision(Rect* rect, Circle* circle);
	bool Collision(Circle* circle, Rect* rect);
}

