#include<iostream>
#include"Store.h"
#include<vector>
#include"Menu.h"
#include "Report.h"
using namespace std;
int Store::num = 0;
int main()
{
	resizeConsole(895,518 );
	Menu screen;
	//screen.Start_System();
	screen.Print_FlashScreen();
	return 0;
}