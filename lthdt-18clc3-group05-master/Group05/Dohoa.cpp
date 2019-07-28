#include"Dohoa.h"

string Enter(int x, int y)
{
	char place[40];// for old password
	char key;
	int i = 0;
	key = _getch();
	if (key == char(27))
	{
		return "";
	}
	if (key != NULL && key != char(13) && key != char(32))
	{
		gotoxy(x, y);
		cout << "                      ";
		place[i] = key;
		gotoxy(x, y);
		cout << key;
	}
	while (true)
	{
		key = _getch();
		if (key != NULL)
		{
			if (key == char(27))
			{
				return "";
			}
			/////////////////////////////// Delete ///////////////////////////////
			else if (key == char(8))
			{
				int check = i - 1;
				if (check >= -1)
				{
					place[i] = '\0';
					gotoxy(x + i, y);
					cout << " ";
					gotoxy(x + i, y);
					i--;
				}
			}
			else if (key == char(13))
			{
				place[i + 1] = '\0';
				break;
			}
			else
			{
				int check = i + 1;
				if (check <= 30)
				{
					if (check <= 30)
					{
						cout << key;
						i += 1;
						place[i] = key;
					}
				}
			}
		}
	}
	return place;
}

void Delete_On_Console(int start_x, int start_y, int end_x, int end_y)
{
	int height = end_y - start_y;
	int weight = end_x-start_x;
	string temp = "";
	for (int i = 1; i <= weight; i++) temp += " ";
	for (int i = 0; i <= height; i++)
	{
		gotoxy(start_x, start_y + i);
		cout << temp;
	}
}

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
void Draw_an_columm(int x, int y, int height, int data) {
	int i = 0;
	for (; i < height; i++)
	{
		gotoxy(x, y - i+1);
		textcolor(9);// BLUE
		for(int i=0;i<8;i++)
		putchar(219);
	}
	gotoxy(x, y - i);
	textcolor(Yellow);
	cout << data;
	textcolor(White);

}
void Table_Draw_Chart(vector<double> months, int year, int z) {
	int m =17;
	int k = 110;
	int n = 11 + 2 * m;
	int distance = (60 + k) / 12;
	textcolor(15);
	gotoxy(0, 0);
	putchar(218);
	for (int i = 1; i <= 95 + k; i++)
		putchar(196);
	putchar(191);
	printf("\n");

	putchar(179);
	for (int i = 1; i <= 95 + k; i++)
		putchar(219);
	printf("%c\n", 179);
	//

	for (int i = 1; i <= m * 2 + 3; i++)
	{
		putchar(179);
		putchar(219);
		gotoxy(95 + k, 1 + i);
		printf("%c %c\n", 219, 179);
	}
	//21
	gotoxy(2, m * 2 + 4);

	for (int i = 1; i <= 94 + k; i++)
		putchar(219);
	printf("\n");

	putchar(192);
	for (int i = 1; i <= 95 + k; i++)
		putchar(196);
	putchar(217);
	// phan bên trong
	// toạ độ điểm O
	int posX = 20;
	int posY = (m * 2 + 3) - 2;

	gotoxy(posX, posY);
	cout << "O";
	//trục dọc
	for (int i = 0; i < (m * 2 + 3) -7; i++) {
		gotoxy(posX, 4 + i);
		putchar(179);
	}
	//trục ngang
	for (int i = 0; i < 68 + k; i++) {
		gotoxy(posX + i, (m * 2 + 3) - 3);
		putchar(196);
	}
	gotoxy(posX, (m * 2 + 3) - 3);	
	putchar(192);
	//đơn vị trục tung
	gotoxy(10, 3);
	cout << "(VND)";
	gotoxy(20, 3);
	putchar(94);
	//đơn vị trục hoành
	gotoxy(85 + k, (m * 2 + 3) - 2);
	cout << "(Months)";
	gotoxy(88 + k, (m * 2 + 3) - 3);
	cout << ">";


	//thong so truc hoanh
	vector<string> Months = { "January","February","March", "April","May","June","July","August","September","October","November", "December" };
	// test key
	vector<double> Data = months;
	//find max value and index of one
	int max = Data[0];
	int i = 1;
	for(;i< Data.size();i++)
	{  
		if (max < Data[i])
		{
			max = Data[i];
		}
	}
	// khoảng cách mặc định trên trục tung
	int default_distance = m * 2 - 5;
	//tính độ cao của từng số trong data và quy ra độ cao với max là giá trị lớn nhất
	vector<int> Height;
	int h = 0;
	for (int i = 0; i < Data.size(); i++)
	{
		h = 1.0 * (Data[i] * default_distance) / max;
		Height.push_back(h);
	}
	//vẽ thông số trục hoành (tháng)
	for (int i = 1; i <= 12; i++) {
		// vẽ từng tháng
		gotoxy(posX + distance * (i)-5, posY);
		cout << Months[i - 1];
		// vẽ từng cột và ghi dữ liệu lên đầu cột đó
		Draw_an_columm(posX + distance * (i)-6, posY - 3, Height[i - 1], Data[i - 1]);
		// vẽ độ chia trên trục tung
		gotoxy(posX, posY - Height[i - 1]-1);
		putchar(197);
		gotoxy(5, posY - 1 - Height[i - 1]);
		printf("%10.f", Data[i - 1]);
	}
	// vẽ độ chia trên trục tung
	double tmp = 0;
	for (int i = 0; i < 12; i++)
		tmp += months[i];
	if (z == 1)
		Profit_and_total(k, m, tmp, year);
	else Stock_and_total(k, m, tmp, year);

	system("pause");
}
void DisplayLogo(int x, int y, const char * file_name, int color, int time_appear)
{
	system("cls");
	ifstream fin(file_name);
	if (!fin.is_open()) {
		gotoxy(x, y);
		cout << "Logo isn't available" << endl;
		Sleep(time_appear);
		system("cls");
		return;
	}
	string logo;
	char tmp[3000];
	fin.get(tmp, 3000, 'eof');
	logo = (string)tmp;
	int i = 0;
	textcolor(color);
	gotoxy(x, y);
	y++;
	while (logo[i] != '\0') {
		if (logo[i] == '\n') {
			cout << logo[i];
			gotoxy(x, y);
			y++;
		}
		else {
			cout << logo[i];
		}
		i++;
	}
	Sleep(time_appear);
	system("cls");
	return;
}

void Profit_and_total(int k, int m, int tmp, int year)
{
	gotoxy(k - 15, (m * 2 + 3) + 4);
	cout << "ACCELERATING GROWTH IN " << year << endl;
	gotoxy(10, (m * 2 + 3) + 6);
	cout << "TOTAL PROFIT IN YEAR " << year << ": ";
	printf("%10.f\n", double(tmp));

}

void Stock_and_total(int k, int m, int tmp, int year)
{
	gotoxy(k - 15, (m * 2 + 3) + 4);
	cout << "ACCELERATING GROWTH IN " << year << endl;
	gotoxy(10, (m * 2 + 3) + 6);
	cout << "TOTAL STOCK IN YEAR " << year << ": ";
	printf("%10d\n", tmp);
}

