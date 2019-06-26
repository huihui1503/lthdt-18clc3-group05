#include<iostream>
#include"Store.h"
#include<vector>
//#include"Dohoa.h"
#include"Menu.h"
using namespace std;
int Store::num = 0;
int main(void)
{
	resizeConsole(1768,768);
	//Menu screen;
	//screen.Start_System();
	//screen.Print_FlashScreen();
	//Store a;

//	a.Input_New_Data_from_file("Data.txt", "INFO.txt");
	//a.Display_All_Advanced();
	//a.Save_All_Data();
	Table_Calc_Cost(10);
	system("pause");
	return 0;
}