#include<iostream>
#include"Store.h"
#include<vector>
#include"Menu.h"
using namespace std;
int Store::num = 0;
int main()
{
	//resizeConsole(895,518 );
	Menu screen;
	screen.Start_System();
	screen.Print_FlashScreen();
	//resizeConsole(1700,700);
	//Table_Draw_Chart(15);
	return 0;
}