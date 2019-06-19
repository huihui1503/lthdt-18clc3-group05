#pragma once
#include<iostream>
#include<string>
#include"Dohoa.h"
#include <io.h>
#include <fcntl.h>
#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define DarkCyan		3
#define DarkRed		    4
#define DarkPink		5
#define DarkYellow	    6
#define DarkWhite		7
#define Gray			8
#define Blue			9
#define Green			10
#define Cyan			11
#define Red			    12
#define Pink			13
#define Yellow		    14
#define White			15
//////////
#define KEY_UP			72
#define KEY_DOWN		80
#define KEY_LEFT		75
#define KEY_RIGHT		77
#define KEY_ENTER		13
#define KEY_SPACE		32
#define KEY_ESC			27
#define KEY_BACKSPACE	8
#define KEY_TAB         9
#define KEY_CTRL            17
using namespace std;
class Menu
{
public:
	void About_Us();
	void Exit();
	string Enter(int x, int y);// dung de cin o mot toa do nao do
	void Draw_Login(int state);// ve table
	int Login();
	void Print_FlashScreen();
	void Start_System();
	Menu();
	~Menu();
};