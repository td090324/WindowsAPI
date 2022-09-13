#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(double x, double y);

	double Length();

	//노멀됐을때 값을 반환하는것
	Vector2 Normal();
	//정규화만 해버리는 것.
	void Normalize();
	
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

	//내적
	static double Dot(Vector2 v1, Vector2 v2);

	//외적
	//2d에서는 z축이 없으니까 계산하면 스칼라값이 나옴
	//때문에 이론상 Vector가 반환이지만 지금은 double로
	static double Cross(Vector2 v1, Vector2 v2);

	//factor가 v2,v3 사이에 있는지 판단.
	static bool IsBetween(Vector2 factor, Vector2 v1, Vector2 v2);

	double x = 0;
	double y = 0;



};


