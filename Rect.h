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

	//���۷����� �ܺο��� �����ϸ� Set ��ɱ��� ����.
	Point& Pos(){ return pos; }


private:
	Point pos;	//������ ��ġ
	Point size;	//������������ ����,�¿� ���� ��
};


