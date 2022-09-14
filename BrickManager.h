#pragma once
class BrickManager
{
public:
	BrickManager(UINT poolCOunt = 5);
	~BrickManager();

	vector<Brick*> GetBricks() { return bricks; }

	void Render(HDC hdc);

	void Stage1();
	void Stage2();

	void ClearStage();

	bool IsClear();

private:
	vector<Brick*> bricks;
};

