#pragma once
class Texture
{
public:
	//���� ���, �̹��� ������, ���� ����
	Texture(wstring path, POINT imageSize, POINT frameSize = {1,1}, COLORREF transColor = COLOR_MAGENTA);
	~Texture();

	//backDC�� extern�̱⶧���� �ٷ� ����ϸ�ȴ�.
	//���� �̹����� rect�� �����ؼ� backDC�� �Ѱ��� ���̴�.
	//rect�� �ؾ� �̹��� �浹ó���� �����ϱ� �����̴�.
	//��������Ʈ �̹����̱� ������ curframe���� POINT�������� �־��ش�.
	void Render(Rect* rect, POINT curFrame = {0,0});

	Vector2 GetTextureSize() { return { (double)textureSize.x, (double)textureSize.y }; }
	POINT GetFrameSize() { return frameSize; }


private:
	HDC memDC;
	HBITMAP bitmap;
	
	COLORREF transColor;

	POINT imageSize;	//���� �̹��� ũ��
	POINT frameSize;	//�ڸ� ������ ���� (�� ���� ����)
	POINT textureSize;	//�߶��� �̹��� ũ��
};


