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

	//���۷����� �ܺο��� �����ϸ� Set ��ɱ��� ����.
	Vector2& Pos(){ return pos; }
	Vector2& Size() { return size; }


private:
	Vector2 pos;	//������ ��ġ
	Vector2 size;	//������������ ����,�¿� ���� ��
};


