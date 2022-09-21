#include "Framework.h"
#include "Time.h"

Time* Time::instance = nullptr;

double Time::timeElapsed = 0;

Time::Time()
{
	//�ʴ� CPU ����(tick) ��
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);

	//CPU ����(tick) ���� ��
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTick);

	//1tick�� �ɸ��� ��
	//double�� ����� ���� 1.0���� ���
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

	//1�����ӿ� �ɸ� �ð� (�帥 �ð�)
	timeElapsed = (curTick - lastTick) * timeScale;

	//���� ����ȭ
	//���� ��� 100���������� ���ϸ� �ʴ� 100�������� ���� �ʰ� �ϰڴٴ°��̴�.
	//�� ������ ī��Ʈ�� 1/100�ʰ� �ɶ��� �����ϵ��� ������ ���ߴ� ���.
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

	//1�� üũ�� ���� ����
	oneSecCount += timeElapsed;

	//���α׷� ���� �� ��� �ð�
	runningTime += timeElapsed;

	//1�ʵ��� �������� �귶���� üũ ����
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
