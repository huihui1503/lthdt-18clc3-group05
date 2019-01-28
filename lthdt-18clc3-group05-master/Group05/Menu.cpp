#include "Menu.h"
#define POSX 35
#define POSY 3
// LOGIN Function

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
	int x = 1;
	int y = 1;
Done:
	int move = main_data.Draw_Brand_For_Choice();
	move += 3;// for advance filter and customer
	int max_col = move % 3;
	int max_row = move / 3;
	if (max_col != 0) max_row += 1;
	else max_col = 3;
	textcolor(White);
	for (int i = 0; i <= 40; i++)
	{
		gotoxy(80, 1 + i);
		cout << "|$|";
	}
	textcolor(Red);
	gotoxy(35, 2); cout << "All PRODUCTS";
	gotoxy(97, 2); cout << "Your bag";
	char key = '.';
	while (key != char(KEY_ESC))
	{
		Draw_Box(x * 25 -17,y * 10 -5, 5, 15, Cyan);
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
				if (x > max_col) x = max_col;
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
			int current = (y - 1) * 3 + (x-1);
			Delete_On_Console(8, 5, 75, 5 + max_row * 10);
			if (current == move-2)
			{
				Move_in_Customer();
				system("cls");
				main_data.Draw_Bag();
			}
			else if(current==move-3)
			{
				Advanced_Filter();
				system("cls");
				main_data.Draw_Bag();
			}
			else if (current == move - 1) {
				system("cls");
				find_BaseOn_ID_or_Name();
			}
			else Choice_For_Sell(main_data.Count_Brand[current]);
			Delete_On_Console(1, 5, 80, 5 + max_row * 10);
			goto Done;
			break;
		}
	}
	main_data.Reset_Bags();
}

void Menu::Advanced_Filter()
{
Done:
	system("cls");
	// Draw effect
	int xBox = 40, yBox = 5;
	Draw_Box(37, 4, 25, 43, 25);// big box
	for (int i = 0; i <= 4; i++)
	{
		Draw_Box(xBox, 7 + i * 5, 1, 37, White);
	}
	int x = 42;
	textcolor(Cyan);
	gotoxy(x, 6); cout << "Brand";
	gotoxy(x, 11); cout << "Price";
	gotoxy(x, 16); cout << "Ram";
	gotoxy(x, 21); cout << "Rom";
	gotoxy(x, 26); cout << "Battery";
	textcolor(White);
	for (int i = 0; i <= 4; i++)
	{
		gotoxy(x + 1, 8 + 5 * i); cout << "None";
	}
	textcolor(Red);
	gotoxy(51, 2); cout << "Advanced Filter";
	Draw_Box(4, 12, 7, 31, White);
	textcolor(Red); gotoxy(6, 13); cout << "* Notes:";
	textcolor(White); gotoxy(6, 15); cout << "[i]: Press Shift + F to find";
	gotoxy(6, 17); cout << "[i]: Esc to exit";
	// Operate
	string content = "";
	int value = 0;//postion of option in array
	int array[5];//options
	for (int i = 0; i < 5; i++) array[i] = 0;
	int current = 0;// current position
	for (int i = 0; i < 5; i++) array[i] = 0;
	char key='.';
	while (int(key) != KEY_ESC)
	{
		Draw_Box(xBox, 7 + current * 5, 1, 37, Pink); textcolor(White); gotoxy(xBox + 33, 8 + current * 5); cout << "=>";
		key = _getch();
		switch (int(key))
		{
		case KEY_RIGHT:
			if (current != 4 && current != 3) content=Show_Option_In_Filter(7 + current * 5, current, value);
			else if (current == 4) content = Show_Option_In_Filter(7 + current * 5 - 6, current, value);
			else if (current == 3) content = Show_Option_In_Filter(7 + current * 5 - 8, current, value);
			if (value == -1) return;
			array[current] = value;
			gotoxy(x + 1, 8 + 5 * current); cout << "                                  ";
			textcolor(White);
			gotoxy(x + 1, 8 + 5 * current); cout << content;
			Delete_On_Console(82, 5, 110, 30);
			break;
		case KEY_UP:
			Draw_Box(xBox, 7 + current * 5, 1, 37, White); gotoxy(xBox + 33, 8 + current * 5); cout << "  ";
			current -= 1;
			if (current < 0) current = 4;
			break;
		case KEY_DOWN:
			Draw_Box(xBox, 7 + current * 5, 1, 37, White);gotoxy(xBox + 33, 8 + current * 5); cout << "  ";
			current += 1;
			if (current > 4) current = 0;
			break;
		case  70:
			Show_Result_Filter(array);
			goto Done;
			break;
		}
	}
}

