#include "Framework.h"
#include "Time.h"

Time* Time::instance = nullptr;

double Time::timeElapsed = 0;

Time::Time()
{
	//초당 CPU 진동(tick) 수
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);

	//CPU 진동(tick) 누적 값
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTick);

	//1tick에 걸리는 값
	//double로 만들기 위해 1.0으로 사용
	timeScale = 1.0 / ticksPerSecond;
}

Time::~Time()
{
}

Time* Time::Get()
{
	if (instance == nullptr)
		instance = new Time();

	return instance;
}

void Time::Delete()
{
	if (instance != nullptr)
		delete instance;
}

void Time::Update()
{
	
	QueryPerformanceCounter((LARGE_INTEGER*)&curTick);

	//1프레임에 걸린 시간 (흐른 시간)
	timeElapsed = (curTick - lastTick) * timeScale;

	//수직 동기화
	//예를 들어 100프레임으로 정하면 초당 100프레임을 넘지 않게 하겠다는것이다.
	//즉 프레임 카운트는 1/100초가 될때만 증가하도록 강제로 맞추는 방식.
	if (scanningRate != 0)
	{
		while (timeElapsed < (1.0 / scanningRate))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&curTick);
			timeElapsed = (curTick - lastTick) * timeScale;
		}
	}



	lastTick = curTick;

	frameCount++;

	//1초 체크를 위한 변수
	oneSecCount += timeElapsed;

	//프로그램 시작 후 경과 시간
	runningTime += timeElapsed;

	//1초동안 몇프레임 흘렀는지 체크 가능
	if (oneSecCount >= 1.0)
	{
		oneSecCount = 0;

		frameRate = frameCount;
		frameCount = 0;
	}
}

void Time::Render()
{
	wstring str;

	str = L"RunningTime : " + to_wstring(runningTime);
	TextOut(backDC, 0, 20, str.c_str(), str.size());

	str = L"FPS         : " + to_wstring(frameRate);
	TextOut(backDC, 0, 40, str.c_str(), str.size());

}
