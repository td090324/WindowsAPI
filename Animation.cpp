#include "Framework.h"
#include "Animation.h"

Animation::Animation(Texture* texture, double updateTime)
	:updateTime(updateTime)
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
