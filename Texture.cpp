#include "Framework.h"
#include "Texture.h"


Texture::Texture(wstring path, POINT imageSize, COLORREF transColor)
	:transColor(transColor), imageSize(imageSize)
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
		rect->Left(), rect->Top(), rect->Size().x, rect->Size().y,
		memDC,     0,           0,    imageSize.x,    imageSize.y,
		COLOR_MAGENTA
	);
}
