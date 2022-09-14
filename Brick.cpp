#include "Framework.h"
#include "Brick.h"

Brick::Brick(Vector2 pos, Vector2 size, UINT hp)
	:curHP(hp)
{
	rect = new Rect(pos, size);

	brushes[0] = CreateSolidBrush(COLOR_RED);
	brushes[1] = CreateSolidBrush(COLOR_MAGENTA);
	brushes[2] = CreateSolidBrush(COLOR_PINK);
	brushes[3] = CreateSolidBrush(COLOR_ORANGE);
	brushes[4] = CreateSolidBrush(COLOR_YELLOW);
}

Brick::~Brick()
{
	delete rect;

	for (UINT i = 0; i < MAX_HP; i++)
	{
		DeleteObject(brushes[i]);
	}
}


void Brick::Render(HDC hdc)
{
	if (curHP <= 0)
		return;

	SelectObject(hdc, brushes[curHP - 1]);
	rect->Render(hdc);
}