void Menu::Show_Result_Filter(int array[])
{
	system("cls");
	vector<Smartphone> temp;
	if (main_data.Find_Smartphone_Filter(temp, array))
	{
		cout << "Not founded";
		system("pause>nul");
		return;
	}
	main_data.Draw_Bag();
	textcolor(Red);
	gotoxy(33, 2); cout << "FOUNDED PRODUCTS";
	for(int i=0;i<temp.size();i++) temp[i].COUT_NAME(i * 5 + 5, 1, 80, White);
	char key = '.';
	int current = 0;
	while (key != char(KEY_ESC))
	{
		main_data.Effect_of_Move(current, temp);
		key = _getch();
		if (int(key) == KEY_UP)
		{
			Delete_On_Console(1, current * 5 + 5, 80, current * 5 + 7);
			temp[current].COUT_NAME(current * 5 + 5, 1, 80, White);
			current -= 1;
			if (current < 0) current = temp.size() - 1;
		}
		if (int(key) == KEY_DOWN)
		{
			Delete_On_Console(1, current * 5 + 5, 80, current * 5 + 7);
			temp[current].COUT_NAME(current * 5 + 5, 1, 80, White);
			current += 1;
			if (current >= temp.size()) current = 0;
		}
		if (int(key) == 83)
		{
			//// Press Shift + S to print bill
			// Test function  print bill
			system("cls");

			//resizeConsole(1780, 1000);
			int move = Enter_Customer();
			system("cls");
			if (move != -1)
			{
				if (move != data.size()) main_data.Sell_Bags(data[move]);
				else
				{
					Customer temp("0", "0", 0);
					main_data.Sell_Bags(temp);
				}
				system("cls");
			}
			//resizeConsole(895, 518);
			//resizeConsole(980, 535);
			return;
		}
		if (int(key) == KEY_ADD)
		{
			if (main_data.Sell_A_Smartphone(temp[current].Get_ID()))
			{
				temp[current].Decrease_StockLevel(1);
			}
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags() + 8);
			main_data.Print_Bill_On_Console();
		}
		if (int(key) == KEY_MINUS)
		{
			if (main_data.Decrease_Quantity(temp[current].Get_ID()))
			{
				temp[current].Increase_StockLevel(1);
			}
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags() + 8);
			main_data.Print_Bill_On_Console();
		}
		if (int(key) == 82)
		{
			// reset bag deo mua nua
			main_data.Reset_Bags();
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags() + 8);
		}
	}
}

string Menu::Show_Option_In_Filter(int y,int current,int&value)
{
	vector<string> temp;
	temp.push_back("None");
	if (current == 1)
	{
		temp.push_back("Under 6M VND");
		temp.push_back("From 6M to 15M VND");
		temp.push_back("Over 15M VND");
	}
	else if (current == 2)
	{
		temp.push_back("Under 4GB");
		temp.push_back("From 4GB to 10GB");
		temp.push_back("Over 10GB");
	}
	else if (current == 3)
	{
		temp.push_back("32GB");
		temp.push_back("64GB");
		temp.push_back("128GB");
		temp.push_back("Over 128GB");
	}
	else if(current==4)
	{
		temp.push_back("Under 3500 mAh");
		temp.push_back("From 3500 mAh to 5000 mAh");
		temp.push_back("Over 5000 mAh");
	}
	switch (current)
	{
	case 0:
		for (int i = 0; i < main_data.Count_Brand.size(); i++) temp.push_back(main_data.Count_Brand[i]);
		value= Move_in_Filter(0,y,temp);
		break;
	case 1:
		value= Move_in_Filter(0, y, temp);
		break;
	case 2:
		value= Move_in_Filter(0, y, temp);
		break;
	case 3:
		value = Move_in_Filter(0, y, temp);
		break;
	case 4:
		value = Move_in_Filter(temp.size()-1, y, temp);
		break;
	}
	if(value>=0) return temp[value];
	return "";
}

int Menu::Move_in_Filter(int current,int y,vector<string>content)
{
	for (int i = 0; i < content.size(); i++)
	{
		textcolor(White);
		gotoxy(85, y + 1 + i * 2); cout << content[i];
	}
	int x = 80;
	int max = content.size()-1;
	char key = '.';
	while (int(key) != KEY_ESC)
	{
		textcolor(Pink);
		gotoxy(85, y + 1 + current * 2); cout << content[current];
		key = _getch();
		switch (int(key))
		{
		case KEY_UP:
			textcolor(White);
			gotoxy(85, y + 1 + current * 2); cout << content[current];
			current -= 1;
			if (current < 0) current = max;
			break;
		case KEY_DOWN:
			textcolor(White);
			gotoxy(85, y + 1 + current * 2); cout << content[current];
			current += 1;
			if (current > max) current = 0;
			break;
		case KEY_ENTER:
			return current;
			break;
		}
	}
	return -1;
}

void Menu::Choice_For_Sell(string chosen_brand)
{
	int y = 5;
	vector<Smartphone>temp;
	main_data.Draw_Phone_of_Brand(chosen_brand,temp);
	char key = '.';
	int current = 0;
	while (key != char(KEY_ESC))
	{
		main_data.Effect_of_Move(current, temp);
		key = _getch();
		if (int(key) == KEY_UP)
		{
			Delete_On_Console(1, current * 5 + 5, 80, current * 5 + 7);
			temp[current].COUT_NAME(current * 5 + 5, 1, 80, White);
			current -= 1;
			if (current < 0) current = temp.size() - 1;
		}
		if (int(key) == KEY_DOWN)
		{
			Delete_On_Console(1, current * 5 + 5, 80, current * 5 + 7);
			temp[current].COUT_NAME(current * 5 + 5, 1, 80, White);
			current += 1;
			if (current >= temp.size()) current = 0;
		}
		if (int(key) == 83)
		{
			//// Press Shift + S to print bill
			// Test function  print bill
			system("cls");

			//resizeConsole(1780, 1000);
			int move=Enter_Customer();
			system("cls");
			if (move != -1)
			{
				if(move!=data.size()) main_data.Sell_Bags(data[move]);
				else
				{
					Customer temp("0", "0", 0);
					main_data.Sell_Bags(temp);
				}
				system("cls");
			}
			//resizeConsole(895, 518);
			//resizeConsole(980, 535);
			return;
		}
		if (int(key) == KEY_ADD)
		{
			if (main_data.Sell_A_Smartphone(temp[current].Get_ID()))
			{
				temp[current].Decrease_StockLevel(1);
			}
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags() + 8);
			main_data.Print_Bill_On_Console();
		}
		if (int(key) == KEY_MINUS)
		{
			if (main_data.Decrease_Quantity(temp[current].Get_ID()))
			{
				temp[current].Increase_StockLevel(1);
			}
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags() + 8);
			main_data.Print_Bill_On_Console();
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
	resizeConsole(1600, 800);
	ifstream fin("BACKGROUND.txt");
	string tmp;
	if (!fin.is_open()) {
		cout << "Group 5:" << endl;
		cout << "Thai Hoang Huy" << endl;
		cout << "Tran Dinh Huy" << endl;
		cout << "Tran Xuan Loc" << endl;
		cout << "Tran Thanh Tuan" << endl;
	}
	else {
		while (!fin.eof())
		{
			
			tmp = fin.get();
			cout << tmp;
		}
		fin.close();
		int posX = 65, posY = 8;
		gotoxy(posX, posY-3);
		cout << "*****************************************";
		gotoxy(posX, posY - 2);
		cout << "* +++++++++++++++++++++++++++++++++++++ *";
		gotoxy(posX, posY - 1);
		cout << "* + ********************************* + *";
		gotoxy(posX, posY);
		cout << "* + *  THAI HOANG HUY  -  18127109  * + *";
		gotoxy(posX, posY + 1);
		cout << "* + *  TRAN DINH HUY   -  18127110  * + *";
		gotoxy(posX, posY + 2);
		cout << "* + *  TRAN XUAN LOC   -  18127131  * + *";
		gotoxy(posX, posY + 3);
		cout << "* + * TRAN THANH TUAN  -  18127247  * + *";
		gotoxy(posX, posY + 4);
		cout << "* + ********************************* + *";
		gotoxy(posX, posY + 5);
		cout << "* +++++++++++++++++++++++++++++++++++++ *";
		gotoxy(posX, posY + 6 );
		cout << "*****************************************";

	}
	system("pause>nul");
	//resizeConsole(895, 518);
	resizeConsole(980, 535);
}
 
