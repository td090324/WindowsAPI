// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <string>
#include <vector>
#include <map>

#include <ctime>

using namespace std;

#define COLOR_BLACK RGB(  0,   0,   0)
#define COLOR_WHITE RGB(255, 255, 255)

#define COLOR_RED   RGB(255, 0,   0)
#define COLOR_GREEN RGB(0, 255,   0)
#define COLOR_BLUE  RGB(0,   0, 255)

#define COLOR_CYAN    RGB(0,  255, 255)
#define COLOR_MAGENTA RGB(255,  0, 255)
#define COLOR_YELLOW  RGB(255, 255,  0)


#define COLOR_GRAY  RGB(128,128,128)
#define COLOR_ORANGE  RGB(255,165,0)
#define COLOR_PINK  RGB(255,192,203)

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define WIN_CENTER Vector2(WIN_WIDTH * 0.5, WIN_HEIGHT * 0.5) 

#define PI 3.14159265



#include "Point.h"
#include "Vector2.h"
#include "Math.h"

using namespace Math;

#include "Rect.h"
#include "Circle.h"
#include "Line.h"

#include "Collision.h"

#include "Texture.h"
#include "Animation.h"

//Avoid
#include "Poo.h"
#include "AvoidPlayer.h"

//Fortress
#include "CannonBall.h"
#include "CannonBallManager.h"
#include "Tank.h"

//Arkanoid
#include "ArkaPlayer.h"
#include "Brick.h"
#include "BrickManager.h"
#include "Ball.h"

#include "Scene.h"
#include "TutorialScene.h"
#include "PaintScene.h"
#include "CollisionScene.h"
#include "AvoidGameScene.h"
#include "AngleScene.h"
#include "ArkanoidScene.h"
#include "ImageScene.h"
#include "AnimationScene.h"

#include "MainGame.h"

extern Vector2	 mousePos;	//다른 파일에서도 해당 전역 변수를 사용 가능하게끔.
extern HWND		 hWnd;
extern HDC		 backDC;
extern HINSTANCE hInst;