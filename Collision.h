#pragma once
namespace Collision
{
	//�簢���� ���� �浹
	bool Collision(Rect* rect, Point point);
	bool Collision(Point point, Rect* rect);


	//�簢���� �簢���� �浹
	bool Collision(Rect* r1, Rect* r2);

	//���� ���� �浹
	bool Collision(Circle* circle, Point point);
	bool Collision(Point point, Circle* circle);

	//���� ���� �浹
	bool Collision(Circle* c1, Circle* c2);

	//���� �簢���� �浹
	bool Collision(Rect* rect, Circle* circle);
	bool Collision(Circle* circle, Rect* rect);
}