void Menu::Exit()
{
	system("cls");
	ifstream fin("thanksyou.txt");
	ifstream fin1("bye bye.txt");
	if (fin.is_open()&& fin1.is_open())
	{
		resizeConsole(1600, 800);
		string tmp;
		while (!fin.eof())
		{
			tmp = fin.get();
			cout << tmp;
		}
		fin.close();
		Sleep(800);
		system("cls");
		while(!fin1.eof())
		{
			tmp = fin1.get();
			cout << tmp;
		}
		fin1.close();
		system("pause");
		resizeConsole(895, 518);

	}
	else {
		gotoxy(55, 15);
		cout << "GOODBYE!!!";
		Sleep(500);
		gotoxy(50, 15);
		cout << "See you later!!!";
	}
}

Menu::Menu()
{
	if (!main_data.Load_Data_from_file())
	main_data.Input_New_Data_from_file("Data.txt", "INFO.txt");
	Load_Data_Customer();
}


Menu::~Menu()
{
	main_data.Save_All_Data();
	Save_Data_Customer();
	
}

bool checkIfUnique(vector<string> unique, string input) {
	if (unique.size() == 0) return true;
	for (size_t i = 0; i < unique.size(); i++) {
		if (input == unique[i]) return false;
	}
	return true;
} // this will check the logo if it existed or not 

void Menu::Master_Move() { // call when login returned 1
	vector<string> uniqueName;
	int xa = 1;
	int ya = 1;
link: {
	uniqueName.erase(uniqueName.begin(), uniqueName.end());
	system("cls");
	// argument to get unique logo for example "Samsung" "Iphone" "Xiaomi" "Asus"
	for (int i = 0; i < main_data.getNum(); i++) {
		if (checkIfUnique(uniqueName, main_data[i].getbrand()))
			uniqueName.push_back(main_data[i].getbrand());
	}
	int x = 8;
	int y = 5;
	for (int i = 1; i <= uniqueName.size() + 3; i++)
	{
		Draw_Box(x, y, 5, 15, White);
		textcolor(DarkCyan);
		gotoxy(x + 4, y + 3);
		if (i <= uniqueName.size()) cout << uniqueName[i - 1];
		else if (i == uniqueName.size() + 1)
		{
			textcolor(Yellow);
			cout << "New";
		}
		else if (i == uniqueName.size() + 2)
		{
			textcolor(Yellow);
			cout << "Customer";
		}
		else
		{
			textcolor(Yellow);
			cout << "Report";
		}
		if (i % 3 == 0)
		{
			x = 8;
			y += 10;
		}
		else
		{
			x += 25;
		}
	}
	//end of unique
	//go for interface
	textcolor(White);
	for (int i = 0; i <= 40; i++)
	{
		gotoxy(80, 1 + i);
		cout << "|$|";
	}
	// drawn line prase between help and menu 
	//menu list

	/*x = 75;
	y = 6;

	textcolor(gray);
	gotoxy(x, y);
	cout << "#use keyboard to move ";
	gotoxy(x, y + 1);
	cout << "#press esc to exit ";*/
	int xBox = 84, yBox = 5;
	Draw_Box(xBox, yBox, 7, 35, White);
	textcolor(Red); gotoxy(xBox + 2, yBox+1); cout << "* Notes:";
	textcolor(White); gotoxy(xBox + 2, yBox+3); cout << "[i]: Press Enter to continue";
	gotoxy(xBox + 2, yBox+5); cout << "[i]: Esc to exit";
	int Xmax = (uniqueName.size()+3) % 3;
	int Ymax = (uniqueName.size()+3) / 3;
	if (Ymax != 0) Ymax += 1;
	else Ymax = 3;
	char c = '.';
	while (int(c)!=KEY_ESC) {
		Draw_Box(xa * 25 - 17, ya * 10 - 5, 5, 15, Cyan);
		c= _getch();
		if (int(c) == KEY_UP) { // up
			Draw_Box(xa * 25 - 17, ya * 10 - 5, 5, 15, White);
			ya -= 1;
			if (ya <= 0)
			{
				ya = Ymax;
				if (xa > Xmax) xa=Xmax;
			}
		}

		if (int(c) == KEY_RIGHT) { // right
			Draw_Box(xa * 25 - 17, ya * 10 - 5, 5, 15, White);
			xa += 1;
			if (ya != Ymax)
			{
				if (xa > 3) xa = 1;
			}
			else
			{
				if (xa > Xmax) xa = 1;
			}
		}

		if (int(c) == KEY_DOWN) { // down
			Draw_Box(xa * 25 - 17, ya * 10 - 5, 5, 15, White);
			ya += 1;
			if (ya > Ymax) ya = 1;
			if (ya == Ymax)
			{
				if (xa > Xmax) xa = Xmax;
			}
		}

		if (int(c) == KEY_LEFT) { // left
			Draw_Box(xa * 25 - 17, ya * 10 - 5, 5, 15, White);
			xa -= 1;
			if (ya != Ymax)
			{
				if (xa <= 0) xa = 3;
			}
			else
			{
				if (xa <= 0) xa = Xmax;
			}
		}

		if (int(c) == KEY_ENTER) { // enter 
			int choice = (ya - 1) * 3 + (xa - 1);
			if(choice == uniqueName.size())
			{
				New();
				system("cls");
			}
			else if (choice == uniqueName.size() + 1)
			{
				Add_Edit_customer();
			}
			else if (choice == uniqueName.size() + 2)
			{
				Report_Interface();
			}
			else
			{
				add_Edit(uniqueName[choice]);
				system("cls");
			}
				goto link;
				break;
			}
		}
	}
}

