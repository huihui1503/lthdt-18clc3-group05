#include "Costumer.h"
#include "Dohoa.h"

int Customer::signal = 0;// check data


string Customer::Classify_Member()
{
	if (this->point < 300) return "Normal";
	if (this->point < 500) return "Loyal";
	else return "VIP";
}

void Customer::Save_Attribute(ofstream&file)
{
	file << this->id << "," << this->name << "," << this->point << "\n";
}

bool Customer::Show_tmp_data(int idx, int idy, int namex, int namey)
{
	gotoxy(idx, idy);
	cout << id;
	gotoxy(namex, namey);
	cout << name;
}

Customer::Customer(string id, string name, double point)
{
	this->id = id;
	this->name = name;
	this->point = point;
}

Customer::Customer()
{
	this->id = "0829994335";
	this->name = "Thai Hoang Huy";
	this->point = 0;
}

Customer::~Customer()
{

}
