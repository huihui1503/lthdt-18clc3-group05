#include "Costumer.h"

int Costumer::signal = 0;// check data

bool Costumer::Show_Info(string id, string name)
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

string Costumer::Classify_Member()
{
	if (this->point < 300) return "Normal";
	if (this->point < 500) return "Loyal";
	else return "VIP";
}

void Costumer::Save_Attribute(ofstream&file)
{
	file << this->id << "," << this->name << "," << this->point << "\n";
}

Costumer::Costumer(string id, string name, double point)
{
	this->id = id;
	this->name = name;
	this->point = point;
}

Costumer::Costumer()
{
	this->id = "0829994335";
	this->name = "Thai Hoang Huy";
	this->point = 0;
}

Costumer::~Costumer()
{

}
