#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	srand(time(NULL));

	HDC hdc = GetDC(hWnd);
	hBitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	backDC = CreateCompatibleDC(hdc);

	SelectObject(backDC, hBitmap);

	//업캐스팅
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
	//BackDC만 초기화 시키기 위한 함수.
	//이걸 해야 잔상이 남지 않는다.
	//랜더 전에 backDC를 WHITENESS로 화면을 하얗게 지우고 Render
	PatBlt
	(
		backDC, 0,0, WIN_WIDTH, WIN_HEIGHT, WHITENESS
	);

	scene->Render(backDC);

	Time::Get()->Render();

	//MousePos
	wstring str = L"MousePos : " + to_wstring((int)mousePos.x) + L", " + to_wstring((int)mousePos.y);
	TextOut(backDC, 0,0,str.c_str(), str.size());

	//비트단위로 복사하는 함수
	//원본(backDC)에 있는 비트맵을 복사해서 앞DC에 붙여넣는 형식.
	//sorce가 있으면 destination함께 있다.
	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, backDC, 0, 0, SRCCOPY);
}
