#pragma once
namespace Math
{
	double Distance(Vector2 p1, Vector2 p2);

	double ToRadian(double degree);
	double ToDegree(double radian);

	int		Random(const    int& min,	 const int& max); //max exclusive 최대값 제외
	double  Random(const double& min, const double& max); //max inclusive 최대값 포함
};