int Menu::add_Edit(string brand){
link: {
	DisplayLogo(0, 0, (brand + "logo.txt").c_str(), Cyan, 1800);
	vector<int> index; // this vector save the index of each element in store which same brand as my current brand
	int x = 40, y = 5;
	system("cls");
	int length = 0;
	for (int i = 0; i < main_data.getNum(); i++) {
		if (main_data[i].compare_with_brand(brand)) {
			main_data[i].COUT_NAME(y, x, x, White);
			y += 5;
			index.push_back(i);
			length++;
		}
	}
	length--;
	x = 10;
	y = 5;
	// move 
	int Index = 0;
	string Arrow = "-->";
	string deleteArrow = "   ";
	gotoxy(x, y); cout << Arrow;
	char c;
	do {
		c = _getch();
		if ((int)c == KEY_UP) {
			gotoxy(x, y); cout << deleteArrow;
			if (y == 5) {
				y = length * 5 + 5;
				Index = length;
				gotoxy(x, y); cout << Arrow;
			}
			else {
				y -= 5;
				Index--;
				gotoxy(x, y); cout << Arrow;
			}
		}
		if ((int)c == KEY_DOWN) {
			gotoxy(x, y); cout << deleteArrow;
			if (y >= length * 5 + 5) {
				y = 5;
				Index = 0;
				gotoxy(x, y); cout << Arrow;
			}
			else {
				y += 5;
				Index++;
				gotoxy(x, y); cout << Arrow;
			}
		}
		if ((int)c == KEY_ENTER) {
			edit(index[Index]);
			goto link;
			break;
		}
	} while ((int)c != KEY_ESC);
	return 1;
	}
}

void Menu::edit(int Index)
{
	system("cls");
	string inf = main_data[Index].ToString();
	vector<string> data = Tokenizer::Parse(inf, ",");
	gotoxy(20, 1);
	textcolor(Gray); cout << "to edit press enter, exit press ESC" << endl;
	int xBox = 13, yBox = 5;
	Draw_Box(10, 4, 27, 43, 27);// big box
	Draw_Box(xBox, 5, 1, 37, 11); // name
	Draw_Box(xBox, 8, 1, 37, 11); // origin
	Draw_Box(xBox, 11, 1, 37, 11);// price B
	Draw_Box(xBox, 14, 1, 37, 11);// price S
	Draw_Box(xBox, 17, 1, 37, 11);// ram
	Draw_Box(xBox, 20, 1, 37, 11);// rom
	Draw_Box(xBox, 23, 1, 37, 11);// battery
	Draw_Box(xBox, 26, 1, 37, 11);// screen
	Draw_Box(xBox, 29, 1, 37, 11);//stock
	int x = 15, y = 6;
	for (int i = 1; i < data.size(); i++) {
		gotoxy(x, y);
		textcolor(Yellow);
		cout << data[i];
		y += 3;
	}
	y = 6;
	Draw_Box(xBox, y - 1, 1, 37, Red);
	int index = 1;
	gotoxy(x, y);
	char c;
	do {
		c = _getch();
		if ((int)c == KEY_UP) {
			Draw_Box(xBox, y - 1, 1, 37, Cyan);
			if (y == 6) {
				y = 30;
				index = 9;
			}
			else {
				y -= 3;
				index--;
			}
			Draw_Box(xBox, y - 1, 1, 37, Red);
			gotoxy(x, y);
		}
		if ((int)c == KEY_DOWN) {
			Draw_Box(xBox, y - 1, 1, 37, Cyan);
			if (y >= 30) {
				y = 6;
				index = 1;
			}
			else {
				y += 3;
				index++;
			}
			Draw_Box(xBox, y - 1, 1, 37, Red);
			gotoxy(x, y);
		}
		if ((int)c == KEY_ENTER) {
			do {
				cout << "                                  ";
				gotoxy(x, y);
				textcolor(Yellow);
				char tmp[100];
				gets_s(tmp);
				data[index] = (string)tmp;
				if (data[index] == "") {
					gotoxy(57, y);
					cout << "This value can't emty";
				}
				gotoxy(x, y);
			} while (data[index] == "");
		}
		if ((int)c == KEY_ESC) break;
	} while (1);
	Smartphone tmp(data[0], data[1], data[2], stoi(data[3]), stoi(data[4]), data[5], data[6], data[7], data[8], stoi(data[9]));
	main_data[Index] = tmp;
}

