#pragma once
#include<iostream>
#include<string>
#include"Store.h"
#include"Dohoa.h"
#include"Customer.h"
#include"Report.h"
#include <io.h>
#include <fcntl.h>
using namespace std;
class Store;
class Menu
{
private:
	Store main_data;
	string path_customer = "Customer.txt";
	vector<Customer> data;
	Report report;
//Customer
public:
	void Load_Data_Customer();
	void Save_Data_Customer();
	void Move_in_Customer();
	void Create_New_Customer();
	bool Check_Existing_Costumer(string name,string id);
	int Enter_Customer();
	bool Create_Hitory(int index);
//Report
public:
	void Report_Interface();
	void Menu_Best_Seller(int status);
	void Menu_Profit_Year();
	void Menu_Stock_Year();
public:
	void Seller_Move();
	void Master_Move();
	void Choice_For_Sell(string chosen_brand);
	//Filter
	void Advanced_Filter();
	string Show_Option_In_Filter( int y,int current, int& value);
	int Move_in_Filter( int current,int y, vector<string>content);
	void Show_Result_Filter(int array[]);
	int add_Edit(string brand);
	void About_Us();
	void Exit();
	void Draw_Login(int state);// ve table
	int Login();
	void Print_FlashScreen();
	void Start_System();
	void edit(int Index);
	void New();
	void Add_Edit_customer(); 
	void Edit_customer(int index);
	void find_BaseOn_ID_or_Name();
	string ChoiceToFind(int x, int y);
	Menu();
	~Menu();
};