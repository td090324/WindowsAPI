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

	struct Data
	{
		Color color;
		Type type;

		Vector2 startPos = {};
		Vector2 endPos = {};

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

	void Preview();

	void Debug();

private:
	Vector2 startPos = {};
	Vector2	endPos = {};

	HPEN	 hPen[4] = {};
	HBRUSH hBrush[4] = {};

	bool isClick = false;

	Color color = BLACK;
	Type type = PEN;

	HDC hdc;

	vector<Data> objects;
};


