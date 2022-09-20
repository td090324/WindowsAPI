#include "Framework.h"
#include "Math.h"

double Math::Distance(Vector2 p1, Vector2 p2)
{
	double a = p1.x - p2.x;
	double b = p1.y - p2.y;


	double distance = sqrt(pow(a, 2) + pow(b, 2));

    return distance;
}

double Math::ToRadian(double degree)
{
	return (PI / 180) * degree;
}

double Math::ToDegree(double radian)
{

	return (180 / PI) * radian;
}

int Math::Random(const int& min, const int& max)
{
	return rand() % (max - min) + min;
}

double Math::Random(const double& min, const double& max)
{
	return (double)rand() / (double)RAND_MAX * (max- min) + min;
}
