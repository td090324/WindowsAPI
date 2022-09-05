#include "Framework.h"
#include "Circle.h"

Circle::Circle(Vector2 pos, double radius)
	:pos(pos), radius(radius)
{
}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	Ellipse(hdc,Left(),Top(),Right(),bottom());
}
