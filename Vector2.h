#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(double x, double y);
	
	//������ �Լ� ����ϰ� ȣ��Ǳ⶧���� ���۷����� �޾ƿ´�.
	//������ �׷��� ������ ������ �����ϱ⶧���� const�� �����ִ� ��.
	//��Ģ ������ �����ε�
	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(const double& value) const;
	Vector2 operator/(const double& value) const;

	//���� ������ �����ε�
	//��ȯ���� ���� ����. �ڽ��� ���� ��ȯ�ϴ� �Լ��̱� ����
	void operator+=(const Vector2& other);
	void operator-=(const Vector2& other);
	void operator*=(const double& value);
	void operator/=(const double& value);

	double x = 0;
	double y = 0;

};


