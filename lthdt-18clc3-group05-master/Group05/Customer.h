#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Customer

{
private:
	string id;
	string name;
	double point;
public:
	void Save_Attribute(ofstream&file);
	bool Show_tmp_data(int namex, int namey);
	string Classify_Member();
	bool check_id_name(string name, string id);
	bool Show_Info(string id, string name);
public:
	static int signal;
	Customer(string, string, double);
	Customer();
	~Customer();
};
