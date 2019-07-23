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
	move += 2;// for advance filter and costumer
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
			if (current == move-1)
			{
				Move_in_Costumer();
				system("cls");
				main_data.Draw_Bag();
			}
			else if(current==move-2)
			{
				Advanced_Filter();
				system("cls");
				main_data.Draw_Bag();
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
	gotoxy(33, 2); cout << "FONDED PRODUCTS";
	for(int i=0;i<temp.size();i++) temp[i].COUT_NAME(i * 5 + 5, 1, 80, White);
	char key = '.';
	int current = 0;
	while (key != char(KEY_ESC))
	{
		main_data.Effect_of_Move(current, temp);
		key = _getch();
		switch (int(key))
		{
		case KEY_UP:
			Delete_On_Console(1, current * 5 + 5, 80, current * 5 + 7);
			temp[current].COUT_NAME(current * 5 + 5, 1, 80, White);
			current -= 1;
			if (current < 0) current = temp.size() - 1;
			break;
		case KEY_DOWN:
			Delete_On_Console(1, current * 5 + 5, 80, current * 5 + 7);
			temp[current].COUT_NAME(current * 5 + 5, 1, 80, White);
			current += 1;
			if (current >= temp.size()) current = 0;
			break;
		case 83:
			//// Press Shift + S to print bill
			break;
		case KEY_ADD:
			if (main_data.Sell_A_Smartphone(temp[current].Get_ID()))
			{
				temp[current].Decrease_StockLevel(1);
			}
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags() + 8);
			main_data.Print_Bill_On_Console();
			break;
		case KEY_MINUS:
			if (main_data.Decrease_Quantity(temp[current].Get_ID()))
			{
				temp[current].Increase_StockLevel(1);
			}
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags() + 8);
			main_data.Print_Bill_On_Console();
			break;
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
		switch (int(key))
		{
		case KEY_UP:
			Delete_On_Console(1, current * 5 + 5, 80, current * 5 + 7);
			temp[current].COUT_NAME(current * 5 + 5, 1, 80, White);
			current -= 1;
			if (current < 0) current = temp.size() - 1;
			break;
		case KEY_DOWN:
			Delete_On_Console(1, current * 5 + 5, 80, current * 5 + 7);
			temp[current].COUT_NAME(current * 5 + 5, 1, 80, White);
			current += 1;
			if (current >= temp.size()) current = 0;
			break;
		case 83:
			//// Press Shift + S to print bill
			// Test function  print bill
			system("cls");
			resizeConsole(1780, 1000);
			main_data.Sell_Bags();
			system("pause");

			system("cls");
			resizeConsole(895, 518);
			Seller_Move();
			break;
		case KEY_ADD:
			if (main_data.Sell_A_Smartphone(temp[current].Get_ID()))
			{
				temp[current].Decrease_StockLevel(1);
			}
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags()+8);
			main_data.Print_Bill_On_Console();
			break;
		case KEY_MINUS:
			if (main_data.Decrease_Quantity(temp[current].Get_ID()))
			{
				temp[current].Increase_StockLevel(1);
			}
			Delete_On_Console(84, 5, 120, main_data.Get_Size_Of_Bags()+8);
			main_data.Print_Bill_On_Console();
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
	cout << "Tran Thanh Tuan" << endl;
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
}

Menu::Menu()
{
	//if (main_data.Load_Data_from_file())
		//return;
	//else 
	main_data.Input_New_Data_from_file("Data.txt", "INFO.txt");
	Load_Data_Costumer();
}


