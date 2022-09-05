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