void Menu::New()
{
	bool empty = false;
link: {
	system("cls");
	if (empty == true) {
		gotoxy(15, 2);
		cout << "Value cannot empty";
	}
	empty = false;
	gotoxy(20, 1);
	textcolor(Gray); cout << "to edit press enter, exit press ESC" << endl;
	int xBox = 13, yBox = 5;
	Draw_Box(10, 4, 31, 43, 27);// big box
	Draw_Box(xBox, 5, 1, 37, 11); // name
	Draw_Box(xBox, 8, 1, 37, 11); // origin
	Draw_Box(xBox, 11, 1, 37, 11);// price B
	Draw_Box(xBox, 14, 1, 37, 11);// price S
	Draw_Box(xBox, 17, 1, 37, 11);// ram
	Draw_Box(xBox, 20, 1, 37, 11);// rom
	Draw_Box(xBox, 23, 1, 37, 11);// battery
	Draw_Box(xBox, 26, 1, 37, 11);// screen
	Draw_Box(xBox, 29, 1, 37, 11);//stock
	Draw_Box(xBox + 10, 32, 1, 10, 11); // edit add button
	int x = 15, y = 6;
	gotoxy(x, y); cout << "# Name"; y += 3;
	gotoxy(x, y); cout << "# Origin"; y += 3;
	gotoxy(x, y); cout << "# Price buy"; y += 3;
	gotoxy(x, y); cout << "# Price sell"; y += 3;
	gotoxy(x, y); cout << "# Ram"; y += 3;
	gotoxy(x, y); cout << "# Rom"; y += 3;
	gotoxy(x, y); cout << "# Battery"; y += 3;
	gotoxy(x, y); cout << "# Screen"; y += 3;
	gotoxy(x, y); cout << "# Stock"; y += 3;
	gotoxy(x + 10, y); cout << "add +"; y += 3;
	y = 6; gotoxy(x, y);
	int lbox = 37;
	string data[10];
	for (int i = 0; i < 10; i++) {
		data[i] = "";
	}
	int index = 1;
	Draw_Box(xBox, y - 1, 1, 37, Red);
	char c;
	gotoxy(x, y);
	do {
		c = _getch();
		if ((int)c == KEY_UP) {
			Draw_Box(xBox, y - 1, 1, lbox, Cyan);
			if (y == 6) {
				xBox = 23;
				y = 33;
				lbox = 10;
				index = 10;
			}
			else {
				lbox = 37;
				xBox = 13;
				y -= 3;
				index--;
			}
			Draw_Box(xBox, y - 1, 1, lbox, Red);
			gotoxy(x, y);
		}
		if ((int)c == KEY_DOWN) {
			Draw_Box(xBox, y - 1, 1, lbox, Cyan);
			if (y >= 33) {
				xBox = 13;
				y = 6;
				lbox = 37;
				index = 1;
			}
			else {
				y += 3;
				index++;
				if (index == 10) {
					xBox = 23;
					lbox = 10;
				}
				else {
					xBox = 13;
					lbox = 37;
				}
			}
			Draw_Box(xBox, y - 1, 1, lbox, Red);
			gotoxy(x, y);
		}
		if ((int)c == KEY_ENTER && index < 10) {
			cout << "                                  ";
			gotoxy(x, y);
			textcolor(Yellow);
			char tmp[100];
			gets_s(tmp);
			data[index] = (string)tmp;
			gotoxy(x, y);
		}
		if ((int)c == KEY_ENTER && index == 10) {
			if (data[1] == "" || data[2] == "" || data[3] == "" || data[4] == "" || data[5] == "" || data[6] == "" || data[7] == "" || data[8] == "" || data[9] == "") {
				empty = true;
				goto link;
			}
			else {
				int r = rand() % 99999 + 100000;
				char ran[10];
				_itoa_s(r, ran, 10);
				for (size_t i = 0; i < main_data.getNum(); i++) {
					while (main_data[i].compare_with_id((string)ran)) {
						int r = rand() % 99999 + 100000;
						_itoa_s(r, ran, 10);
					}
				}
				data[0] = (string)ran;
				Smartphone tmp(data[0], data[1], data[2], stoi(data[3]), stoi(data[4]), data[5], data[6], data[7], data[8], stoi(data[9]));
				main_data.addNewSmartphone(tmp);
				return;
			}
		}
		if ((int)c == KEY_ESC) break;
	} while (1);
	}
}

void Menu::Add_Edit_customer()
{
	int index = 0;
	int xbox = 45, ybox = 5;
link: {
	system("cls");
	for (size_t i = 0; i < data.size(); i++) {
		Draw_Box(xbox, ybox, 1, 30, White);
		textcolor(Cyan);
		data[i].Show_tmp_data(xbox + 2, ybox + 1);
		ybox += 4;
	}
	Draw_Box(xbox, ybox, 1, 30, DarkCyan);
	gotoxy(xbox + 2, ybox + 1);
	textcolor(Yellow);
	cout << "  New customer";
	char c;
	xbox = 84, ybox = 5;
	Draw_Box(xbox, ybox, 7, 35, White);
	textcolor(Red); gotoxy(xbox + 2, ybox + 1); cout << "* Notes:";
	textcolor(White); gotoxy(xbox + 2, ybox + 3); cout << "[i]: Press Enter to continue";
	gotoxy(xbox + 2, ybox + 5); cout << "[i]: Esc to exit";
	xbox = 45, ybox = 5;
	do {
		Draw_Box(xbox, ybox + index * 4, 1, 30,Red);
		c = _getch();
		if ((int)c == KEY_UP) //up
		{
			Draw_Box(xbox, ybox+index*4, 1, 30, White);
			index -= 1;
			if (index < 0) index = data.size();
		}
		if ((int)c == KEY_DOWN) {
			Draw_Box(xbox, ybox + index * 4, 1, 30, White);
			index += 1;
			if (index > data.size()) index = 0;
		}
		if ((int)c == KEY_ENTER) {
			cout << index;
			if (index != data.size()) {
				Edit_customer(index);
				goto link;
			}
			if (index == data.size()) {
				//new customer
				Create_New_Customer();
				goto link;
			}
		}
	} while ((int)c != KEY_ESC );
	}
	return;
}

