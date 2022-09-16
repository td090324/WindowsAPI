#pragma once
class Texture
{
public:
	//파일 경로, 이미지 사이즈, 제거 색상
	Texture(wstring path, POINT imageSize, COLORREF transColor = COLOR_MAGENTA);
	~Texture();

	//backDC는 extern이기때문에 바로 사용하면된다.
	//원본 이미지를 rect로 복사해서 backDC로 넘겨줄 것이다.
	//rect를 해야 이미지 충돌처리도 가능하기 때문이다.
	//스프라이트 이미지이기 때문에 curframe으로 POINT형식으로 넣어준다.
	void Render(Rect* rect, POINT curFrame = {0,0});

private:
	HDC memDC;
	HBITMAP bitmap;
	
	COLORREF transColor;

	POINT imageSize;
};


