#pragma once
class ArkaPlayer
{
public:
	ArkaPlayer();
	~ArkaPlayer();

	void Update();
	void Render(HDC hdc);

	void Move();

private:
	Rect* rect;

	double speed = 3;	

	HBRUSH hBrush;
};

