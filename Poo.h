#pragma once
class Poo
{
	enum Color
	{
		RED,
		GREEN,
		BLUE
	};

	enum Type
	{
		RECT,
		CIRCLE
	};

public:
	Poo();
	~Poo();

	void Update();
	void Render(HDC hdc);

	void CreateObject();

	Rect* GetRect() { return rect; }
	Circle* GetCircle() { return circle; }

private:
	Rect*	  rect = nullptr;
	Circle* circle = nullptr;

	Type type = RECT;
	Color color = RED;

	HBRUSH brushes[3];
	HBRUSH oldBrush = nullptr;

	double speed = 1;

};


