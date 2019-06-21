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
	int num;
	vector<Smartphone> arrSmartphones;
	vector<Smartphone> Bags;
	vector<string> Count_Brand;
public:
	void output(int i);
	friend istream& operator>>(istream& is, Store& p);
	friend ostream& operator<<(ostream& os, const Store& p);
	Smartphone & operator[](int index);
	int getNum() { return num; }
public: // Xuat hoa don
	void Input_Storage(Smartphone smp);
	void Output_Bill();
public: // Xu li nghiep vu
	int  findSmartphone(string ID);
	bool AddNewSmartphone_FromFile(string filename);
	void AddNewSmartphone_From_keyboard();
	void AddNewSmartphone_withAttributes(string id, string n, string pb, string ps,string ori, string sl);
	bool changeDataSmartPhone(string ID);
	bool Sell_A_Smartphone(string ID);
	bool Save_Data_Info();
	bool Load_Data_from_file(string Filename);
	bool Load_Info_From_file(string Filename);
	bool Sell_Bags(); // tham so gio hang se duoc khai bao trong methods
	//Seller Function of Hui
	int Draw_Brand_For_Choice();
public:
	Store(const Store& p);
	Store();
	~Store();
};

