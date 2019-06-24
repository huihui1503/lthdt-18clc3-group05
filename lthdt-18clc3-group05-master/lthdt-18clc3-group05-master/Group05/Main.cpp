#include<iostream>
#include"Store.h"
#include<vector>
#include"Menu.h"
using namespace std;
int Store::num = 0;
int main(void)
{
	//Menu screen;
	//screen.Start_System();
	//screen.Print_FlashScreen();
	Store a;
	a.Load_Data_from_file();
	a.Save_All_Data();
	return 0;
}