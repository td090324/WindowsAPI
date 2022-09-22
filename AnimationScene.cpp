#include "Framework.h"
#include "AnimationScene.h"

AnimationScene::AnimationScene()
{
	marioTex = new Texture(L"Texture/mario_all.bmp", { 512,328 }, {8,4});

	marioRect = new Rect(WIN_CENTER, marioTex->GetTextureSize());

	marioAnim = new Animation(marioTex);
	//marioAnim->SetDefault();
	//marioAnim->SetPart(7, 4);
	marioAnim->SetVector({28,27,24,26});
}

AnimationScene::~AnimationScene()
{
	delete marioTex;
	delete marioRect;
	delete marioAnim;
}

void AnimationScene::Update()
{
	if (Keyboard::Get()->Press(VK_LEFT))
		marioRect->Pos() += Vector2(-1, 0) * 100 * Time::Delta();

	if (Keyboard::Get()->Press(VK_RIGHT))
		marioRect->Pos() += Vector2(+1, 0) * 100 * Time::Delta();

	marioAnim->Update();
}

void AnimationScene::Render(HDC hdc)
{
	//marioTex->Render(marioRect, marioAnim->GetCurFrame());
	marioAnim->Render(marioRect);
}
