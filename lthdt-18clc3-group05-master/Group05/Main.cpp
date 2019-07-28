#include<iostream>
#include"Store.h"
#include<vector>
#include"Menu.h"
#include "Report.h"
using namespace std;
int Store::num = 0;
int main()
{
	resizeConsole(970,535 );
	Menu screen;
	//screen.Start_System();
	screen.Print_FlashScreen();
	return 0;
}