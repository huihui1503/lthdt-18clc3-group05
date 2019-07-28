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

void Customer::Display_Data_index(int idx, int idy, int namex, int namey, int pointx, int pointy, const char *memberlogo, int memx, int memy)
{
	if (idx > -1 && idy > -1) {
		gotoxy(idx, idy);
		cout << id;
	}
	if (namex > -1 && namey > -1) {
		gotoxy(namex, namey);
		cout << name;
	}
	if (pointx > -1 && pointy > -1) {
		gotoxy(pointx, pointy);
		cout << point;
	}
	if (memx > -1 && memy > -1) {
		ifstream fin(memberlogo);
		if (!fin.is_open()) return;
		char tmp[1000];
		fin.getline(tmp, 1000, 'eof');
		int i = 0;
		gotoxy(memx, memy);
		while (tmp[i] != '\0') {
			if (tmp[i] == '\n') {
				cout << tmp[i];
				gotoxy(memx, memy);
				memy++;
			}
			else cout << tmp[i];
			i++;
		}
	}
}

string Customer::ToString()
{
	stringstream name;
	name << this->id << "," << this->name << "," << this->point;
	return name.str();
}

string Customer::Classify_Member()
{
	if (this->point < 300) return "Normal";
	if (this->point < 500) return "Loyal";
	else return "VIP";
}

void Customer::Save_Attribute(ofstream&file)
{
	file << this->id << "," << this->name << "," << this->point;
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
