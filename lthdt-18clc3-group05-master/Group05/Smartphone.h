#pragma once
#include<iostream>
using namespace std;
#include<sstream>
#include<fstream>
#include<conio.h>
#include<string>
class Smartphone{
private:
	double Price_b;//buy
	double Price_s;//sell
	string Name;
	string ID;
	string Origin;
	string Specification; // thong so ky thuat (file name)
	int StockLevel;// so luong san pham
	static int InstanceCount;
public:
	string ToString();
	bool compare_with_name(string name1);
	bool compare_with_id(string id);
	void addNewSmartphone(string id, string n, string pb, string ps, string ori, string spec, string sl);
	//static Smartphone* Parse(string line, string operator);
	bool Sell_Smartphone();
	Smartphone& operator = (const Smartphone& p);
	
public:
	bool inputFromfile(string filename);
	friend ostream& operator<<(ostream& os, const Smartphone& p);
	friend istream& operator>>(istream& is, Smartphone& p);
public:
	Smartphone();
	Smartphone(const Smartphone& other);
	~Smartphone();
};

