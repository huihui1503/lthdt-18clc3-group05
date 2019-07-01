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

void Table_Expand(int m)
{
	m++;
	int k = 110;
	int n = 11 + 2 * m;

	textcolor(15);

	gotoxy(0, 0);
	putchar(218);
	for (int i = 1; i <= 80 + k; i++)
		putchar(196);
	putchar(191);
	printf("\n");

	//

	putchar(179);
	for (int i = 1; i <= 80 + k; i++)
		putchar(219);
	printf("%c\n", 179);
	//

	for (int i = 1; i <= m * 2 + 3; i++)
	{
		putchar(179);
		putchar(219);
		gotoxy(80 + k, 1 + i);
		printf("%c %c\n", 219, 179);
	}
	//21
	gotoxy(2, m * 2 + 4);

	for (int i = 1; i <= 79 + k; i++)
		putchar(219);
	printf("\n");

	putchar(192);
	for (int i = 1; i <= 80 + k; i++)
		putchar(196);
	putchar(217);

	// phan ben torng

	gotoxy(3, 3);
	putchar(218);
	for (int i = 1; i < 76 + k; i++)
		if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 ||i==120||i==135 || i == 150||i==165) putchar(194);
		else putchar(196);
		printf("%c\n", 191);
	for (int i = 13; i <= n; i += 2)
	{
		//_getch();
		gotoxy(3, i - 9);
		putchar(179);
			gotoxy(79 + k, i - 9);
		putchar(179);
		printf("\n");
		//
		gotoxy(13, i - 9);
		putchar(179);


		gotoxy(33, i - 9);
		putchar(179);

		gotoxy(48, i - 9);
		putchar(179);

		gotoxy(88, i - 9);	
		putchar(179);

		gotoxy(108, i - 9);
		putchar(179);

		gotoxy(123, i - 9);
		putchar(179);

		gotoxy(138, i - 9);
		putchar(179);
		gotoxy(153, i - 9);
		putchar(179);
		gotoxy(168, i - 9);
		putchar(179);



		gotoxy(3, i + 1 - 9);
		if (i == n) putchar(192);
		else putchar(195);
		if (i != n)
			for (int i = 1; i < 76 + k; i++)
				if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 || i == 120 || i == 135 || i == 150 || i == 165) putchar(197);
				else putchar(196);
		else
			for (int i = 1; i < 76 + k; i++)
				if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 || i == 120 || i == 135 || i == 150 || i == 165) putchar(193);
				else putchar(196);
		if (i == n) putchar(217); else putchar(180);

	}

	//information

	gotoxy(7, 4);
	cout << "STT";
	gotoxy(23, 4);
	cout << "ID";
	gotoxy(39, 4);
	cout << "BRAND";
	gotoxy(65, 4);
	cout << "NAME";
	gotoxy(96, 4);
	cout << "PRICE";
	gotoxy(113, 4);
	cout << "ORIGIN";
	gotoxy(129, 4);
	cout << "RAM";
	gotoxy(144, 4);
	cout << "ROM";	
	gotoxy(158, 4);
	cout << "BATTERY";
	gotoxy(177, 4);
	cout << "SCREEN";
}

void Table_Basic(int m) {
	m++;
	int k = 44;
	int n = 11 + 2 * m;

	textcolor(15);

	gotoxy(0, 0);
	putchar(218);
	for (int i = 1; i <= 80 + k; i++)
		putchar(196);
	putchar(191);
	printf("\n");

	//

	putchar(179);
	for (int i = 1; i <= 80 + k; i++)
		putchar(219);
	printf("%c\n", 179);
	//

	for (int i = 1; i <= m * 2 + 3; i++)
	{
		putchar(179);
		putchar(219);
		gotoxy(80 + k, 1 + i);
		printf("%c %c\n", 219, 179);
	}
	//21
	gotoxy(2, m * 2 + 4);

	for (int i = 1; i <= 79 + k; i++)
		putchar(219);
	printf("\n");

	putchar(192);
	for (int i = 1; i <= 80 + k; i++)
		putchar(196);
	putchar(217);

	// phan ben torng

	gotoxy(3, 3);
	putchar(218);
	for (int i = 1; i < 76 + k; i++)
		if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 || i == 120 ) putchar(194);
		else putchar(196);
	printf("%c\n", 191);
	for (int i = 13; i <= n; i += 2)
	{
		//_getch();
		gotoxy(3, i - 9);
		putchar(179);
		gotoxy(79 + k, i - 9);
		putchar(179);
		printf("\n");
		//
		gotoxy(13, i - 9);
		putchar(179);


		gotoxy(33, i - 9);
		putchar(179);

		gotoxy(48, i - 9);
		putchar(179);

		gotoxy(88, i - 9);
		putchar(179);

		gotoxy(108, i - 9);
		putchar(179);

		gotoxy(123, i - 9);
		putchar(179);
		gotoxy(3, i + 1 - 9);
		if (i == n) putchar(192);
		else putchar(195);
		if (i != n)
			for (int i = 1; i < 76 + k; i++)
				if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 || i == 120 ) putchar(197);
				else putchar(196);
		else
			for (int i = 1; i < 76 + k; i++)
				if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 || i == 120) putchar(193);
				else putchar(196);
		if (i == n) putchar(217); else putchar(180);

	}

	//information

	gotoxy(7, 4);
	cout << "STT";
	gotoxy(23, 4);
	cout << "ID";
	gotoxy(39, 4);
	cout << "BRAND";
	gotoxy(65, 4);
	cout << "NAME";
	gotoxy(96, 4);
	cout << "PRICE";
	gotoxy(113, 4);
	cout << "ORIGIN";

}

