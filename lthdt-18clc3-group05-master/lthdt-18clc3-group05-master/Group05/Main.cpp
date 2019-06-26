#include<iostream>
#include"Store.h"
#include<vector>
//#include"Dohoa.h"
#include"Menu.h"
using namespace std;
int Store::num = 0;
int main(void)
{
	//resizeConsole(1768,768);
	Menu screen;
	screen.Start_System();
	screen.Print_FlashScreen();
	//Table_Calc_Cost(10);
	system("pause");
	return 0;
}