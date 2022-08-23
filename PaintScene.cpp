#include "Framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	hPen[BLACK] = CreatePen(PS_SOLID, 3, COLOR_BLACK);
	hPen[RED]	= CreatePen(PS_SOLID, 3, COLOR_RED);
	hPen[GREEN] = CreatePen(PS_SOLID, 3, COLOR_GREEN);
	hPen[BLUE]	= CreatePen(PS_SOLID, 3, COLOR_BLUE);

	hBrush[BLACK] = CreateSolidBrush(COLOR_BLACK);
	hBrush[RED] = CreateSolidBrush(COLOR_RED);
	hBrush[GREEN] = CreateSolidBrush(COLOR_GREEN);
	hBrush[BLUE] = CreateSolidBrush(COLOR_BLUE);

	hdc = GetDC(hWnd);
}

PaintScene::~PaintScene()
{
	for (UINT i = 0; i < 4; i++)
	{
		DeleteObject(hPen[i]);
		DeleteObject(hBrush[i]);
	}

	ReleaseDC(hWnd, hdc);
}

void PaintScene::Update()
{
	SetState();

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		if(!isClick)
			LButtonDown();
	}
	else
	{
		if(isClick)
			LButtonUp();
	}
}

void PaintScene::Render(HDC hdc)
{
	
}

void PaintScene::LButtonDown()
{
	isClick = true;

	startPos = mousePos;
}

void PaintScene::LButtonUp()
{
	isClick = false;
	endPos = mousePos;

	DrawObjects();

}

void PaintScene::DrawPen()
{
}

void PaintScene::DrawObjects()
{
	SelectObject(hdc, hPen[color]);
	SelectObject(hdc, hBrush[color]);

	switch (type)
	{
	case PaintScene::LINE:
		MoveToEx(hdc, startPos.x, startPos.y, nullptr);
		LineTo(hdc, endPos.x, endPos.y);
		break;
	case PaintScene::RECT:
		Rectangle(hdc, startPos.x, startPos.y, endPos.x, endPos.y);
		break;
	case PaintScene::ELLIPSE:
		Ellipse(hdc, startPos.x, startPos.y, endPos.x, endPos.y);
		break;
	default:
		break;
	}
}

void PaintScene::SetState()
{
	if (GetAsyncKeyState('1'))
		type = PEN;
	if (GetAsyncKeyState('2'))
		type = LINE;
	if (GetAsyncKeyState('3'))
		type = RECT;
	if (GetAsyncKeyState('4'))
		type = ELLIPSE;

	if (GetAsyncKeyState(VK_F1))
		color = BLACK;
	if (GetAsyncKeyState(VK_F2))
		color = RED;
	if (GetAsyncKeyState(VK_F3))
		color = GREEN;
	if (GetAsyncKeyState(VK_F4))
		color = BLUE;
}
