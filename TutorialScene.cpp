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

    ReleaseDC(hWnd, hdc);   //GetDC ����
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

    //���ڰ����� Ű���� �޴´�.
    if (GetAsyncKeyState(VK_LBUTTON))
    {       
        COLORREF color = RGB(255, 0, 0);

        SetPixel(hdc, mousePos.x, mousePos.y, color);       
    }

}

void TutorialScene::Render(HDC hdc)
{
    //Text
    //�迭�� ũ�⿡�� ������ ������
    //��� ó���� �ؾ��Ѵ�.
    //wstring ������ ���ȭ ��Ű�� �Լ��� c_str()
    wstring str = L"Hello, World";
    TextOut(hdc, 10, 10, str.c_str(), str.size());

    //Dot ��
    //������ RGB ���� 1����Ʈ 2^8 0~255
    //��ǻ�� ������ �������� �������.
    SetPixel(hdc, 100, 100, RGB(255, 0, 0));


    //Line ��
    //�������� ������ �������Ѵ�.
    for (int i = 0; i < 100; i++)
    {
        SetPixel(hdc, 200 + i, 100, RGB(255, 0, 0));
    }

    SelectObject(hdc, gPen);
    //������ ����ִ� �Լ�
    MoveToEx(hdc, 200, 200, nullptr);
    //������ ����ִ� �Լ�
    LineTo(hdc, 300, 300);



    SelectObject(hdc, bPen);
    SelectObject(hdc, bBrush);
    //left, top ������ x,y
    Rectangle(hdc, 350, 350, 450, 400);



    SelectObject(hdc, rPen);
    SelectObject(hdc, hBrush);
    //Ÿ��
    Ellipse(hdc, 350, 350, 450, 400);
}
