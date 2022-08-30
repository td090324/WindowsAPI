#pragma once
class AvoidGameScene : public Scene
{


public:
	AvoidGameScene();
	~AvoidGameScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Collision();


private:
	vector<Poo*> objects;

	AvoidPlayer* player;
	
	int cooltime;
	int randomTime;

	bool isPlay = true;
};



