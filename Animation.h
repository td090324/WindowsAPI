#pragma once
class Animation
{
public:
	Animation(Texture* texture, double updateTime = 0.1);
	~Animation();

	void Update();
	void Render(Rect* rect);

	void SetDefault(bool isLoop = true);	//처음부터 끝까지 재생하는 함수
	
	void SetPart(int start, int end, bool isLoop = true); //특정위치부터 재생 함수

	void SetVector(vector<UINT> vector, bool isLoop = true); //원하는 동작을 만들 수 있는 함수

	//현재 동작 한개 프레임(x,y)
	POINT GetCurFrame() { return frames[indexes[curPlayIndex]]; }

private:
	vector<POINT>  frames;
	vector<UINT>  indexes;

	UINT curPlayIndex = 0;
	UINT maxPlayIndex = 0;

	double time = 0;
	double updateTime=0;   		//updateTime는 애니메이션 갱신 주기

	bool isPlay= true;
	bool isLoop= true;			//애니메이션 반복 여부

	Texture* texture;
};



