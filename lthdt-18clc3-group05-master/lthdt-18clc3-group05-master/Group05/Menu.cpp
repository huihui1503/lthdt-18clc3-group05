#include "Menu.h"
#define POSX 35
#define POSY 3
// LOGIN Function
string Menu::Enter(int x, int y)
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
			else if (key != char(KEY_UP) && key != char(KEY_DOWN) && key != char(KEY_LEFT) && key != char(KEY_RIGHT) && key != char(KEY_TAB) && key != char(KEY_CTRL))
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

void Menu::Draw_Login(int state)
{
	textcolor(Cyan);
	//////////////////////////////////Draw table//////////////////////////////////
	gotoxy(POSX, POSY);
	for (int i = 0; i <= 50; i++)
	{
		if (i == 0) cout << char(218);
		else if (i == 50) cout << char(191);
		else cout << char(196);
	}
	for (int i = 0; i < 20; i++)
	{
		gotoxy(POSX, POSY + 1 + i);
		if (i == 3) {
			cout << char(192);
			for (int i = 1; i < 50; i++) cout << char(196);
		}
		else if (i == 4) {
			cout << char(218);
			for (int i = 1; i < 50; i++) cout << char(196);
		}
		else cout << char(179);
	}
	gotoxy(POSX, POSY + 20);
	for (int i = 0; i <= 50; i++)
	{
		if (i == 0) cout << char(192);
		else if (i == 50) cout << char(217);
		else cout << char(196);
	}
	for (int i = 0; i < 19; i++)
	{
		gotoxy(POSX + 50, POSY + 1 + i);
		if (i == 3) cout << char(217);
		else if (i == 4) cout << char(191);
		else cout << char(179);
	}
	///////////////  User Name  ////////////////
	gotoxy(POSX + 5, POSY + 8);
	for (int i = 0; i <= 40; i++)
	{
		if (i == 0) cout << char(218);
		else if (i == 40) cout << char(191);
		else cout << char(196);
	}
	gotoxy(POSX + 5, POSY + 9); cout << char(179);
	gotoxy(POSX + 45, POSY + 9); cout << char(179);
	gotoxy(POSX + 5, POSY + 10);
	for (int i = 0; i <= 40; i++)
	{
		if (i == 0) cout << char(192);
		else if (i == 40) cout << char(217);
		else cout << char(196);
	}
	///////////////  Password  ////////////////
	gotoxy(POSX + 5, POSY + 11);
	for (int i = 0; i <= 40; i++)
	{
		if (i == 0) cout << char(218);
		else if (i == 40) cout << char(191);
		else cout << char(196);
	}
	gotoxy(POSX + 5, POSY + 12); cout << char(179);
	gotoxy(POSX + 45, POSY + 12); cout << char(179);
	gotoxy(POSX + 5, POSY + 13);
	for (int i = 0; i <= 40; i++)
	{
		if (i == 0) cout << char(192);
		else if (i == 40) cout << char(217);
		else cout << char(196);
	}
	//////////////////////////////////Draw text/////////////////////////////////////////
	gotoxy(POSX + 9, POSY + 2);
	textcolor(9);
	cout << "Commercial Management System";
	gotoxy(POSX + 7, POSY + 7);
	textcolor(13);
	cout << "Sign in";
	textcolor(Gray);
	gotoxy(POSX + 8, POSY + 15);
	cout << "* To continue: Press Enter";
	gotoxy(POSX + 8, POSY + 16);
	cout << "* Note: Do not include space";
	gotoxy(POSX + 8, POSY + 17);
	cout << "[!] Go back to menu: Press 'ESC'";
	textcolor(7);
	if (state == 0)
	{
		gotoxy(POSX + 7, POSY + 12);
		cout << "Enter password      ";
		gotoxy(POSX + 7, POSY + 9);
		cout << "Enter username or ID     ";
	}
	else if (state == 1)
	{
		gotoxy(POSX + 7, POSY + 12);
		cout << "Enter password     ";
	}

}

