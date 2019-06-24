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
public: // Ham lien quan toi tinh toan
	bool Input_Storage(Smartphone smp);
	bool Output_Bill(double money);
	void Sell_Bags();
	int findSmartphone(string ID);
	bool Sell_A_Smartphone(string ID);
	void Add_To_Bags(const Smartphone& smp);
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
public:
	//Seller Function of Hui
	int Draw_Brand_For_Choice();
public:
	Store(const Store& p);
	Store();
	~Store();
};

