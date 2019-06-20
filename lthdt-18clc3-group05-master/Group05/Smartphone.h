#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<conio.h>
#include<string>
#include<vector>
#include"Tokenizer.h"
using namespace std;
class Smartphone{
private:
	double Price_b;//buy
	double Price_s;//sell
	string Name;
	string ID;
	string Origin;
	int StockLevel;// so luong san pham
	static int InstanceCount;
public:
	double PriceBuy() {return Price_b;}
	string brand;
public:
	string ToString();
	bool compare_with_name(string name1);
	bool compare_with_id(string id);
	void addNewSmartphone(string id, string n, string pb, string ps, string ori, string sl);
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

