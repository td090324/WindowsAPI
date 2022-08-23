#include "Framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    rPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
    gPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
    bPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));

    rBrush = CreateSolidBrush(RGB(255, 0, 0));
    gBrush = CreateSolidBrush(RGB(0, 255, 0));
    bBrush = CreateSolidBrush(RGB(0, 0, 255));

    hdc = GetDC(hWnd);
}

TutorialScene::~TutorialScene()
{
    DeleteObject(rPen);
    DeleteObject(gPen);
    DeleteObject(bPen);

    DeleteObject(rBrush);
    DeleteObject(gBrush);
    DeleteObject(bBrush);

    ReleaseDC(hWnd, hdc);   //GetDC 해제
}

void TutorialScene::Update()
{
    if (GetAsyncKeyState('1'))
    {
        hBrush = rBrush;
    }

    if (GetAsyncKeyState('2'))
    {
        hBrush = gBrush;
    }

    //인자값으로 키값을 받는다.
    if (GetAsyncKeyState(VK_LBUTTON))
    {       
        COLORREF color = RGB(255, 0, 0);

        SetPixel(hdc, mousePos.x, mousePos.y, color);       
    }

}

void TutorialScene::Render(HDC hdc)
{
    //Text
    //배열의 크기에는 변수가 못들어간다
    //상수 처리를 해야한다.
    //wstring 변수를 상수화 시키는 함수가 c_str()
    wstring str = L"Hello, World";
    TextOut(hdc, 10, 10, str.c_str(), str.size());

    //Dot 점
    //색상은 RGB 각각 1바이트 2^8 0~255
    //컴퓨터 색상은 섞을수록 밝아진다.
    SetPixel(hdc, 100, 100, RGB(255, 0, 0));


    //Line 선
    //시작점과 끝점을 잡아줘야한다.
    for (int i = 0; i < 100; i++)
    {
        SetPixel(hdc, 200 + i, 100, RGB(255, 0, 0));
    }

    SelectObject(hdc, gPen);
    //시작점 잡아주는 함수
    MoveToEx(hdc, 200, 200, nullptr);
    //목적지 잡아주는 함수
    LineTo(hdc, 300, 300);



    SelectObject(hdc, bPen);
    SelectObject(hdc, bBrush);
    //left, top 시작점 x,y
    Rectangle(hdc, 350, 350, 450, 400);



    SelectObject(hdc, rPen);
    SelectObject(hdc, hBrush);
    //타원
    Ellipse(hdc, 350, 350, 450, 400);
}