int Menu :: Login()
{
Done:
	string place;// for username
	char place1[100];// for password
	char key;
	Draw_Login(0);//0: screen default
	place = Enter(POSX + 7, POSY + 9);
	if (place == "") system("cls");
	if (place == "") return -1;
	int count = 0;//Count show password, 0:hidden, 1:show
	int i = 0;
	gotoxy(POSX + 7, POSY + 12); cout << "                      ";
	gotoxy(POSX + 7, POSY + 12);
	int count1 = 1;
	while (true)
	{
		key = _getch();
		if (key != NULL)
		{
			if (key == char(27))
			{
				system("cls");
				return -1;
			}
/////////////////////////////// Delete ///////////////////////////////
		else if (key == char(8))
			{
				int check = i - 1;
				if (check >= -1)
				{
					place1[i] = '\0';
					gotoxy(POSX + 7 + i, POSY + 12);
					cout << " ";
					gotoxy(POSX + 7 + i, POSY + 12);
					i--;
				}
			}
////////////////////////// Enter Password ///////////////////////////////
			else if (key == char(13))
			{
				place1[i + 1] = '\0';
				break;
			}
			else if (key == char(32))
			{
				gotoxy(POSX + 7, POSY + 12);
				if (count == 0) count = 1;
				else count = 0;
				if (count == 0)
				{
					for (int z = 0; z <= i; z++) cout << "*";
				}
				else
				{
					for (int z = 0; z <= i; z++) cout << place1[z];
				}
			}
			else if ((key >= char(48) && key <= char(57)) || (key >= char(97) && key <= char(122)))
			{
				int check = i + 1;
				if (check <= 30)
				{
					if (count == 0) cout << "*";
					else if (count == 1) cout << key;
					if (count1 == 1 && i == 0) count1++;
					else i += 1;
					place1[i] = key;
				}
			}
		}
	}
	string pass = string(place1);
	if (place == "master" && pass == "master") return 1;
	if (place == "seller" && pass == "seller") return 2;
	else
	{
		system("cls");
		textcolor(9);
		gotoxy(POSX + 6, POSY - 1);
		textcolor(12);
		cout << "Username or password is not correct!!!";
		goto Done;
	}
}

// MOVE Function

void Menu::Print_FlashScreen()
{
Done:
	system("cls");
	_setmode(_fileno(stdout), _O_TEXT);
	textcolor(Cyan);
	gotoxy(13, 4); cout << "____ ____ _  _ _  _ ____ ____ ____ _ ____ _       _  _ ____ _  _ ____ ____ ____ _  _ ____ _  _ ___";
	gotoxy(13, 5); cout << "|    |  | |\\/| |\\/| |___ |__/ |    | |__| |       |\\/| |__| |\\ | |__| | __ |___ |\\/| |___ |\\ |  |";
	gotoxy(13, 6); cout << "|___ |__| |  | |  | |___ |  \\ |___ | |  | |___    |  | |  | | \\| |  | |__] |___ |  | |___ | \\|  |";
	string array[3] = { "Login", "About us","Exit" };
	char key='.';
	int choice = 0;
	int line = 12, col = 55;//vi tri
	textcolor(White);
	for (int i = 0; i < 3; i++)
	{
		gotoxy(col, line + i); cout << array[i];
	}
	int choice_num = 2;
	while (1)
	{
		textcolor(Red);
		gotoxy(col, line + choice); cout << array[choice];
		key = _getch();
		switch (int(key))
		{
		case 72:
			textcolor(White);
			gotoxy(col, line + choice); cout << array[choice];
			choice--;
			if (choice < 0) choice = choice_num;
			break;
		case 80:
			textcolor(White);
			gotoxy(col, line + choice); cout << array[choice];
			choice++;
			if (choice > choice_num) choice = 0;
			break;
		case 13: 
			int check = 0;
			switch (choice)
			{
			case 0:
				system("cls");
				check = Login();
				if (check == 1) Master_Move();
				else if (check == 2) Seller_Move();
				goto Done;
				break;
			case 1:
				About_Us();
				goto Done;
				break;
			case 2: 
				Exit();
				return;
			}
			break;
		}
	}
}

// Seller Function
 
