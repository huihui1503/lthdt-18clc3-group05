#ifndef _Dohoa_
#define _Dohoa_
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
void resizeConsole(int width, int height); // Hàm tô màu.
void textcolor(int x);
void gotoxy(int x, int y);// Hàm xóa màn hình.
void XoaManHinh();
// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */
// Hàm tự viết
void ToMau(int x, int y, char *a, int color);// x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
#endif // !_Dohoa_

