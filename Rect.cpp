#include "Framework.h"
#include "Rect.h"


Rect::Rect(double left, double top, double right, double bottom)
{
	pos.x = (left + right) * 0.5;
	pos.y = (top + bottom) * 0.5;
	size.x = abs(right - left);	//abs 절대값 구하는 함수
	size.y = abs(bottom - top);
}

Rect::Rect(Vector2 pos, Vector2 size)
	:pos(pos), size(size)
{
}

Rect::~Rect()
{
}

void Rect::Render(HDC hdc)
{
	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}

void Rect::SetRect(double left, double top, double right, double bottom)
{
	pos.x = (left + right) * 0.5;
	pos.y = (top + bottom) * 0.5;
	size.x = abs(right - left);
	size.y = abs(bottom - top);
}
