#pragma once
class ImageScene : public Scene
{
public:
	ImageScene();
	~ImageScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:

	HDC		memDC;	//가상 공간
	HBITMAP hBitmap;
	HBITMAP rockMan;

	POINT curFrame = {};

	int time = 0;

	Texture*	airplaneTexture;
	Rect*       airplaneRect;

	Texture*	rockManTexture;
	Rect*		rockManRect;
};



