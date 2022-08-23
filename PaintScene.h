#pragma once
class PaintScene : public Scene
{
	enum Color
	{
		BLACK,
		RED,
		GREEN,
		BLUE
	};

	enum Type
	{
		PEN,
		LINE,
		RECT,
		ELLIPSE
	};

public:
	PaintScene();
	~PaintScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void LButtonDown();
	void LButtonUp();

	void DrawPen();
	void DrawObjects();

	void SetState();

private:
	POINT startPos = {};
	POINT	endPos = {};

	HPEN	 hPen[4] = {};
	HBRUSH hBrush[4] = {};

	bool isClick = false;

	Color color = BLACK;
	Type type = PEN;

	HDC hdc;
};


