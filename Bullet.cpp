#include "Framework.h"
#include "Bullet.h"

Bullet::Bullet(Texture* texture)
	:texture(texture)
{
	rect = new Rect({ 0,0 }, texture->GetTextureSize());
}

Bullet::~Bullet()
{
	delete rect;
}

void Bullet::Update()
{
	if (!isFire)
		return;

	rect->Pos() += dir * power * Time::Delta();
}

void Bullet::Render()
{
	if (!isFire)
		return;

	texture->Render(rect);
}

void Bullet::Fire(Vector2 pos, Vector2 dir, double power)
{
	rect->Pos() = pos;
	this->dir = dir;
	this->power = power;

	isFire = true;
}
