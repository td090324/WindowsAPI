#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(double x, double y);
	
	//연산자 함수 빈번하게 호출되기때문에 레퍼런스로 받아온다.
	//하지만 그러면 원본에 수정이 가능하기때문에 const로 막아주는 것.
	//사칙 연산자 오버로딩
	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(const double& value) const;
	Vector2 operator/(const double& value) const;

	//대입 연산자 오버로딩
	//반환형이 따로 없다. 자신의 값을 변환하는 함수이기 때문
	void operator+=(const Vector2& other);
	void operator-=(const Vector2& other);
	void operator*=(const double& value);
	void operator/=(const double& value);

	double x = 0;
	double y = 0;

};


