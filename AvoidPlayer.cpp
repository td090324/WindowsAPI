#include "Framework.h"
#include "AvoidPlayer.h"

AvoidPlayer::AvoidPlayer()
{
	rect = new Rect(Vector2(600,600),Vector2(100,50));
}

AvoidPlayer::~AvoidPlayer()
{
	delete rect;
}

void AvoidPlayer::Update()
{
	if (!isActive)
		return;

	if (hp <= 0)
		isActive = false;

	Move();
}

void AvoidPlayer::Render(HDC hdc)
{
	if (!isActive)
	{
		wstring str = L"PLAYER IS DEAD!";
		TextOut(hdc, 600, 400, str.c_str(), str.size());

		return;
	}

	wstring str = L"PLAYER HP : " + to_wstring(hp);
	TextOut(hdc, 10, 10, str.c_str(), str.size());

	rect->Render(hdc);
}

void AvoidPlayer::Move()
{
	if (GetAsyncKeyState('A'))
		rect->Pos().x -= speed;

	if (GetAsyncKeyState('D'))
		rect->Pos().x += speed;
}
