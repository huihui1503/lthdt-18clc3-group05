#ifndef _Dohoa_
#define _Dohoa_
#include <iostream>
#include<vector>
#include"Smartphone.h"
#include <conio.h>
#include <Windows.h>
#include<string>
#include <io.h>
#include <fcntl.h>
using namespace std;
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
#define KEY_ADD			43
#define KEY_MINUS		45
void resizeConsole(int width, int height); // Hàm tô màu.
void textcolor(int x);
void gotoxy(int x, int y);// Hàm xóa màn hình.
void XoaManHinh();
void Draw_Box(int x, int y, int size_l, int size_w, int color);
void Delete_On_Console(int start_x, int start_y, int end_x, int end_y);// Triangle Delete
// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */
// Hàm tự viết
void ToMau(int x, int y, char *a, int color);// x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
void Table_Expand(int m);// Testing Function dont use if dont know
void Table_Basic(int m);
void Table_Calc_Cost(int m);
void Table_Draw_Chart(vector<double> months, int year);
void Draw_an_columm(int x, int y, int height, int data);
#endif // !_Dohoa_

void Delete_On_Console(int start_x, int start_y, int end_x, int end_y);
