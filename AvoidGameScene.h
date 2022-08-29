#pragma once
class AvoidGameScene : public Scene
{


public:
	AvoidGameScene();
	~AvoidGameScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;


private:
	vector<Poo*> objects;
	
	int cooltime;
	int randomTime;
};



