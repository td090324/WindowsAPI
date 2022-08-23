#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();


	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:

	HPEN rPen;
	HPEN gPen;
	HPEN bPen;

	HBRUSH rBrush;
	HBRUSH gBrush;
	HBRUSH bBrush;


	HBRUSH hBrush;

	HDC hdc;

};


