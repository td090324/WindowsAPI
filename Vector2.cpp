#include "Framework.h"
#include "Vector2.h"

Vector2::Vector2()
{
}

Vector2::Vector2(double x, double y)
	:x(x), y(y)
{
}

double Vector2::Length()
{
	return sqrt(pow(x,2)+pow(y,2));
}

Vector2 Vector2::Normal()
{
	//return Vector2(this->x / Length(), this->y / Length());

	//this는 나를 가리키는 포인터이다.
	return *this / Length();
}

void Vector2::Normalize()
{
	*this /= Length();
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator*(const double& value) const
{
	return Vector2(this->x * value, this->y * value);
}

Vector2 Vector2::operator/(const double& value) const
{
	return Vector2(this->x / value, this->y / value);
}

void Vector2::operator+=(const Vector2& other)
{
	this->x += other.x;
	this->y += other.y;
}

void Vector2::operator-=(const Vector2& other)
{
	this->x -= other.x;
	this->y -= other.y;
}

void Vector2::operator*=(const double& value)
{
	this->x *= value;
	this->y *= value;
}

void Vector2::operator/=(const double& value)
{
	this->x /= value;
	this->y /= value;
}

double Vector2::Dot(Vector2 v1, Vector2 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y));
}

double Vector2::Cross(Vector2 v1, Vector2 v2)
{
	return ((v1.x * v2.y) - (v1.y * v2.x));
}

bool Vector2::IsBetween(Vector2 factor, Vector2 v1, Vector2 v2)
{
	//if (Cross(factor, v1) * Cross(factor, v2) < 0)
	//	return true;

	//두 수를 곱하면 같은 부호인지 아닌지 알 수 있다.
	//부호가 달라야 true. 두 점 사이에 있다는 의미이기 때문에
	return Cross(factor, v1) * Cross(factor, v2) < 0;
}
