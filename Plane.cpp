#include "Framework.h"
#include "Plane.h"

Plane::Plane()
{
	texture = new Texture(L"Texture/airplane.bmp", { 281,278 });

	rect = new Rect({ WIN_CENTER.x, WIN_HEIGHT * 0.8 }, texture->GetTextureSize());

	bullet = new Bullet(new Texture(L"Texture/PBullet.bmp", { 28,28 }));
}

Plane::~Plane()
{
	delete texture;
	delete rect;
	delete bullet;
}

void Plane::Update()
{
	//�ð��� ���ǵ忡 ����ϴ� ���⺤�͸� �� �����Ӹ��� �����ָ鼭 �̵���Ű��
	if (Keyboard::Get()->Press(VK_LEFT))
		rect->Pos() += Vector2(-1, 0) * speed * Time::Delta();

	if (Keyboard::Get()->Press(VK_RIGHT))
		rect->Pos() += Vector2(+1, 0) * speed * Time::Delta();

	if (Keyboard::Get()->Press(VK_UP))
		rect->Pos() += Vector2(0, -1) * speed * Time::Delta();

	if (Keyboard::Get()->Press(VK_DOWN))
		rect->Pos() += Vector2(0, +1) * speed * Time::Delta();

	bullet->Update();

	Shoot();
}

void Plane::Render()
{
	texture->Render(rect);
	bullet->Render();
}

void Plane::Shoot()
{
	if (Keyboard::Get()->Down(VK_SPACE))
		bullet->Fire(rect->Pos(), Vector2(0, -1), 500.0);
}
