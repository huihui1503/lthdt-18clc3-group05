#include"Dohoa.h"

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */

// Hàm tự viết
void ToMau(int x, int y, char *a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

void Draw_Box(int x, int y, int size_l, int size_w, int color)
{
	textcolor(color);
	gotoxy(x, y);
	for (int i = 1; i <= size_w; i++)
	{
		if (i == 1) cout << char(218);
		else if (i == size_w) cout << char(191);
		else cout << char(196);
	}
	for (int i = 1; i <= size_l; i++)
	{
		gotoxy(x, y + i); cout << char(179);
		gotoxy(x + size_w - 1, y + i); cout << char(179);
	}
	gotoxy(x, y + size_l + 1);
	for (int i = 1; i <= size_w; i++)
	{
		if (i == 1) cout << char(192);
		else if (i == size_w) cout << char(217);
		else cout << char(196);
	}

}
void Delete_On_Console(int start_x, int start_y, int end_x, int end_y)
{
	int height = end_y - start_y;
	int weight = end_x - start_x;
	string temp = "";
	for (int i = 1; i <= weight; i++) temp += " ";
	for (int i = 0; i <= height; i++)
	{
		gotoxy(start_x, start_y + i);
		cout << temp;
	}
}