void Menu::Edit_customer(int index)
{
Done:
	system("cls");
	int xbox = 10, ybox = 5;
	xbox = 84, ybox = 5;
	Draw_Box(xbox, ybox, 7, 35, White);
	textcolor(Red); gotoxy(xbox + 2, ybox + 1); cout << "* Notes:";
	textcolor(White); gotoxy(xbox + 2, ybox + 3); cout << "[i]: Press Enter to continue";
	gotoxy(xbox + 2, ybox + 5); cout << "[i]: Press Shift + H to history";
	gotoxy(xbox + 2, ybox + 7); cout << "[i]: Esc to exit";
	xbox = 10, ybox = 5;
	Draw_Box(xbox, ybox, 18, 50, 25); // bigbox
	gotoxy(xbox + 2, ybox + 1);
	textcolor(Yellow);
	cout << "ID";
	ybox += 1;
	Draw_Box(xbox + 1, ybox + 1, 1, 48, White); // id box
	ybox += 4;
	gotoxy(xbox + 2, ybox);
	textcolor(Yellow);
	cout << "Name";
	Draw_Box(xbox + 1, ybox + 1, 1, 48, White); // name box
	ybox += 4;
	gotoxy(xbox + 2, ybox);
	textcolor(Yellow);
	cout << "Point";
	Draw_Box(xbox + 1, ybox + 1, 1, 48, White); // name box
	ybox += 4;
	ybox = 5;
	data[index].Display_Data_index(xbox + 2, 8, xbox + 2, 12, xbox + 2, 16, (data[index].Classify_Member() + ".txt").c_str(), xbox + 1, 19);
	char c;
	int x = xbox + 1;
	int y = 7;
	vector<string> cdata = Tokenizer::Parse(data[index].ToString(), ",");
	int i = 0;
	Draw_Box(x, y, 1, 48, Red);
	gotoxy(x+1, y+1);
	while (1) {
		c = _getch();
		if ((int)c == KEY_UP) {
			Draw_Box(x, y, 1, 48, White);
			if (y <= 7) {
				y = 15;
				i = 2;
			}
			else {
				y -= 4;
				i--;
			}
			Draw_Box(x, y, 1, 48, Red);
			gotoxy(x + 1, y + 1);
		}
		if ((int)c == KEY_DOWN) {
			Draw_Box(x, y, 1, 48, White);
			if (y >= 12) {
				y = 7;
				i = 0;
			}
			else {
				y += 4;
				i++;
			}
			Draw_Box(x, y, 1, 48, Red);
			gotoxy(x + 1, y + 1);
		}
		if ((int)c == KEY_ENTER) {
			do {
				gotoxy(x + 1, y + 1);
				cout << "                  ";
				gotoxy(x + 1, y + 1);
				char tmp[1000];
				gets_s(tmp);
				cdata[i] = (string)tmp;
				if (cdata[i] == "") {
					gotoxy(x + 52, y);
					cout << "value can't be null";
				}
			} while (cdata[i] == "");
			gotoxy(x + 1, y + 1);
		}
		if ((int)c == 72)
		{
			Create_Hitory(index);
			system("cls");
			goto Done;

		}

		if ((int)c == KEY_ESC) {
			Customer tmp(cdata[0], cdata[1], stoi(cdata[2]));
			data[index] = tmp;
			return;
		}
	}
}

