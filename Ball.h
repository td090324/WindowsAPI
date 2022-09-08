#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPlayer(ArkaPlayer* player) { this->player = player; }
	void SetBrickManager(vector<Brick*> bricks) { this->bricks = bricks; }

	void CollisionWall();
	void CollisionPlayer();
	void CollisionBrick();



private:
	Circle* circle;

	ArkaPlayer* player = nullptr;

	vector<Brick*>* bricks = nullptr;

	double speed = 5;
	
	Vector2 dir = {};

	bool isPlay = false;
};


