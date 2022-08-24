#pragma once
class Rect
{
public:
	Rect(double left, double top, double right, double bottom);
	Rect(Point pos, Point size);
	~Rect();

	void Render(HDC hdc);

	double Left() { return this->pos.x - this->size.x * 0.5; }
	double Right() { return this->pos.x + this->size.x * 0.5; }
	double Top() { return this->pos.y - this->size.y * 0.5; }
	double Bottom() { return this->pos.y + this->size.y * 0.5; }

	void SetPos(Point pos) { this->pos = pos; }
	Point GetPos() { return pos; }

	//레퍼런스로 외부에서 접근하면 Set 기능까지 가능.
	Point& Pos(){ return pos; }


private:
	Point pos;	//중점의 위치
	Point size;	//중점기준으로 상하,좌우 선의 합
};


