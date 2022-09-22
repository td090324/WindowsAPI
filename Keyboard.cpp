#include "Framework.h"
#include "Keyboard.h"

Keyboard* Keyboard::instance = nullptr;

Keyboard::Keyboard()
{
	/*
	배열 초기화 방법
	
	1. 변수 선언 시 ={};
	2. ZeroMemory
	3. memset
	*/

	//memset(keyCurState, 0, sizeof(keyCurState));
	//memset을 재정의한 함수이지만 다른점은 0으로 초기화를 고정시켜놓은 함수.
	//보통 중간에 배열 데이터를 날리고 싶을때 사용.
	ZeroMemory(keyCurState, sizeof(keyCurState));
	ZeroMemory(keyOldState, sizeof(keyOldState));
	ZeroMemory(keyMap, sizeof(keyMap));
}

Keyboard::~Keyboard()
{
}


void Keyboard::Delete()
{
	if (instance != nullptr)
		delete instance;
}

void Keyboard::Update()
{
	//배열을 복사하는 방법으로 memcpy
	//이전 프레임 상태를 전체 기록
	memcpy(keyOldState, keyCurState, sizeof(keyCurState));

	ZeroMemory(keyCurState, sizeof(keyCurState));
	ZeroMemory(keyMap, sizeof(keyMap));

	//반환값은 총 4가지
	// 아마 프레임마다 체크하려고 반환값을 나눈 것이 아닐까라는.
	//0 또는 1 반환 -     키보드를 누르지 않은 상태
	//128 또는 129 반환 - 키보드를 누른 상태
	GetKeyboardState(keyCurState);

	/*
	삼항 연산자
	조건식 ? TRUE일때 반환값 : FALSE일때 반환값
	DOWN, UP / keyCurState ? "DOWN" : "UP
	*/

	for (UINT i = 0; i < MAX_KEY; i++)
	{
		//상태가 4가지 나오는 것을 2가지로 변경하는 방법
		//0x80을 0x81(129) 또는 1, 0을 &연산자-비트연산자 하면
		//0x80 또는 0x00이 된다.
		BYTE key = keyCurState[i] & 0x80;

		//0이나 1이면 0으로 나오니 배열에 0으로 다시 들어가고
		//128, 129는 128로 나오니 1로 다시 들어간다.
		keyCurState[i] = key ? 1 : 0;

		BYTE old = keyOldState[i];
		BYTE cur = keyCurState[i];

		if (old == 0 && cur == 1)	//이전에는 false, 현재는 true : DOWN
			keyMap[i] = DOWN;
		else if (old == 1 && cur == 0) //이전에는 true, 현재는 flase : UP
			keyMap[i] = UP;
		else if (old == 1 && cur == 1) //이전에는 true, 현재도 true : PRESS
			keyMap[i] = PRESS;
		else
			keyMap[i] = NONE;
	}
}

Keyboard* Keyboard::Get()
{
	if (instance == nullptr)
		instance = new Keyboard();

	return instance;
}
