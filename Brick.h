#pragma once

#define MAX_HP 5

class Brick
{
public:
	Brick(Vector2 pos, Vector2 size);
	~Brick();

	void Render(HDC hdc);

	Rect* GetRect() { return rect; }

	UINT& GetHP() { return curHP; }

private:
	Rect* rect;

	UINT curHP = 1;
};
