#pragma once
class Ufo
{
public:
	Ufo();
	~Ufo();

	void Update();
	void Render();

	void RandomMove();

private:
	Texture* texture;
	Rect* rect;
	Animation* animation;
	
	double speed = 100.0;

	double time       = 0.0;
	double randomTime = 0.0;

	Vector2 dir = Vector2(1, 1).Normal();
};



