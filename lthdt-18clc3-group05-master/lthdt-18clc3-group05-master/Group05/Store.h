#pragma once
#include "Date.h"
#include"Smartphone.h"
#include"Dohoa.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Store
{
private:
	static string File_Save_Expand;
	static int num;
	vector<Smartphone> arrSmartphones;
	vector<Smartphone> Bags;
	vector<string> Count_Brand;
public:
	Smartphone & operator[](int index);
	int getNum() { return num; }
public: // Xuat hoa don
	void Input_Storage(Smartphone smp);
	void Output_Bill();
public:
	//MASTER
	void output_Basic(int i);
	friend ostream& operator<<(ostream& os, const Store& p);
	void output_Advanced(int i);
	void Display_All_Advanced();
	friend istream& operator>>(istream& is, Store& p);
	void AddNewSmartphone_From_keyboard();
	bool changeDataSmartPhone(string ID);
	bool Save_All_Data();
	bool Load_Data_from_file();
	bool Input_New_Data_from_file(string Filename, string info);
public: // Xu li nghiep vu
	int  findSmartphone(string ID);
	bool Sell_A_Smartphone(string ID);
	bool Sell_Bags(); // tham so gio hang se duoc khai bao trong methods
	//Seller Function of Hui
	int Draw_Brand_For_Choice();
public:
	Store(const Store& p);
	Store();
	~Store();
};

