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

		if (type == PEN)
			DrawPen();
	}
	else
	{
		if(isClick)
			LButtonUp();

	}




}

void PaintScene::Render(HDC hdc)
{
	Debug();

	DrawObjects();

	if(isClick)
		Preview();
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

	Data data;
	data.startPos = this->startPos;
	data.endPos = this->endPos;
	data.color = this->color;
	data.type = this->type;

	objects.push_back(data);
}

void PaintScene::DrawPen()
{
	SelectObject(hdc, hPen[color]);
	SelectObject(hdc, hBrush[color]);

	endPos = mousePos;

	MoveToEx(hdc, startPos.x, startPos.y, nullptr);
	LineTo(hdc, endPos.x, endPos.y);

	startPos = endPos;
}

void PaintScene::DrawObjects()
{
	//범위 기반 for문
	for (Data data : objects)
	{
		SelectObject(hdc, hPen[data.color]);
		SelectObject(hdc, hBrush[data.color]);

		switch (data.type)
		{
		case PaintScene::LINE:
			MoveToEx(hdc, data.startPos.x, data.startPos.y, nullptr);
			LineTo(hdc, data.endPos.x, data.endPos.y);
			break;
		case PaintScene::RECT:
			Rectangle(hdc, data.startPos.x, data.startPos.y, data.endPos.x, data.endPos.y);
			break;
		case PaintScene::ELLIPSE:
			Ellipse(hdc, data.startPos.x, data.startPos.y, data.endPos.x, data.endPos.y);
			break;
		default:
			break;
		}
	}

	/*for (UINT i = 0; i < objects.size(); i++)
	{
		SelectObject(hdc, hPen[color]);
		SelectObject(hdc, hBrush[color]);

		switch (type)
		{
		case PaintScene::LINE:
			MoveToEx(hdc, objects[i].startPos.x, objects[i].startPos.y, nullptr);
			LineTo(hdc, objects[i].endPos.x, objects[i].endPos.y);
			break;
		case PaintScene::RECT:
			Rectangle(hdc, objects[i].startPos.x, objects[i].startPos.y, objects[i].endPos.x, objects[i].endPos.y);
			break;
		case PaintScene::ELLIPSE:
			Ellipse(hdc, objects[i].startPos.x, objects[i].startPos.y, objects[i].endPos.x, objects[i].endPos.y);
			break;
		default:
			break;
		}
	}*/

	/*SelectObject(hdc, hPen[color]);
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
	}*/
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

void PaintScene::Preview()
{
	SelectObject(hdc, hPen[color]);
	SelectObject(hdc, hBrush[color]);

	switch (type)
	{
	case PaintScene::LINE:
		MoveToEx(hdc, startPos.x, startPos.y, nullptr);
		LineTo(hdc, mousePos.x, mousePos.y);
		break;
	case PaintScene::RECT:
		Rectangle(hdc, startPos.x, startPos.y, mousePos.x, mousePos.y);
		break;
	case PaintScene::ELLIPSE:
		Ellipse(hdc, startPos.x, startPos.y, mousePos.x, mousePos.y);
		break;
	default:
		break;
	}
}

void PaintScene::Debug()
{
	wstring str;

	str = L"1: PEN, 2: LINE, 3: RECT, 4: ELLIPSE";
	TextOut(hdc, 0, 0, str.c_str(), str.size());

	str = L"F1: BLACK, F2: RED, F3: GREEN, F4: BLUE";
	TextOut(hdc, 0, 20, str.c_str(), str.size());

}
