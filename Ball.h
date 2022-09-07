#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void CollisionWall();
	void CoolisionPlayer();

	void SetPlayer(ArkaPlayer* player) { this->player = player; }


private:
	Circle* circle;

	ArkaPlayer* player = nullptr;

	double speed = 5;
	
	Vector2 dir = {};

	bool isPlay = false;
};