void Table_Calc_Cost(int m) {
	m+=2;
	int k = 110;
	int n = 11 + 2 * m;

	textcolor(15);

	gotoxy(0, 0);
	putchar(218);
	for (int i = 1; i <= 80 + k; i++)
		putchar(196);
	putchar(191);
	printf("\n");

	//

	putchar(179);
	for (int i = 1; i <= 80 + k; i++)
		putchar(219);
	printf("%c\n", 179);
	//

	for (int i = 1; i <= m * 2 + 3; i++)
	{
		putchar(179);
		putchar(219);
		gotoxy(80 + k, 1 + i);
		printf("%c %c\n", 219, 179);
	}
	//21
	gotoxy(2, m * 2 + 4);

	for (int i = 1; i <= 79 + k; i++)
		putchar(219);
	printf("\n");

	putchar(192);
	for (int i = 1; i <= 80 + k; i++)
		putchar(196);
	putchar(217);

	// phan ben torng

	gotoxy(3, 3);
	putchar(218);
	for (int i = 1; i < 76 + k; i++)
		if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 || i == 120 || i == 135 || i == 150) putchar(194);
		else putchar(196);
	printf("%c\n", 191);
	int tmp = n;
	n -= 1;
	for (int i = 13; i <= n; i += 2)
	{
		//_getch();
	
			gotoxy(3, i - 9);
			putchar(179);
			gotoxy(79 + k, i - 9);
			putchar(179);
			printf("\n");
			//
			gotoxy(13, i - 9);
			putchar(179);


			gotoxy(33, i - 9);
			putchar(179);

			gotoxy(48, i - 9);
			putchar(179);

			gotoxy(88, i - 9);
			putchar(179);

			gotoxy(108, i - 9);
			putchar(179);

			gotoxy(123, i - 9);
			putchar(179);
			gotoxy(138, i - 9);
			putchar(179);
			gotoxy(153, i - 9);
			putchar(179);
			if (i == n - 1) {
				gotoxy(3, i + 1 - 9);
				putchar(195);
				for (int i = 1; i < 76 + k; i++)
					if (i == 30 || i == 135 || i == 150) putchar(197);
					else if (i == 10 || i == 45 || i == 85 || i == 105||i==120)
						putchar(193);
				else putchar(196);
				putchar(180);
				i+=2;
				gotoxy(3, i - 9);
				putchar(179);
				gotoxy(79 + k, i - 9);
				putchar(179);
				printf("\n");
				//
				gotoxy(33, i - 9);
				putchar(179);
				gotoxy(138, i - 9);
				putchar(179);
				gotoxy(153, i - 9);
				putchar(179);

				gotoxy(3, i - 8);
				putchar(192);
				for (int i = 1; i < 76 + k; i++)
					if (i == 30 || i == 135 || i == 150) putchar(193);
					else putchar(196);
				putchar(217);
				break;
			}
		gotoxy(3, i + 1 - 9);
		if (i == n) putchar(192);
		else putchar(195);
			if (i != n)
			for (int i = 1; i < 76 + k; i++)
				if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 || i == 120 || i == 135 || i == 150 ) putchar(197);
				else putchar(196);
		else
			for (int i = 1; i < 76 + k; i++)
				if (i == 10 || i == 30 || i == 45 || i == 85 || i == 105 || i == 120 || i == 135 || i == 150 ) putchar(193);
				else putchar(196);
		if (i == n) putchar(217); else putchar(180);

	}

	//information

	gotoxy(7, 4);
	cout << "STT";
	gotoxy(23, 4);
	cout << "ID";
	gotoxy(39, 4);
	cout << "BRAND";
	gotoxy(65, 4);
	cout << "NAME";
	gotoxy(96, 4);
	cout << "PRICE";
	gotoxy(113, 4);
	cout << "ORIGIN";
	gotoxy(127, 4);
	cout << "RAM/ROM";
	gotoxy(140, 4);
	cout << "STOCKLEVELS";
	gotoxy(170, 4);
	cout << "COST";
	gotoxy(15, n - 8);
	cout << "TOTAL :";
}