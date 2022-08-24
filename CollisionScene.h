#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	//사각형과 점의 충돌
	bool Collision(Rect* rect, Point point);

	//사각형과 사각형의 충돌
	bool Collision(Rect* r1, Rect* r2);

private:
	HBRUSH rBrush;
	HBRUSH gBrush;
	HBRUSH bBrush;


	Rect* rect1;
	Rect* rect2;

	double speed = 3.0;
};


