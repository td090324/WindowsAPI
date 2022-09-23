#include "Framework.h"
#include "Ufo.h"

Ufo::Ufo()
{
	texture = new Texture(L"Texture/ufo.bmp", { 530,32 }, {10,1});
	rect = new Rect({ Math::Random(0.0, (double)WIN_WIDTH), -texture->GetTextureSize().y}, texture->GetTextureSize());
	animation = new Animation(texture);
	animation->SetDefault();
}

Ufo::~Ufo()
{
	delete texture;
	delete rect;
	delete animation;
}

void Ufo::Update()
{
	animation->Update();

	rect->Pos() += dir * speed * Time::Delta();

	//러닝타임처럼 시간이 누적되는 중
	time += Time::Delta();

	RandomMove();
}

void Ufo::Render()
{
	animation->Render(rect);
}

void Ufo::RandomMove()
{
	if (time > randomTime)
	{
		time       = 0.0;
		randomTime = Math::Random(0.0, 2.0);

		dir.x *= -1;
	}
}
