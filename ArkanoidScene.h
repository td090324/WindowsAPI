#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	virtual void Update() override;	//������ ������ ���ִ� �Լ�.
	virtual void Render(HDC hdc) override;	//ȭ���� �������ִ� �Լ�.

private:
	ArkaPlayer* player;
	Ball* ball;
	//Brick* brick;

	BrickManager* bricks;

};



