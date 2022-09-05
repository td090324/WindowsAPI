#pragma once
class CannonBallManager
{
public:
	//�Ű������� �ʱⰪ�� �ش�.
	//�Ű������� �ȵ����� �⺻���� 30. �ٸ����� ������ �� ���� ����.
	//�� ������� �����ؾ��ϸ� �⺻���� �Ű������� �������� �� �ڿ� ��ġ�ؾ��Ѵ�.
	CannonBallManager(UINT poolCount = 30);
	~CannonBallManager();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 pos, double angle, double power);
	void Fire(Vector2 pos, Vector2 dir, double power);

private:
	vector<CannonBall*> cannonBalls;
};


