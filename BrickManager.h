#pragma once
class BrickManager
{
public:
	BrickManager(UINT poolCOunt = 5);
	~BrickManager();

	vector<Brick*> GetBricks() { return bricks; }

	void Update();
	void Render(HDC hdc);

private:
	vector<Brick*> bricks;
};

