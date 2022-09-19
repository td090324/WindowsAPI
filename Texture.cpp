#include "Framework.h"
#include "Texture.h"


Texture::Texture(wstring path, POINT imageSize, POINT frameSize, COLORREF transColor)
	:transColor(transColor), imageSize(imageSize), frameSize(frameSize)
{

	bitmap = (HBITMAP)LoadImage
	(
		hInst,
		path.c_str(),
		IMAGE_BITMAP,
		imageSize.x, imageSize.y,
		LR_LOADFROMFILE
	);

	HDC hdc = GetDC(hWnd);

	memDC = CreateCompatibleDC(hdc);

	ReleaseDC(hWnd, hdc);

	SelectObject(memDC, bitmap);

	textureSize = {imageSize.x / frameSize.x, imageSize.y / frameSize.y};

}

Texture::~Texture()
{
	DeleteDC(memDC);
	DeleteObject(bitmap);
}

void Texture::Render(Rect* rect, POINT curFrame)
{
	GdiTransparentBlt 
	(
		backDC, 
		rect->Left(), rect->Top(), 
		rect->Size().x, rect->Size().y,
		memDC,
		textureSize.x * curFrame.x, textureSize.y * curFrame.y, 
		textureSize.x, textureSize.y,
		COLOR_MAGENTA
	);
}
