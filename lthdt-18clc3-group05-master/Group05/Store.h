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
	static string FILE_SAVE_BILL;
	static string File_Save_Expand;
	static int num;
	vector<Smartphone> arrSmartphones;
	vector<Smartphone> Bags; //dat bien tam
public:
	Smartphone & operator[](int index);
	int getNum() { return num; }
public: // Xuat hoa don
	bool Input_Storage(Smartphone& smp); //Nhap vao kho
	bool Output_Bill(string name, double change);
	void Save_bill_by_month();
public:
	//MASTER
	friend void Calc_StockAnd_TotalPrice(int& stock, int& total, const vector<Smartphone>& arr);
	void AddNewSmartphone_From_keyboard();
	bool changeDataSmartPhone(string ID);
	bool Save_All_Data();
	bool Load_Data_from_file();
	bool Input_New_Data_from_file(string Filename, string info);
	// DISPLAY
	void output_Basic(int i);
	friend ostream& operator<<(ostream& os, const Store& p);
	void output_Advanced(int i);
	void Display_All_Advanced();
	void Display_All_Basic();
	void Display_All_Calc_Cost();
	friend istream& operator>>(istream& is, Store& p);
public: // Xu li nghiep vu
	int  findSmartphone(vector<Smartphone>& temp, string ID);
	bool Sell_A_Smartphone(string ID);
	bool Sell_Bags(); // tham so gio hang se duoc khai bao trong methods
	void Add_To_Bags(Smartphone&temp);
	bool Decrease_Quantity(string ID);
	bool Reset_Bags();
	bool Print_Bill_On_Console();
	void addNewSmartphone(Smartphone tmp);
	//Seller Function of Hui
	int Draw_Brand_For_Choice();
	void Draw_Phone_of_Brand(string brand, vector<Smartphone>&temp);
	void Effect_of_Move(int pos,vector<Smartphone>temp);
	vector<string> Count_Brand;
	static double Sum;// total money in bag
	int Get_Size_Of_Bags()
	{
		if (Bags.empty()) return 0;
		return Bags.size();
	}
	void Draw_Bag();
	//Filter
	bool Find_Smartphone_Filter(vector<Smartphone>& temp,int condition[]);
public:
	Store(const Store& p);
	Store();
	~Store();
};
bool isFile_inSystem(string path);

