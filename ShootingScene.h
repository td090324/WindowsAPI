#pragma once
class ShootingScene : public Scene
{
public:
	ShootingScene();
	~ShootingScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Plane* plane;
	Ufo* enemy;

};



