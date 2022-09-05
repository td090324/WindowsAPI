#include "Framework.h"
#include "Tank.h"

Tank::Tank()
{
	body = new Rect(Vector2(200, 500), Vector2(200,100));

	barrel = new Line(body->Pos(), Vector2(body->Pos().x + barrelLength, body->Pos().y));

	//ball = new CannonBall();
	balls = new CannonBallManager();

	rBrush = CreateSolidBrush(COLOR_RED);

	barFront = new Rect(50, 650, 50            , 700);
	barBack = new Rect(50, 650, 50 + MAX_POWER, 700);
}

Tank::~Tank()
{
	delete body;
	delete barrel;

	//delete ball;
	delete balls;

	DeleteObject(rBrush);

	delete barFront;
	delete barBack;
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

	barBack->Render(hdc);

	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, rBrush);
	barFront->Render(hdc);
	SelectObject(hdc, rBrush);
}

void Tank::RotateBarrel()
{
	////Rotate Barrel
	//if (GetAsyncKeyState(VK_UP))
	//	barrelAngle += 0.05f; //���Ȱ�
	//else if (GetAsyncKeyState(VK_DOWN))
	//	barrelAngle -= 0.05f;

	////���� End�� ����
	//barrel->End().x = body->Pos().x + barrelLength * cos(barrelAngle);
	//barrel->End().y = body->Pos().y - barrelLength * sin(barrelAngle);

	//������ ���콺 ��ġ�� �ٶ󺸰� ���� ���ϱ�
	//���� ���ϱ�
	Vector2 dir = mousePos - body->Pos();

	//�������� ��ǥ��� -����
	barrelAngle = atan2(-dir.y, dir.x);

	//barrel->End().x = body->Pos().x + barrelLength * cos(barrelAngle);
	//barrel->End().y = body->Pos().y - barrelLength * sin(barrelAngle);
	
	dir.Normalize();

	barrel->End() = body->Pos() + dir * barrelLength;
}

void Tank::MoveBody()
{
	//��ũ�� ��ü�� ��Ʈ �̵�
	if (GetAsyncKeyState(VK_LEFT))
		body->Pos() += Vector2(-1, 0) * speed; //���⺤�ͷ� ����
		//body->Pos().x -= speed;
	if (GetAsyncKeyState(VK_RIGHT))
		body->Pos() += Vector2(1, 0) * speed;
		//body->Pos().x += speed;

	//���ŵ� ��ũ ��ġ�� �°� ������Ʈ
	barrel->Start() = body->Pos();
}

void Tank::FireBall()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		isCharging = true;
		
		power += 1;

		if (power > MAX_POWER)
			power = MAX_POWER;

		barFront->SetRect
		(
			barFront->Left(),
			barFront->Top(),
			barFront->Left() + power,
			barFront->Bottom()
		);

	}
	else if(isCharging)
	{
		Vector2 dir = mousePos - body->Pos();
		dir.Normalize();

		balls->Fire(barrel->End(), dir, power);

		isCharging = false;

		power = 200;
	}
}
