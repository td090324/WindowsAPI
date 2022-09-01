#include "Framework.h"
#include "Tank.h"

Tank::Tank()
{
	body = new Rect(Point(200, 500), Point(200,100));

	barrel = new Line(body->Pos(), Point(body->Pos().x + barrelLength, body->Pos().y));

	ball = new CannonBall();
}

Tank::~Tank()
{
	delete body;
	delete barrel;

	delete ball;
}

void Tank::Update()
{
	RotateBarrel();

	MoveBody();

	FireBall();

	ball->Update();
}

void Tank::Render(HDC hdc)
{
	body->Render(hdc);
	barrel->Render(hdc);

	ball->Render(hdc);
}

void Tank::RotateBarrel()
{
	//Rotate Barrel
	if (GetAsyncKeyState(VK_UP))
		barrelAngle += 0.05f; //���Ȱ�
	else if (GetAsyncKeyState(VK_DOWN))
		barrelAngle -= 0.05f;

	//���� End�� ����
	barrel->End().x = body->Pos().x + barrelLength * cos(barrelAngle);
	barrel->End().y = body->Pos().y - barrelLength * sin(barrelAngle);
}

void Tank::MoveBody()
{
	//��ũ�� ��ü�� ��Ʈ �̵�
	if (GetAsyncKeyState(VK_LEFT))
		body->Pos().x -= speed;
	if (GetAsyncKeyState(VK_RIGHT))
		body->Pos().x += speed;

	//���ŵ� ��ũ ��ġ�� �°� ������Ʈ
	barrel->Start() = body->Pos();
}

void Tank::FireBall()
{
	if (GetAsyncKeyState(VK_SPACE))
		ball->Fire(barrel->End(), barrelAngle, 20);
}
