#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Costumer
{
private:
	string id;
	string name;
	double point;
public:
	void Save_Attribute(ofstream&file);
	bool Show_Info(string id, string name);
	string Classify_Member();
public:
	static int signal;
	Costumer(string, string, double);
	Costumer();
	~Costumer();
};

