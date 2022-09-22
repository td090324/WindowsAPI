#include "Framework.h"
#include "Keyboard.h"

Keyboard* Keyboard::instance = nullptr;

Keyboard::Keyboard()
{
	/*
	�迭 �ʱ�ȭ ���
	
	1. ���� ���� �� ={};
	2. ZeroMemory
	3. memset
	*/

	//memset(keyCurState, 0, sizeof(keyCurState));
	//memset�� �������� �Լ������� �ٸ����� 0���� �ʱ�ȭ�� �������ѳ��� �Լ�.
	//���� �߰��� �迭 �����͸� ������ ������ ���.
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
	//�迭�� �����ϴ� ������� memcpy
	//���� ������ ���¸� ��ü ���
	memcpy(keyOldState, keyCurState, sizeof(keyCurState));

	ZeroMemory(keyCurState, sizeof(keyCurState));
	ZeroMemory(keyMap, sizeof(keyMap));

	//��ȯ���� �� 4����
	// �Ƹ� �����Ӹ��� üũ�Ϸ��� ��ȯ���� ���� ���� �ƴұ���.
	//0 �Ǵ� 1 ��ȯ -     Ű���带 ������ ���� ����
	//128 �Ǵ� 129 ��ȯ - Ű���带 ���� ����
	GetKeyboardState(keyCurState);

	/*
	���� ������
	���ǽ� ? TRUE�϶� ��ȯ�� : FALSE�϶� ��ȯ��
	DOWN, UP / keyCurState ? "DOWN" : "UP
	*/

	for (UINT i = 0; i < MAX_KEY; i++)
	{
		//���°� 4���� ������ ���� 2������ �����ϴ� ���
		//0x80�� 0x81(129) �Ǵ� 1, 0�� &������-��Ʈ������ �ϸ�
		//0x80 �Ǵ� 0x00�� �ȴ�.
		BYTE key = keyCurState[i] & 0x80;

		//0�̳� 1�̸� 0���� ������ �迭�� 0���� �ٽ� ����
		//128, 129�� 128�� ������ 1�� �ٽ� ����.
		keyCurState[i] = key ? 1 : 0;

		BYTE old = keyOldState[i];
		BYTE cur = keyCurState[i];

		if (old == 0 && cur == 1)	//�������� false, ����� true : DOWN
			keyMap[i] = DOWN;
		else if (old == 1 && cur == 0) //�������� true, ����� flase : UP
			keyMap[i] = UP;
		else if (old == 1 && cur == 1) //�������� true, ���絵 true : PRESS
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
