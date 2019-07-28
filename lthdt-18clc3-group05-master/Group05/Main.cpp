#include<iostream>
#include"Store.h"
#include<vector>
#include"Menu.h"
#include "Report.h"
using namespace std;
int Store::num = 0;
int main()
{
	//resizeConsole(980,535);
	Menu screen;
	screen.Start_System();
	screen.Print_FlashScreen();
	//Store a;
	//a.Input_New_Data_from_file("data.txt", "INFO.txt");
	//a.Save_All_Data();
	return 0;
}