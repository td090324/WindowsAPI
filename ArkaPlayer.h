#pragma once
class ArkaPlayer
{
public:
	ArkaPlayer();
	~ArkaPlayer();

	void Update();
	void Render(HDC hdc);

	void Move();

	Rect* GetRect() { return rect; }


private:
	Rect* rect;

	double speed = 3;	

	HBRUSH hBrush;


};

