#pragma once
class Time
{
private:
	Time();
	~Time();

public:
	static Time*   Get();
	static void Delete();

	void Update();
	void Render();

	//�ð��� ��ȭ��.
	static double Delta() { return timeElapsed; }

private:
	static Time* instance;

	static double timeElapsed;	//��� �ð�

	double timeScale = 0;		//1Tick�� �ð�

	INT64	    curTick = 0;
	INT64	   lastTick = 0;
	INT64 ticksPerSecond = 0;

	UINT frameCount	= 0;
	UINT  frameRate	= 0;

	double runningTime = 0;	//���α׷� ������ ������� ����� �ð�

	double scanningRate = 0;	//�ֻ���

	double oneSecCount = 0;	//1�ʸ� ī��Ʈ �ϴ� ����, fps����� ���� ����
};



