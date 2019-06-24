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
	//ATTRIBUTES
	string ID;
	string Name;
	string Brand;
	string Origin;
	int StockLevel;// so luong san pham
	double Price_b;//buy
	double Price_s;//sell
	string Ram;
	string Rom;
	string Battery;
	string Screen;
	static int InstanceCount;
public:
	double PriceBuy() {return Price_b;}
public:
	//OPERATOR 
	Smartphone& operator = (const Smartphone& p);
	friend ostream& operator<<(ostream& os, const Smartphone& p);
	friend double Calc_Total_Cost(const vector<Smartphone>& p);
	friend istream& operator>>(istream& is, Smartphone& p);
	void output_Basic();
public:	
	// METHOD
	string ToString();
	string ToStringFile();
	string ToStringFile_Expand();
	bool compare_with_name(string name1);
	bool compare_with_id(string id);
	bool Sell_Smartphone();
	void Add_Basic_Attributes(string id, string name, string brand, string pb, string ps, string ori, string sl);
	void Add_Advanced_Attributes(string rom, string ram, string battery, string screen);
public:
	Smartphone();
	Smartphone(const Smartphone& other);
	~Smartphone();
};

