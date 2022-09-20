#pragma once
class Animation
{
public:
	Animation(Texture* texture, double updateTime = 0.1);
	~Animation();

	void Update();
	void Render(Rect* rect);

	void SetDefault(bool isLoop = true);	//ó������ ������ ����ϴ� �Լ�
	
	void SetPart(int start, int end, bool isLoop = true); //Ư����ġ���� ��� �Լ�

	void SetVector(vector<UINT> vector, bool isLoop = true); //���ϴ� ������ ���� �� �ִ� �Լ�

	//���� ���� �Ѱ� ������(x,y)
	POINT GetCurFrame() { return frames[indexes[curPlayIndex]]; }

private:
	vector<POINT>  frames;
	vector<UINT>  indexes;

	UINT curPlayIndex = 0;
	UINT maxPlayIndex = 0;

	double time = 0;
	double updateTime=0;   		//updateTime�� �ִϸ��̼� ���� �ֱ�

	bool isPlay= true;
	bool isLoop= true;			//�ִϸ��̼� �ݺ� ����

	Texture* texture;
};