void Menu::Seller_Move()
{
	system("cls");
	textcolor(White);
	for (int i = 0; i <= 40; i++)
	{
		gotoxy(80, 1 + i);
		cout << "|$|";
	}
	int move = main_data.Draw_Brand_For_Choice();
	textcolor(Red);
	gotoxy(35, 2); cout << "All PRODUCTS";
	gotoxy(97, 2); cout << "Your bag";
	char key = '.';
	int max_col = move % 3;
	int max_row = move / 3;
	if (max_col != 0) max_row += 1;
	else max_col = 3;
	int x = 1;
	int y = 1;
	while (key != char(KEY_ESC))
	{
		Draw_Box(x * 25 - 17, y * 10 - 5, 5, 15, Cyan);
		key = _getch();
		switch (int(key))
		{
		case KEY_LEFT:
			Draw_Box(x * 25 - 17, y * 10 - 5, 5, 15, White);
			x -= 1;
			if (y != max_row)
			{
				if (x <= 0) x = 3;
			}
			else
			{
				if (x <= 0) x = max_col;
			}
			break;
		case KEY_RIGHT:
			Draw_Box(x * 25 - 17, y * 10 - 5, 5, 15, White);
			x += 1;
			if (y != max_row)
			{
				if (x > 3) x = 1;
			}
			else
			{
				if (x > max_col) x = 1;
			}
			break;
		case KEY_UP:
			Draw_Box(x * 25 - 17, y * 10 - 5, 5, 15, White);
			y -= 1;
			if (y <= 0)
			{
				y = max_row;
				if (x > max_row) x = max_row;
			}
			break;
		case KEY_DOWN:
			Draw_Box(x * 25 - 17, y * 10 - 5, 5, 15, White);
			y += 1;
			if (y > max_row) y = 1;
			if (y == max_row)
			{
				if (x > max_col) x = max_col;
			}
			break;
		case KEY_ENTER:
			int current = (y - 1) * 3 + x;
			Delete_On_Console(8, 5, 75, 5 + max_row * 10);
			//Move to other screen
			system("pause>nul");
			break;
		}
	}
}

// Other function

void Menu::Start_System()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int y = 3;
	int x = 28;
	y = 6;
	x = 35;
	textcolor(Blue);
	gotoxy(x, y);    wcout << L"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█";
	for (int i = 1; i <= 17; i++)
	{
		gotoxy(x, y + i); wcout << L"█                                                █";
	}
	gotoxy(x, y + 18);    wcout << L"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█";
	Sleep(800);
	y = 9;
	x = 42;
	textcolor(DarkCyan);
	gotoxy(x, y);    wcout << L"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█";
	for (int i = 1; i <= 11; i++)
	{
		gotoxy(x, y + i); wcout << L"█                                  █";
	}
	gotoxy(x, y + 12);    wcout << L"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█";
	Sleep(800);
	textcolor(Cyan);
	x = 49;
	y = 12;
	gotoxy(x, y);    wcout << L"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█";
	gotoxy(x, y + 1); wcout << L"█░░                ░░█";
	gotoxy(x, y + 2);  wcout << L"█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█";
	gotoxy(x, y + 3);  wcout << L"█░░║║║╠─║─║─║║║║║╠─░░█";
	gotoxy(x, y + 4);  wcout << L"█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█";
	gotoxy(x, y + 5); wcout << L"█░░                ░░█";
	gotoxy(x, y + 6);  wcout << L"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█";
	Sleep(1000);
}

void Menu::About_Us()
{
	system("cls");
	cout << "Group 5:" << endl;
	cout << "Thai Hoang Huy"<<endl;
	cout << "Tran Dinh Huy" << endl;
	cout << "Tran Xuan Loc" << endl;
	system("pause>nul");
}
 
void Menu::Exit()
{
	system("cls");
	gotoxy(55, 15);
	cout << "GOODBYE!!!";
	Sleep(500);
	gotoxy(50, 15);
	cout << "See you later!!!";
	Sleep(500);
}

Menu::Menu()
{
	//main_data.Load_Data_from_file("data.txt");

}


Menu::~Menu()
{

}

bool checkIfUnique(vector<string> unique, string input) {
	if (unique.size() == 0) return true;
	for (size_t i = 0; i < unique.size(); i++) {
		if (input.compare(unique[i]) == 0) return false;
	}
	return true;
} // this will check the logo if it existed or not 

