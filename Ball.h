#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPlayer(ArkaPlayer* player) { this->player = player; }
	void SetBricks(BrickManager* bricks) { this->bricks = bricks; }


	void CollisionWall();
	void CollisionPlayer();
	void CollisionBricks();

	bool& IsPlay() { return isPlay; }

private:
	Circle* circle;

	ArkaPlayer* player = nullptr;
	BrickManager* bricks = nullptr;


	double speed = 8;
	
	Vector2 dir = {};

	bool isPlay = false;
};


