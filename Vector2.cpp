#include "Framework.h"
#include "Vector2.h"

Vector2::Vector2()
{
}

Vector2::Vector2(double x, double y)
	:x(x), y(y)
{
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
