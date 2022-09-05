#pragma once
class Circle
{
public:
	Circle(Vector2 pos, double radius);
	~Circle();

	void Render(HDC hdc);

	double Left()	{ return pos.x - radius; }
	double Right()	{ return pos.x + radius; }
	double Top()	{ return pos.y - radius; }
	double bottom()	{ return pos.y + radius; }

	Vector2& Pos() { return pos; }
	double Radius() { return radius; }

private:
	Vector2 pos = {};
	double radius = 0;
};



