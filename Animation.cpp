#include "Framework.h"
#include "Animation.h"

Animation::Animation(Texture* texture, double updateTime)
	:updateTime(updateTime), texture(texture)
{
	
	UINT nX = texture->GetFrameSize().x;
	UINT nY = texture->GetFrameSize().y;

	maxPlayIndex = nX * nY;

	for (UINT i = 0; i < maxPlayIndex; i++)
	{
		long x = i % nX;
		long y = i / nX;

		frames.push_back({ x,y });
	}
}

Animation::~Animation()
{
}

void Animation::Update()
{
	if (!isPlay)
		return;

	time += Time::Delta();	//TODO : Time 설정

	if (time > updateTime)
	{
		time = 0;
		curPlayIndex++;

		//동작이 끝났으면
		if (curPlayIndex >= indexes.size())
		{
			//반복 or 한번 동작인지 체크해서 초기화
			if (isLoop)
			{
				curPlayIndex = 0;
			}
			else
			{
				curPlayIndex--;
				isPlay = false;
			}
		}
	}
}

void Animation::Render(Rect* rect)
{
	texture->Render(rect, GetCurFrame());
}

void Animation::SetDefault(bool isLoop)
{
	this->isLoop = isLoop;

	indexes.clear();

	for (UINT i = 0; i < maxPlayIndex; i++)
	{
		indexes.push_back(i);
	}
}

void Animation::SetPart(int start, int end, bool isLoop)
{
	this->isLoop = isLoop;

	indexes.clear();

	if (end > start)
	{
		for (int i = start; i <= end; i++)
		{
			indexes.push_back(i);
		}
	}
	else
	{
		for (int i = start; i >= end; i--)
		{
			indexes.push_back(i);
		}
	}
}

void Animation::SetVector(vector<UINT> vector, bool isLoop)
{
	this->isLoop = isLoop;

	indexes.clear();

	indexes = vector;
}
