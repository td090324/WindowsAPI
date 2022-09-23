#pragma once
class Plane
{
public:
	Plane();
	~Plane();

	void Update();
	void Render();

	void Shoot();

private:
	Texture* texture;
	Rect* rect;

	double speed = 300.0;

	Bullet* bullet;

};



