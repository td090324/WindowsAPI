#include "Framework.h"
#include "ArkaPlayer.h"

ArkaPlayer::ArkaPlayer()
{
	rect = new Rect({ WIN_CENTER.x, WIN_HEIGHT * 0.9 }, {100,30});

	hBrush = CreateSolidBrush(RGB(128,128,128));
}

ArkaPlayer::~ArkaPlayer()
{
	delete rect;

	DeleteObject(hBrush);
}

void ArkaPlayer::Update()
{
	Move();
}

void ArkaPlayer::Render(HDC hdc)
{
	SelectObject(hdc, hBrush);
	rect->Render(hdc);
}

void ArkaPlayer::Move()
{
	if (GetAsyncKeyState('A'))
		rect->Pos() += Vector2(-1, 0) * speed;

	if (GetAsyncKeyState('D'))
		rect->Pos() += Vector2(1, 0) * speed;

}