Menu::~Menu()
{
	main_data.Save_All_Data();
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
			textcolor(Pink);
			cout << "New";
		}
		else if (i == uniqueName.size() + 2)
		{
			textcolor(Pink);
			cout << "Costumer";
		}
		else
		{
			textcolor(Pink);
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
				//costumer
			}
			else if (choice == uniqueName.size() + 2)
			{
				//report
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
			cout << "                                  ";
			gotoxy(x, y);
			textcolor(Yellow);
			char tmp[100];
			gets_s(tmp);
			data[index] = (string)tmp;
			gotoxy(x, y);
		}
		if ((int)c == KEY_ESC) break;
	} while (1);
	Smartphone tmp(data[0], data[1], data[2], stoi(data[3]), stoi(data[4]), data[5], data[6], data[7], data[8], stoi(data[9]));
	main_data[Index] = tmp;
}

void Menu::New()
{
	system("cls");
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
	gotoxy(x, y); cout << "# Name"; y += 3;
	gotoxy(x, y); cout << "# Origin"; y += 3;
	gotoxy(x, y); cout << "# Price buy"; y += 3;
	gotoxy(x, y); cout << "# Price sell"; y += 3;
	gotoxy(x, y); cout << "# Ram"; y += 3;
	gotoxy(x, y); cout << "# Rom"; y += 3;
	gotoxy(x, y); cout << "# Battery"; y += 3;
	gotoxy(x, y); cout << "# Screen"; y += 3;
	gotoxy(x, y); cout << "# Stock"; y += 3;
	y = 6; gotoxy(x, y);
	string data[10];
	for (int i = 0; i < 10; i++) {
		data[i] = "0";
	}
	int index = 1;
	Draw_Box(xBox, y - 1, 1, 37, Red);
	char c;
	gotoxy(x, y);
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
			cout << "                                  ";
			gotoxy(x, y);
			textcolor(Yellow);
			char tmp[100];
			gets_s(tmp);
			data[index] = (string)tmp;
			gotoxy(x, y);
		}
		if ((int)c == KEY_ESC) break;
	} while (1);
	int r = rand() % 99999 + 100000;
	char ran[10];
	_itoa_s(r, ran, 10);
	for (size_t i = 0; i < main_data.getNum(); i++) {
		while(main_data[i].compare_with_id((string)ran)) {
			int r = rand() % 99999 + 100000;
			_itoa_s(r, ran, 10);
		}
	}
	data[0] = (string)ran;
	Smartphone tmp(data[0], data[1], data[2], stoi(data[3]), stoi(data[4]), data[5], data[6], data[7], data[8], stoi(data[9]));
	main_data.addNewSmartphone(tmp);
}

void Menu::Add_Edit_customer()
{
	int xbox = 10, ybox = 5;
	for (size_t i = 0; i < data.size(); i++) {
		Draw_Box(xbox, ybox, 3, 13, DarkCyan);
		xbox += 17;
		Draw_Box(xbox, ybox, 3, 13, DarkCyan);
		data[i].Show_tmp_data(xbox + 1, ybox + 1, xbox + 18, ybox + 1);
		ybox += 4;
	}
	xbox = 10;
	ybox = 5;
}


//costumer function
void Menu::Load_Data_Costumer()
{
	ifstream file(path_costumer);
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
		file.ignore();
		Customer test(id, name, stoi(point));
		data.push_back(test);
	}
	data[0].signal = 1;
	file.close();
}

void Menu::Save_Data_Costumer()
{
	ofstream file(path_costumer);
	if (!file.is_open()) return;
	for (int i = 0; i < data.size(); i++)
	{
		data[i].Save_Attribute(file);
	}
	file.close();
}

void Menu::Move_in_Costumer()
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
	gotoxy(49, 2); cout << "Costumer Management";
	Draw_Box(xBox, 17, 7, 37, White);
	textcolor(Red); gotoxy(xBox+2, 18); cout << "* Notes:";
	textcolor(White); gotoxy(xBox + 2, 20); cout << "[i]: Press Enter to continue";
	gotoxy(xBox+2, 22); cout << "[i]: Esc to exit";
	gotoxy(xBox + 2, 8);
	string place1 = Enter(xBox+2, 8);
	gotoxy(xBox + 2, 13);
	string place2 = Enter(xBox+2, 13);
	if (place1 == "" && place2 == "") return;
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