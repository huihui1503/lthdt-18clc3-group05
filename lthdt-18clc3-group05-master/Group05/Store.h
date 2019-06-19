#pragma once
#include<vector>
#include "Date.h"
#include"Smartphone.h"
class Store
{
private:
	int num;
	vector<Smartphone> arrSmartphones;
	vector<Smartphone> Bags;
	static string Smartphones_Data;
public:
	void output(int i);
	friend istream& operator>>(istream& is, Store& p);
	friend ostream& operator<<(ostream& os, const Store& p);
	Smartphone & operator[](int index);
public: // Xuat hoa don
	void Input_Storage(Smartphone smp);
	void Output_Bill();
public: // Xu li nghiep vu
	int  findSmartphone(string ID);
	bool AddNewSmartphone_FromFile(string filename);
	void AddNewSmartphone_From_keyboard();
	void AddNewSmartphone_withAttributes(string id, string n,string b, string pb, string ps, string ori,string sl);
	bool changeAllDataSmartPhone(string ID);
	void changeAnAttrinbute(string ID, int k);
	bool Sell_A_Smartphone(string ID);
	bool Save_Data();
	bool Load_Data_from_file(string Filename);
	bool Sell_Bags(); // tham so gio hang se duoc khai bao trong methods
public:
	Store(const Store& p);
	Store();
	~Store();
};