void Menu::find_BaseOn_ID_or_Name()
{
	int posx = 20;
	int posy = 5;
	Draw_Box(posx, posy, 8, 40, 25); // bigbox
	gotoxy(posx + 45, posy);
	textcolor(Gray);
	cout << "Press Shift F to find";
	textcolor(Cyan);
	gotoxy(posx + 1, posy + 1);
	cout << "Base on: ";
	Draw_Box(posx + 1, posy + 2, 1, 38, Cyan); // base box
	Draw_Box(posx + 1, posy + 5, 1, 38, Cyan); // value input box
	gotoxy(posx + 2, posy + 3);
	cout << "None";
	char c = '\0';
	string arrow = "=>";
	string value = "";
	string ValueCompare = "";
	int index = 1;
	gotoxy(posx + 35, posy + 3);
	cout << arrow;
	int y = posy + 3;
	while ((int)c != KEY_ESC) {
		c = _getch();
		if ((int)c == KEY_UP) {
			gotoxy(posx + 35, y);
			cout << "  ";
			if (index == 1) {
				index = 2;
				y = posy + 6;
			}
			else {
				index = 1;
				y = posy + 3;
			}
			gotoxy(posx + 35, y);
			cout << arrow;
		}
		if ((int)c == KEY_DOWN) {
			gotoxy(posx + 35, y);
			cout << "  ";
			if (index == 2) {
				index = 1;
				y = posy + 3;
			}
			else {
				index ++;
				y = posy + 6;
			}
			gotoxy(posx + 35, y);
			cout << arrow;
		}
		if ((int)c == KEY_ENTER) {
			if (index == 1) {
				goto right;
			}
			else if (index == 2) {
				gotoxy(posx + 2, posy + 6);
				cout << "                                   ";
				gotoxy(posx + 2, posy + 6);
				char tmp[1000];
				gets_s(tmp);
				ValueCompare = (string)tmp;
				gotoxy(posx + 2, posy + 6);
			}
		}
		if ((int)c == 70) {
			system("cls");
			if (value == "ID") {
				for (int i = 0; i < main_data.getNum(); i++) {
					if (main_data[i].compare_with_id(ValueCompare) == true) {
						cout << main_data[i] << endl;
						system("pause");
						system("cls");
						return;
					}
				}
			}
			if (value == "Name") {
				for (int i = 0; i < main_data.getNum(); i++) {
					if (main_data[i].compare_with_name(ValueCompare) == true) {
						cout << main_data[i] << endl;
						system("pause");
						system("cls");
						return;
					}
				}
			}
			else {
				cout << "NOT FOUND" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	right: {
		if ((int)c == KEY_RIGHT) {
			if (index == 1) {
				value = ChoiceToFind(posx + 41, posy + 3);
				gotoxy(posx + 2, posy + 3);
				cout << "        ";
				textcolor(Cyan);
				gotoxy(posx + 2, posy + 3);
				cout << value;
			}
		}
		}
	}
}

string Menu::ChoiceToFind(int x, int y)
{
	string v[] = { "ID", "Name" };
	textcolor(Red);
	gotoxy(x, y);
	cout << "+ ID";
	textcolor(White);
	gotoxy(x, y + 1);
	cout << "+ Name";
	char c = '\0';
	int index = 1;
	while ((int)c != KEY_LEFT && (int)c != KEY_ESC) {
		c = _getch();
		if ((int)c == KEY_UP) {
			gotoxy(x, y);
			textcolor(White);
			cout <<"+ "  << v[index - 1];
			if (index <= 1) {
				index = 2;
				y ++;
			}
			else {
				index--;
				y --;
			}
			gotoxy(x, y);
			textcolor(Red);
			cout <<"+ "<< v[index - 1];
		}
		if ((int)c == KEY_DOWN) {
			gotoxy(x, y);
			textcolor(White);
			cout <<"+ "<< v[index - 1];
			if (index == 1) {
				index++;
				y ++;
			
			}
			else {
				index = 1;
				y --;
			}
			gotoxy(x, y);
			textcolor(Red);
			cout << "+ "<<v[index - 1];
		}
		if ((int)c == KEY_ENTER) {
			return v[index - 1];
		}
	}
	return "None";
}

bool Menu::Create_Hitory(int index)
{
	system("cls");
	ifstream file(data[index].Get_ID()+".txt");
	if (!file.is_open()) return false;
	while (file.good())
	{
		char temp[1000];
		file.getline(temp, 1000, '\n');
		string out = string(temp);
		cout << temp << endl;
	}
	file.close();
	system("pause>nul");
	return true;
}

//costumer function
void Menu::Load_Data_Customer()
{
	ifstream file(path_customer);
	if (!file.is_open()) return;
	while (file.good())
	{
		char temp[1000];
		string name;
		string id;
		string point;
		file.getline(temp, 1000, ','); id = string(temp);
		file.getline(temp, 1000, ','); name = string(temp);
		file.getline(temp, 1000, '\n'); point = string(temp);
		Customer test(id, name, stoi(point));
		data.push_back(test);
	}
	data[0].signal = 1;
	file.close();
}

void Menu::Save_Data_Customer()
{
	ofstream file(path_customer);
	if (!file.is_open()) return;
	for (int i = 0; i < data.size() - 1; i++)
	{
		data[i].Save_Attribute(file);
		file << "\n";
	}
	data[data.size() -1].Save_Attribute(file);
	file.close();
}

void Menu::Move_in_Customer()
{
Done:
	system("cls");
	// Draw effect
	int xBox = 40, yBox = 5;
	Draw_Box(37, 4, 25, 43, 25);// big box
	for (int i = 0; i <= 1; i++)
	{
		Draw_Box(xBox, 7 + i * 5, 1, 37, White);
	}
	int x = 42;
	textcolor(Cyan);
	gotoxy(x, 6); cout << "ID";
	gotoxy(x, 11); cout << "Name";
	textcolor(Red);
	gotoxy(49, 2); cout << "Customer Management";
	Draw_Box(xBox, 17, 7, 37, White);
	textcolor(Red); gotoxy(xBox+2, 18); cout << "* Notes:";
	textcolor(White); gotoxy(xBox + 2, 20); cout << "[i]: Press Enter to continue";
	gotoxy(xBox+2, 22); cout << "[i]: Esc to exit";
	gotoxy(xBox + 2, 24); cout << "[i]: Shilft + N to create new";
	gotoxy(xBox + 2, 8);
	string place1 = Enter(xBox+2, 8);
	if (place1 == "") return;
	if (place1 == "N") Create_New_Customer();
	gotoxy(xBox + 2, 13);
	string place2 = Enter(xBox+2, 13);
	if (place2 == "") return;
	if (place2 == "N") Create_New_Customer();
	bool check = false;
	system("cls");
	for (int i = 0; i < data.size()&&!check; i++)
	{
		check = data[i].Show_Info(place1,place2);
	}
	if (!check) cout << "NOT FOUNDED";
	system("pause>nul");
	goto Done;
}

void Menu::Create_New_Customer()
{
Done:
	system("cls");
	// Draw effect
	int xBox = 40, yBox = 5;
	Draw_Box(37, 4, 25, 43, 25);// big box
	for (int i = 0; i <= 1; i++)
	{
		Draw_Box(xBox, 7 + i * 5, 1, 37, White);
	}
	int x = 42;
	textcolor(Cyan);
	gotoxy(x, 6); cout << "ID";
	gotoxy(x, 11); cout << "Name";
	textcolor(Red);
	gotoxy(49, 2); cout << "Register new memmber";
	Draw_Box(xBox, 17, 7, 37, White);
	textcolor(Red); gotoxy(xBox + 2, 18); cout << "* Notes:";
	textcolor(White); gotoxy(xBox + 2, 20); cout << "[i]: Press Enter to continue";
	gotoxy(xBox + 2, 22); cout << "[i]: Esc to exit";
	gotoxy(xBox + 2, 8);
	string place1 = Enter(xBox + 2, 8);
	if (place1 == "") return;
	gotoxy(xBox + 2, 13);
	string place2 = Enter(xBox + 2, 13);
	if (place2 == "") return;
	bool check = Check_Existing_Costumer(place2, place1);
	gotoxy(49, 3);
	textcolor(Red);
	if (!check) cout << "Register successfully!!!";
	else cout << "Account has existed!!!!";
	system("pause>nul");
	goto Done;
}

bool Menu::Check_Existing_Costumer(string name, string id)
{
	bool check = false;
	for (int i = 0; i < data.size() && !check; i++)
	{
		check = data[i].check_id_name(name, id);
	}
	if (!check)
	{
		Customer temp(id, name, 0);
		data.push_back(temp);
	}
	return check;
}

int Menu::Enter_Customer()
{
	string id;
	textcolor(Red);
	gotoxy(41, 12); cout << "Customer 's ID";
	Draw_Box(40, 13, 1, 40, Cyan);
	gotoxy(42, 14);
	textcolor(White);
	id = Enter(42, 14);
	if (id == "") return -1;// return 
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].check_id_name("temp", id)) return i; // position of customer in array
	}
	return data.size();// not exist
}

