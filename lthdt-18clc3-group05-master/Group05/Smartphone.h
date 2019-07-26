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
	string getbrand() { return Brand; }
	double PriceBuy() {return Price_b;}
	double PriceSell() { return Price_s; }
	string Get_Name() { return Name; }
public:
	//OPERATOR 
	Smartphone& operator = (const Smartphone& p);
	friend ostream& operator<<(ostream& os, const Smartphone& p);
	friend double Calc_Total_Cost(const vector<Smartphone>& p);
	friend int Calc_Total_Stocklevel(const vector<Smartphone>& p);
	double Calc_Profit(); //New
	friend istream& operator>>(istream& is, Smartphone& p);
	vector<Smartphone>& operator -(vector<Smartphone>& p);
	void output_Basic();
	//DISPLAY IN TABLE
	void Display_Expand(int i);
	void Display_Basic(int i);
	void Display_Calc_Cost(int i);
public:	
	// METHOD
	string ToStringBill(); //Fix
	string ToStringBestSeller(); //New
	string ToString();
	string ToStringFile();
	string ToStringFile_Expand();
	bool compare_with_name(string name1);
	bool compare_with_id(string id);
	bool compare_id_with(Smartphone s); //New
	bool Sell_Smartphone();
	void Add_Basic_Attributes(string id, string name, string brand, string pb, string ps, string ori, string sl);
	void Add_Advanced_Attributes(string rom, string ram, string battery, string screen);
	void Add_Bill_Attributes(string id, string name, string pb, string ps, string sl);//New
public:
	void COUT_NAME(int y, int left, int right, int color);
	bool compare_with_brand(string brand);
	bool Check_On_Console(int x, int y);
public:
	void Set_StockLevel(int value)
	{
		StockLevel = value;
	}

	string Get_ID()
	{
		return ID;
	}

	void Increase_StockLevel(int value)
	{
		this->StockLevel += value;
	}

	bool Decrease_StockLevel(int value)
	{
		if (StockLevel-value >= 0) StockLevel -= value;
		else return false;
		return true;
	}

	int Get_StockLevel()
	{
		return StockLevel;
	}
	void Add_to_Sum(double&Sum)
	{
		Sum += Price_s;
	}
	void Remove_from_Sum(double& Sum)
	{
		Sum -= Price_s;
	}
//advanced filter
public:
	bool Check_Condition_Filter(int condition[]);
//Customer
	void Discount_Price_Follow_Point(double point);
public:
	Smartphone();
	Smartphone(string id, string name, string origin, double price_b, double price_s, string ram, string rom, string battery, string screen, int stock);
	Smartphone(const Smartphone& other);
	~Smartphone();
};

