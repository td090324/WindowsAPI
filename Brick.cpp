#include "Framework.h"
#include "Brick.h"

Brick::Brick(Vector2 pos, Vector2 size)
{
	rect = new Rect(pos, size);
}

Brick::~Brick()
{
	delete rect;
}

void Brick::Update()
{
}

void Brick::Render(HDC hdc)
{
	rect->Render(hdc);
}