//Report
void Menu::Report_Interface()
{
	int choice = 0;
Done:
	system("cls");
	string array[4] = { "Best seller", "Profit in year","Profit in distance","Statistic Stocks in year" };
	char key = '.';
	int line = 12, col = 55;//vi tri
	textcolor(White);
	for (int i = 0; i < 4; i++)
	{
		gotoxy(col, line + i); cout << array[i];
	}
	int choice_num = 3;
	while (int(key)!=KEY_ESC)
	{
		textcolor(Red);
		gotoxy(col, line + choice); cout << array[choice];
		key = _getch();
		if (int(key) == KEY_UP)
		{
			textcolor(White);
			gotoxy(col, line + choice); cout << array[choice];
			choice--;
			if (choice < 0) choice = choice_num;
		}
		if (int(key) == KEY_DOWN)
		{
			textcolor(White);
			gotoxy(col, line + choice); cout << array[choice];
			choice++;
			if (choice > choice_num) choice = 0;
		}
		if (int(key) == KEY_ENTER)
		{
			if (choice == 0)
			{
				//FUNCTION bestseller
				system("cls");
				textcolor(Red);
				gotoxy(51, 2); cout << "Best Seller";
				Menu_Best_Seller(1);
			}
			if (choice == 1)
			{
				//FUNCTION profit year
				//Calc_Profit_Follow_Year(int year);
				Menu_Profit_Year();
			}
			if (choice == 2)
			{
				//FUNCTION profit distance
				//Calc_Profit_Follow_2Month_To_2Year(int month1, int year1, int month2, int year2);
				system("cls");
				textcolor(Red);
				gotoxy(51, 2); cout << "Profit in distance";
				Menu_Best_Seller(2);
			}
			if (choice == 3)
			{
				Menu_Stock_Year();
			}
			goto Done;
		}
	}

}

void Menu::Menu_Best_Seller(int status)
{
	// Draw effect
	int xBox = 40, yBox = 5;
	Draw_Box(37, 4, 22, 43, 25);// big box
	for (int i = 0; i <= 3; i++)
	{
		Draw_Box(xBox, 7 + i * 5, 1, 37, White);
	}
	int x = 42;
	textcolor(Cyan);
	gotoxy(x, 6); cout << "From month";
	gotoxy(x, 11); cout << "From year";
	gotoxy(x, 16); cout << "To month";
	gotoxy(x, 21); cout << "To year";
	textcolor(White);
	Draw_Box(4, 12, 7, 31, White);
	textcolor(Red); gotoxy(6, 13); cout << "* Notes:";
	textcolor(White); gotoxy(6, 15); cout << "[i]: Press Shift + F to find";
	gotoxy(6, 17); cout << "[i]: Esc to exit";
	string month1, month2, year1, year2;
	gotoxy(x + 1, 8);
	month1 = Enter(x + 1, 8);
	if (month1 == "") return;
	gotoxy(x + 1, 8 + 5 * 1);
	year1 = Enter(x + 1, 8 + 5 * 1);
	if (year1 == "") return;
	gotoxy(x + 1, 8 + 5 * 2);
	month2 = Enter(x + 1, 8 + 5 * 2);
	if (month2 == "") return;
	gotoxy(x + 1, 8 + 5 * 3);
	year2 = Enter(x + 1, 8 + 5 * 3);
	if (year2 == "") return;
	if (status == 1)report.find_Best_Seller_In(stoi(month1), stoi(year1), stoi(month2), stoi(year2));
	else {
		system("cls");
		cout << (long long)report.Calc_Profit_Follow_2Month_To_2Year(stoi(month1), stoi(year1), stoi(month2), stoi(year2));
		cout << endl;
		system("pause");
	}
}

void Menu::Menu_Profit_Year()
{
	system("cls");
	textcolor(Red);
	gotoxy(51, 2); cout << "Profit in year";
	gotoxy(41, 12); cout << "Year";
	Draw_Box(40, 13, 1, 40, Cyan);
	string year;
	gotoxy(42, 14);
	textcolor(White);
	year= Enter(42, 14);
	if (year == "") return;
	system("cls");
	resizeConsole(1700, 900);
	report.Draw_Chart_forA_Year(stoi(year));
	resizeConsole(980, 535);
	system("cls");
}

void Menu::Menu_Stock_Year()
{
	system("cls");
	textcolor(Red);
	gotoxy(51, 2); cout << "Statistic Stocks in year";
	Draw_Box(40, 13, 1, 40, Cyan);
	string year;
	gotoxy(42, 14);
	textcolor(White);
	year = Enter(42, 14);
	if (year == "") return;
	system("cls");
	resizeConsole(1700, 900);
	report.Draw_Chart_forA_Year_Stocklevel(stoi(year));
	resizeConsole(895, 518);
	system("cls");
}

