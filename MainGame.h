#pragma once
/*
FPS(Frame Per Second) vs 주사율(헤르츠hz)
비슷하지만 다른 의미다.
게임,그래픽쪽에서 프레임은 사진 한장이라는 뜻으로 사용한다.
100프레임 => 초당 100장의 사진을 뿌린다
FPS => 초당 화면 갱신 횟수

V-Sync (Vertical Synchronization) 수직 동기화
모니터 주사율에 맞춰서 컴퓨터 성능을 강제로 동기화 시킴
수직동기화 끄면 단점도 있음. 모니터가 표현을 못하면 그림이 찢어지는 현상이 나옴. 테어링현상 (어긋나는)
테어링효과를 최소화하는 기술 G-sync


주사율은?
모니터에 쓰이는 표현.
모니터가 표현할 수 있는 최대 프레임의 지표.
요즘 게임 전용 모니터가 144헤르츠
PC성능 무관하게 최대 144프레임까지만 표현 가능 

해상도(FHD : 1920 * 1080, QHD : 2560 * 1440) 두 가지가 일반적인 해상도.
DX단계에서 필요한 내용.
숫자는 픽셀(점)의 숫자. 해상도가 높아지면 좀 더 잘게 쪼개서 표현.
해상도가 높아질수록 엘리언싱(계단효과)이 낮아지고 더 부드러워진다.


*/
class MainGame
{
public:
	MainGame();
	~MainGame();

	void Update();
	void Render(HDC hdc);

private:
	Scene* scene;

	HBITMAP hBitmap;
};

