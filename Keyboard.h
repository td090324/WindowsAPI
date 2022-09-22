#pragma once

#define MAX_KEY 256

enum KeyState
{
	NONE,
	DOWN,	//누른 순간 1번
	UP,
	PRESS	//누르는 동안은 계속
};

class Keyboard
{
private:
	Keyboard();
	~Keyboard();

public:
	static Keyboard* Get();		//반환

	static void Delete();		//삭제

	void Update();

	bool Down(DWORD key) { return keyMap[key] == DOWN; }
	bool Up(DWORD key) { return keyMap[key] == UP; }
	bool Press(DWORD key) { return keyMap[key] == PRESS; }

private:
	static Keyboard* instance;
	
	BYTE keyCurState[MAX_KEY];
	BYTE keyOldState[MAX_KEY];

	BYTE keyMap[MAX_KEY];
};


