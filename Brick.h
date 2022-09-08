#pragma once
class Brick
{
public:
	Brick(Vector2 pos, Vector2 size);
	~Brick();

	void Update();
	void Render(HDC hdc);

	Rect* GetRect() { return rect; }

private:
	Rect* rect;
};
