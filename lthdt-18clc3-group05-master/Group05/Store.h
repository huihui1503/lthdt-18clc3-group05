#pragma once
#include<vector>
#include"Smartphone.h"
class Store
{
private:
	int num;
	vector<Smartphone> arrSmartphones;
public:
	void output(int i);
	friend istream& operator>>(istream& is, Store& p);
	friend ostream& operator<<(ostream& os, const Store& p);
	Smartphone & operator[](int index);
public:
	int  findSmartphone(string ID);
	bool AddNewSmartphone_FromFile(string filename);
	void AddNewSmartphone_From_keyboard();
	void AddNewSmartphone_withAttributes(string id, string n, string pb, string ps, string ori, string spec, string sl);
	bool changeDataSmartPhone(string ID);
	bool Sell_A_Smartphone(string ID);
	bool Save_Data();
	bool Load_Data_from_file(string Filename);
	bool Sell_Bags(); // tham so gio hang se duoc khai bao trong methods
public:
	Store(const Store& p);
	Store();
	~Store();
};

