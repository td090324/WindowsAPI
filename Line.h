#pragma once
class Line
{
public:
	Line(Point start, Point end);
	~Line();

	void Render(HDC hdc);

	Point& Start() { return start; }
	Point&	 End() { return   end; }

private:
	Point start = {};
	Point	end = {};
};


