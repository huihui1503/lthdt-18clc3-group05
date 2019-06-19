#include<iostream>
#include"Store.h"
#include<vector>
#include"Dohoa.h"
#include"Menu.h"
using namespace std;
int main(void)
{
	Store a;
	//Menu screen;
	//screen.Start_System();
	//screen.Print_FlashScreen();
	a.Load_Data_from_file("data.txt");
	return 0;
}