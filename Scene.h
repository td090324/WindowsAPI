#pragma once

//�������̽�  - ���������Լ��θ� �̷���� Ŭ����
//�߻�Ŭ���� - ���������Լ��� �Ѱ��� �ִ� Ŭ����
class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Update() = 0;	//������ ������ ���ִ� �Լ�.
	virtual void Render(HDC hdc) = 0;	//ȭ���� �������ִ� �Լ�.

};

