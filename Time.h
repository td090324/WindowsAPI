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

	//시간의 변화량.
	static double Delta() { return timeElapsed; }

private:
	static Time* instance;

	static double timeElapsed;	//경과 시간

	double timeScale = 0;		//1Tick당 시간

	INT64	    curTick = 0;
	INT64	   lastTick = 0;
	INT64 ticksPerSecond = 0;

	UINT frameCount	= 0;
	UINT  frameRate	= 0;

	double runningTime = 0;	//프로그램 시작후 현재까지 경과한 시간

	double scanningRate = 0;	//주사율

	double oneSecCount = 0;	//1초를 카운트 하는 변수, fps기록을 위한 변수
};



