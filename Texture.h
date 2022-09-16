#pragma once
class Texture
{
public:
	//���� ���, �̹��� ������, ���� ����
	Texture(wstring path, POINT imageSize, COLORREF transColor = COLOR_MAGENTA);
	~Texture();

	//backDC�� extern�̱⶧���� �ٷ� ����ϸ�ȴ�.
	//���� �̹����� rect�� �����ؼ� backDC�� �Ѱ��� ���̴�.
	//rect�� �ؾ� �̹��� �浹ó���� �����ϱ� �����̴�.
	//��������Ʈ �̹����̱� ������ curframe���� POINT�������� �־��ش�.
	void Render(Rect* rect, POINT curFrame = {0,0});

private:
	HDC memDC;
	HBITMAP bitmap;
	
	COLORREF transColor;

	POINT imageSize;
};


