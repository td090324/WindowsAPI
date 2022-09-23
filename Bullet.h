#pragma once
class Bullet
{
public:
	Bullet(Texture* texture);
	~Bullet();

	void Update();
	void Render();

	void Fire(Vector2 pos, Vector2 dir, double power);

private:
	Texture* texture;
	Rect* rect;

	Vector2 dir = {};
	double power = 500.0;

	bool isFire = false;
};



