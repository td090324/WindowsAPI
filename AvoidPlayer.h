#pragma once
class AvoidPlayer
{
public:
	AvoidPlayer();
	~AvoidPlayer();

	void Update();
	void Render(HDC hdc);

	void Move();

	Rect* GetRect() { return rect; }
	bool& IsActive() { return isActive; }

	UINT& HP() { return hp; }

private:
	Rect* rect;

	double speed = 3.0;

	bool isActive = true;

	UINT hp = 3;
};



