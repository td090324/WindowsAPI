#pragma once
class CannonBallManager
{
public:
	//매개변수에 초기값을 준다.
	//매개변수가 안들어오면 기본값이 30. 다른값이 들어오면 그 값이 적용.
	//꼭 헤더에서 정의해야하며 기본값은 매개변수의 순서에서 맨 뒤에 위치해야한다.
	CannonBallManager(UINT poolCount = 30);
	~CannonBallManager();

	void Update();
	void Render(HDC hdc);

	void Fire(Point pos, double angle, double power);

private:
	vector<CannonBall*> cannonBalls;
};


