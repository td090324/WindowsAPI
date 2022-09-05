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
	//	barrelAngle += 0.05f; //라디안값
	//else if (GetAsyncKeyState(VK_DOWN))
	//	barrelAngle -= 0.05f;

	////포신 End값 변경
	//barrel->End().x = body->Pos().x + barrelLength * cos(barrelAngle);
	//barrel->End().y = body->Pos().y - barrelLength * sin(barrelAngle);

	//포신을 마우스 위치를 바라보게 방향 구하기
	//벡터 구하기
	Vector2 dir = mousePos - body->Pos();

	//뒤집어진 좌표계라 -적용
	barrelAngle = atan2(-dir.y, dir.x);

	//barrel->End().x = body->Pos().x + barrelLength * cos(barrelAngle);
	//barrel->End().y = body->Pos().y - barrelLength * sin(barrelAngle);
	
	dir.Normalize();

	barrel->End() = body->Pos() + dir * barrelLength;
}

void Tank::MoveBody()
{
	//탱크의 몸체인 렉트 이동
	if (GetAsyncKeyState(VK_LEFT))
		body->Pos() += Vector2(-1, 0) * speed; //방향벡터로 변경
		//body->Pos().x -= speed;
	if (GetAsyncKeyState(VK_RIGHT))
		body->Pos() += Vector2(1, 0) * speed;
		//body->Pos().x += speed;

	//포신도 탱크 위치에 맞게 업데이트
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
