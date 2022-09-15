#include "Framework.h"
#include "ImageScene.h"

ImageScene::ImageScene()
{
	//이미지 정보를 비트맵에 저장.
	hBitmap = (HBITMAP)LoadImage
	(
		hInst, 
		L"Texture/airplane.bmp", //경로는 보통 솔루션이다.
		IMAGE_BITMAP,
		281, 278,				 //이미지 사이즈
		LR_LOADFROMFILE
	);

	HDC hdc = GetDC(hWnd);

	memDC = CreateCompatibleDC(hdc);

	//가상 공간에 비트맵 정보가 담긴다.
	SelectObject(memDC, hBitmap);

	ReleaseDC(hWnd, hdc);	//화면에 그려지는 DC는 ReleaseDC로 지워준다.
}

ImageScene::~ImageScene()
{
	DeleteDC(memDC);		//가상 DC들은 deleteDC로 지워준다.

	DeleteObject(hBitmap);
}

void ImageScene::Update()
{
}

void ImageScene::Render(HDC hdc)
{

	//memDC(가상공간)에 있는 비트맵 정보를 backDC로 보낸다. 
	BitBlt
	(
		backDC, WIN_CENTER.x, WIN_CENTER.y, 281, 278,
		memDC, 0,0, SRCCOPY
	);
}

