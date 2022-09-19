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
	//SelectObject(memDC, hBitmap);

	ReleaseDC(hWnd, hdc);	//ȭ�鿡 �׷����� DC�� ReleaseDC�� �����ش�.

	rockMan = (HBITMAP)LoadImage
	(
		hInst,
		L"Texture/�ϸ�.bmp",
		IMAGE_BITMAP,
		480, 100,
		LR_LOADFROMFILE
	);

	airplaneTexture = new Texture(L"Texture/airplane.bmp", { 281, 278 });

	//���� ������� �󸶸�ŭ ����Ұ��ΰ�.
	airplaneRect = new Rect(WIN_CENTER, Vector2(300, 300));


	rockManTexture = new Texture(L"Texture/�ϸ�.bmp", { 480, 100 }, {10,2});
	rockManRect	   = new Rect({ 100,100 }, rockManTexture->GetTextureSize());
}

ImageScene::~ImageScene()
{
	DeleteDC(memDC);		//���� DC���� deleteDC�� �����ش�.

	DeleteObject(hBitmap);

	DeleteObject(rockMan);

	delete airplaneTexture;
	delete airplaneRect;

	delete rockManTexture;
	delete rockManRect;
}

void ImageScene::Update()
{
	time++;

	curFrame.y = 1;

	if (time > 10)
	{
		++curFrame.x %= 10;
		time = 0;
	}

	if (GetAsyncKeyState(VK_LEFT))
		airplaneRect->Pos() += Vector2(-1, 0) * 5;

	if (GetAsyncKeyState(VK_RIGHT))
		airplaneRect->Pos() += Vector2(+1, 0) * 5;
}

void ImageScene::Render(HDC hdc)
{

	//memDC(�������)�� �ִ� ��Ʈ�� ������ backDC�� ������. 
	//BitBlt
	//(
	//	backDC, WIN_CENTER.x, WIN_CENTER.y, 281, 278,
	//	memDC, 0,0, SRCCOPY
	//);

	//StretchBlt  �̹��� ���� ������ ���������� ����Ÿ�� ó���� ���ϴ� �Լ�
	//(
	//	backDC,0,0, 500, 500,
	//	memDC, 0, 0, 281, 278, SRCCOPY
	//);

	//SelectObject(memDC, hBitmap);

	//GdiTransparentBlt    //������ ���ڴ� ����ó���� ���� �Է�
	//(
	//	backDC, 0, 0, 500, 500,
	//	memDC, 0, 0, 281, 278, COLOR_MAGENTA
	//);

	//SelectObject(memDC, rockMan);


	//GdiTransparentBlt    //������ ���ڴ� ����ó���� ���� �Է�
	//(
	//	backDC,          WIN_CENTER.x,         WIN_CENTER.y, 480/10, 100/2,
	//	memDC,  (480/10) * curFrame.x, (100/2) * curFrame.y, 480/10, 100/2,
	//	COLOR_MAGENTA
	//);

	airplaneTexture->Render(airplaneRect);

	rockManTexture->Render(rockManRect, curFrame);
}

