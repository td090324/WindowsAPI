#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	virtual void Update() override;	//정보를 갱신을 해주는 함수.
	virtual void Render(HDC hdc) override;	//화면을 갱신해주는 함수.

private:
	ArkaPlayer* player;
	Ball* ball;

};



