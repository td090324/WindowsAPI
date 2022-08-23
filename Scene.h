#pragma once

//인터페이스  - 순수가상함수로만 이루어진 클래스
//추상클래스 - 순수가상함수가 한개라도 있는 클래스
class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Update() = 0;	//정보를 갱신을 해주는 함수.
	virtual void Render(HDC hdc) = 0;	//화면을 갱신해주는 함수.

};

