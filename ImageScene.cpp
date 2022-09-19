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
	//SelectObject(memDC, hBitmap);

	ReleaseDC(hWnd, hdc);	//화면에 그려지는 DC는 ReleaseDC로 지워준다.

	rockMan = (HBITMAP)LoadImage
	(
		hInst,
		L"Texture/록맨.bmp",
		IMAGE_BITMAP,
		480, 100,
		LR_LOADFROMFILE
	);

	airplaneTexture = new Texture(L"Texture/airplane.bmp", { 281, 278 });

	//원본 상관없이 얼마만큼 사용할것인가.
	airplaneRect = new Rect(WIN_CENTER, Vector2(300, 300));


	rockManTexture = new Texture(L"Texture/록맨.bmp", { 480, 100 }, {10,2});
	rockManRect	   = new Rect({ 100,100 }, rockManTexture->GetTextureSize());
}

ImageScene::~ImageScene()
{
	DeleteDC(memDC);		//가상 DC들은 deleteDC로 지워준다.

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

	//memDC(가상공간)에 있는 비트맵 정보를 backDC로 보낸다. 
	//BitBlt
	//(
	//	backDC, WIN_CENTER.x, WIN_CENTER.y, 281, 278,
	//	memDC, 0,0, SRCCOPY
	//);

	//StretchBlt  이미지 길이 변경은 가능하지만 마젠타색 처리는 안하는 함수
	//(
	//	backDC,0,0, 500, 500,
	//	memDC, 0, 0, 281, 278, SRCCOPY
	//);

	//SelectObject(memDC, hBitmap);

	//GdiTransparentBlt    //마지막 인자는 투명처리할 색상 입력
	//(
	//	backDC, 0, 0, 500, 500,
	//	memDC, 0, 0, 281, 278, COLOR_MAGENTA
	//);

	//SelectObject(memDC, rockMan);


	//GdiTransparentBlt    //마지막 인자는 투명처리할 색상 입력
	//(
	//	backDC,          WIN_CENTER.x,         WIN_CENTER.y, 480/10, 100/2,
	//	memDC,  (480/10) * curFrame.x, (100/2) * curFrame.y, 480/10, 100/2,
	//	COLOR_MAGENTA
	//);

	airplaneTexture->Render(airplaneRect);

	rockManTexture->Render(rockManRect, curFrame);
}

