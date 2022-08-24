#include "Framework.h"
#include "Rect.h"


Rect::Rect(double left, double top, double right, double bottom)
{
	pos.x = (left + right) * 0.5;
	pos.y = (top + bottom) * 0.5;
	size.x = abs(right - left);	//abs 절대값 구하는 함수
	size.y = abs(bottom - top);
}

Rect::Rect(Point pos, Point size)
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
