#include "Framework.h"
#include "ImageScene.h"

ImageScene::ImageScene()
{
	//�̹��� ������ ��Ʈ�ʿ� ����.
	hBitmap = (HBITMAP)LoadImage
	(
		hInst, 
		L"Texture/airplane.bmp", //��δ� ���� �ַ���̴�.
		IMAGE_BITMAP,
		281, 278,				 //�̹��� ������
		LR_LOADFROMFILE
	);

	HDC hdc = GetDC(hWnd);

	memDC = CreateCompatibleDC(hdc);

	//���� ������ ��Ʈ�� ������ ����.
	SelectObject(memDC, hBitmap);

	ReleaseDC(hWnd, hdc);	//ȭ�鿡 �׷����� DC�� ReleaseDC�� �����ش�.
}

ImageScene::~ImageScene()
{
	DeleteDC(memDC);		//���� DC���� deleteDC�� �����ش�.

	DeleteObject(hBitmap);
}

void ImageScene::Update()
{
}

void ImageScene::Render(HDC hdc)
{

	//memDC(�������)�� �ִ� ��Ʈ�� ������ backDC�� ������. 
	BitBlt
	(
		backDC, WIN_CENTER.x, WIN_CENTER.y, 281, 278,
		memDC, 0,0, SRCCOPY
	);
}

