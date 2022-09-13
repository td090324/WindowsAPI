#pragma once
class Rect
{
public:
	Rect(double left, double top, double right, double bottom);
	Rect(Vector2 pos, Vector2 size);
	~Rect();

	void Render(HDC hdc);

	void SetRect(double left, double top, double right, double bottom);

	double Left() { return this->pos.x - this->size.x * 0.5; }
	double Right() { return this->pos.x + this->size.x * 0.5; }
	double Top() { return this->pos.y - this->size.y * 0.5; }
	double Bottom() { return this->pos.y + this->size.y * 0.5; }

	void SetPos(Vector2 pos) { this->pos = pos; }
	Vector2 GetPos() { return pos; }

	//레퍼런스로 외부에서 접근하면 Set 기능까지 가능.
	Vector2& Pos(){ return pos; }
	Vector2& Size() { return size; }


private:
	Vector2 pos;	//중점의 위치
	Vector2 size;	//중점기준으로 상하,좌우 선의 합
};


