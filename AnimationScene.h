#pragma once
class AnimationScene : public Scene
{
public:
	AnimationScene();
	~AnimationScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Texture*	marioTex;
	Rect*		marioRect;
	Animation*  marioAnim;

};



