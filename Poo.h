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

private:
	Rect*	  rect = nullptr;
	Circle* circle = nullptr;

	Type type = RECT;
	Color color = RED;

	HBRUSH brushes[3];

	double speed = 1;

};


