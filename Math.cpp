#include "Framework.h"
#include "Math.h"

double Math::Distance(Point p1, Point p2)
{
	double a = p1.x - p2.x;
	double b = p1.y - p2.y;


	double distance = sqrt(pow(a, 2) + pow(b, 2));

    return distance;
}
