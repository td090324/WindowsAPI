#pragma once
class AngleScene : public Scene
{
public:
	AngleScene();
	~AngleScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;	//화면을 갱신해주는 함수.

private:

};