void Menu::Master_Move() { // call when login returned 1
	vector<string> uniqueName; // argument to get unique logo for example "Samsung" "Iphone" "Xiaomi" "Asus"
	for (int i = 0; i < main_data.getNum(); i++) {
	//	if (checkIfUnique(uniqueName, main_data[i].Brand))
		//	uniqueName.push_back(main_data[i].Brand);
	}
	//end of unique
	system("cls");
	//go for interface
	int x = 10, y = 5;
	int count = 1; // if count = 3 endline and draw another box
	for (size_t i = 0; i < uniqueName.size(); i++) {
		Draw_Box(x, y, 3, 12, Yellow);
		gotoxy(x + 2, y + 2);
		cout << uniqueName[i];
		if (count == 3) {
			y += 8;
			x = 10;
			count = 0;
		}
		else {
			x += 20;
			y = 5;
		}
		count++;
	}
	y += 8;
	Draw_Box(x, y, 3, 12, Yellow);
	gotoxy(x + 2, y + 2);
	cout << "  New"; // the new box
	x = 70;
	y = 5;
	for (size_t i = 0; i <= uniqueName.size() / 3; i++) {
		for (int j = 0; j < 8; j++) {
			gotoxy(x, y + j);
			cout << "|";
		}
	} // drawn line prase between help and menu 
	//menu list

	x = 75;
	y = 6;

	textcolor(Gray);
	gotoxy(x, y);
	cout << "#use keyboard to move ";
	gotoxy(x, y + 1);
	cout << "#Press ESC to exit ";

	x = 10;
	y = 5;
	Draw_Box(x, y, 3, 12, Cyan);
	
	gotoxy(x, y);

	int choice = 0; // choice implement another interface

	int Xmax = 10 + (uniqueName.size() % 3) * 20;
	int Ymax = 5 + (uniqueName.size() / 3) * 8;
	while (1) {
		char c = _getch();
		if (int(c) == 72) { // up
			int xa = x, ya = y;
			if (y <= 5) {
				y += (uniqueName.size() / 3) * 8;
				choice += 3 * (uniqueName.size() / 3);
			}
			else {
				y -= 8;
				choice -= 3;
			}
			if (x > Xmax && y == Ymax) {
				y -= 8;
				choice -= 3;
			}
			Draw_Box(xa, ya, 3, 12, Yellow);
			Draw_Box(x, y, 3, 12, Cyan);
			gotoxy(x, y);
		}
		if (int(c) == 77) { // right
			int xa = x, ya = y;
			if (x >= 50) {
				x = 10;
				choice-= 2;
			}
			else {
				x += 20;
				choice += 1;
			}
			if (x > Xmax && y == Ymax) {
				x = 10;
				choice -= (uniqueName.size() % 3 + 1);
			}
			Draw_Box(xa, ya, 3, 12, Yellow);
			Draw_Box(x, y, 3, 12, Cyan);
			gotoxy(x, y);
		}
		if (int(c) == 80) { // down
			int xa = x, ya = y;
			if (y >= 5 + ((uniqueName.size() / 3) * 8)) {
				y = 5;
				choice -= 3 * (uniqueName.size() / 3);
			}
			else {
				y += 8;
				choice += 3;
			}
			if (x > Xmax && y == Ymax) {
				y = 5;
				choice -= 3 * (uniqueName.size() / 3);
			}
			Draw_Box(xa, ya, 3, 12, Yellow);
			Draw_Box(x, y, 3, 12, Cyan);
			gotoxy(x, y);
		}
		if (int(c) == 75) { // left
			int xa = x, ya = y;
			if (x == 10) {
				x += 2 * 20;
				choice += 2;
			}
			else {
				x -= 20;
				choice -= 1;
			}
			if (x > Xmax && y == Ymax) {
				x = Xmax;
				choice = uniqueName.size();
			}
			Draw_Box(xa, ya, 3, 12, Yellow);
			Draw_Box(x, y, 3, 12, Cyan);
			gotoxy(x, y);
		}
		if (int(c) == 27) { // esc
			choice = -1;
			break;
		}
		if (int(c) == 13) { // enter 
			cout << choice << endl; // try choice 
		}
	}
}

void Menu::add_Edit(string Brand)
{

}
