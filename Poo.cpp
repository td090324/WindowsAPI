#include "Framework.h"
#include "Poo.h"

Poo::Poo()
{
	brushes[RED] = CreateSolidBrush(COLOR_RED);
	brushes[GREEN] = CreateSolidBrush(COLOR_GREEN);
	brushes[BLUE] = CreateSolidBrush(COLOR_BLUE);

	CreateObject();
}

Poo::~Poo()
{
	for (UINT i = 0; i < 3; i++)
	{
		DeleteObject(brushes[i]);
	}
}

void Poo::Update()
{
	if (rect != nullptr)
		rect->Pos().y += speed;
	else
		circle->Pos().y += speed;
}

void Poo::Render(HDC hdc)
{
	switch (color)
	{
	case Poo::RED:
		oldBrush = (HBRUSH)SelectObject(hdc,brushes[RED]);
		break;
	case Poo::GREEN:
		oldBrush = (HBRUSH)SelectObject(hdc, brushes[GREEN]);
		break;
	case Poo::BLUE:
		oldBrush = (HBRUSH)SelectObject(hdc, brushes[BLUE]);
		break;
	}

	if (rect != nullptr)
		rect->Render(hdc);
	else
		circle->Render(hdc);

	SelectObject(hdc, oldBrush);
}

void Poo::CreateObject()
{
	//Type, Color, Position, size

	type = (Type)(rand() % 2);

	color = (Color)(rand() % 3);

	Point pos;
	pos.x = rand() % 1000 + 100;
	pos.y = -100;

	double size = rand() % 100 + 50;

	switch (type)
	{
	case Poo::RECT:
	{
		rect = new Rect(pos, Point(size, size));
	}
		break;
	case Poo::CIRCLE:
	{
		circle = new Circle(pos, size);
	}
		break;
	default:
		break;
	}




}
