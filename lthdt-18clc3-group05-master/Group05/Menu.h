#pragma once
#include<iostream>
#include<string>
#include"Store.h"
#include"Dohoa.h"
#include <io.h>
#include <fcntl.h>
using namespace std;
class Store;
class Menu
{
private:
	Store main_data;
public:
	void Seller_Move();
	void About_Us();
	void Exit();
	string Enter(int x, int y);// dung de cin o mot toa do nao do
	void Draw_Login(int state);// ve table
	int Login();
	void Print_FlashScreen();
	void Start_System();
	Menu();
	~Menu();
};