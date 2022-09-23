#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	srand(time(NULL));

	HDC hdc = GetDC(hWnd);
	hBitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	backDC = CreateCompatibleDC(hdc);

	SelectObject(backDC, hBitmap);

	//��ĳ����
	//scene = new TutorialScene();
	//scene = new PaintScene();
	//scene = new CollisionScene();
	//scene = new AvoidGameScene();
	//scene = new AngleScene();
	//scene = new ArkanoidScene();
	//scene = new ImageScene();
	//scene = new AnimationScene();
	scene = new ShootingScene();
}

MainGame::~MainGame()
{
	delete scene;

	//Check
	DeleteObject(hBitmap);

	Time::Delete();
	Keyboard::Delete();
}

void MainGame::Update()
{
	Time::Get()->Update();
	Keyboard::Get()->Update();

	scene->Update();
}

void MainGame::Render(HDC hdc)
{
	//PatternBlt
	//BackDC�� �ʱ�ȭ ��Ű�� ���� �Լ�.
	//�̰� �ؾ� �ܻ��� ���� �ʴ´�.
	//���� ���� backDC�� WHITENESS�� ȭ���� �Ͼ�� ����� Render
	PatBlt
	(
		backDC, 0,0, WIN_WIDTH, WIN_HEIGHT, WHITENESS
	);

	scene->Render(backDC);

	Time::Get()->Render();

	//MousePos
	wstring str = L"MousePos : " + to_wstring((int)mousePos.x) + L", " + to_wstring((int)mousePos.y);
	TextOut(backDC, 0,0,str.c_str(), str.size());

	//��Ʈ������ �����ϴ� �Լ�
	//����(backDC)�� �ִ� ��Ʈ���� �����ؼ� ��DC�� �ٿ��ִ� ����.
	//sorce�� ������ destination�Բ� �ִ�.
	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, backDC, 0, 0, SRCCOPY);
}
