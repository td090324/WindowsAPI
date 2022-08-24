#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	//�簢���� ���� �浹
	bool Collision(Rect* rect, Point point);

	//�簢���� �簢���� �浹
	bool Collision(Rect* r1, Rect* r2);

private:
	HBRUSH rBrush;
	HBRUSH gBrush;
	HBRUSH bBrush;


	Rect* rect1;
	Rect* rect2;

	double speed = 3.0;
};


