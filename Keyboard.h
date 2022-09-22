#pragma once

#define MAX_KEY 256

enum KeyState
{
	NONE,
	DOWN,	//���� ���� 1��
	UP,
	PRESS	//������ ������ ���
};

class Keyboard
{
private:
	Keyboard();
	~Keyboard();

public:
	static Keyboard* Get();		//��ȯ

	static void Delete();		//����

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


