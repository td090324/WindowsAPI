#include "Framework.h"
#include "Tank.h"

Tank::Tank()
{
	body = new Rect(Point(200, 500), Point(200,100));

	barrel = new Line(body->Pos(), Point(body->Pos().x + barrelLength, body->Pos().y));

	//ball = new CannonBall();
	balls = new CannonBallManager();
}

Tank::~Tank()
{
	delete body;
	delete barrel;

	delete balls;
}

void Tank::Update()
{
	RotateBarrel();

	MoveBody();

	FireBall();

	balls->Update();
}

void Tank::Render(HDC hdc)
{
	body->Render(hdc);
	barrel->Render(hdc);

	balls->Render(hdc);
}

void Tank::RotateBarrel()
{
	//Rotate Barrel
	if (GetAsyncKeyState(VK_UP))
		barrelAngle += 0.05f; //라디안값
	else if (GetAsyncKeyState(VK_DOWN))
		barrelAngle -= 0.05f;

	//포신 End값 변경
	barrel->End().x = body->Pos().x + barrelLength * cos(barrelAngle);
	barrel->End().y = body->Pos().y - barrelLength * sin(barrelAngle);

	//포신을 마우스 위치를 바라보게 방향 구하기
	//Vector2 dir = mousePos

}

void Tank::MoveBody()
{
	//탱크의 몸체인 렉트 이동
	if (GetAsyncKeyState(VK_LEFT))
		body->Pos().x -= speed;
	if (GetAsyncKeyState(VK_RIGHT))
		body->Pos().x += speed;

	//포신도 탱크 위치에 맞게 업데이트
	barrel->Start() = body->Pos();
}

void Tank::FireBall()
{
	if (GetAsyncKeyState(VK_SPACE))
		balls->Fire(barrel->End(), barrelAngle, 200);
}
