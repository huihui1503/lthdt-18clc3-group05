#include "Customer.h"
#include "Dohoa.h"

int Customer::signal = 0;// check data

bool Customer::check_id_name(string name, string id)
{
	return this->name == name || this->id == id;
}

bool Customer::Show_Info(string id, string name)
{
	if (this->id == id || this->name == name)
	{
		cout << "ID: " << this->id<<endl;
		cout << "Name: " << this->name<<endl;
		cout << "Point: "; printf_s("%.f", this->point);
		cout << endl;
		cout << "Memmber: " << this->Classify_Member();
		return true;
	}
	return false;
}

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


bool Customer::Show_tmp_data(int namex, int namey)
{
	gotoxy(namex, namey);
	cout << name;
	return true;
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
