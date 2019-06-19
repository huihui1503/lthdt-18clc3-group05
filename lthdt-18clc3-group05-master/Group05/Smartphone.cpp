#include "Smartphone.h"
int Smartphone::InstanceCount = 0;

string Smartphone::ToString()
{
	stringstream writer;
	writer << Price_b << "," << Price_s << "," << Name << "," << ID << "," << Origin << "," << Specification;
	return writer.str();
}


bool Smartphone::compare_with_name(string Name1)
{
	return Name1 == Name;
}

bool Smartphone::compare_with_id(string id)
{
	return ID == id;
}

void Smartphone::addNewSmartphone(string id, string n, string pb, string ps, string ori, string spec, string sl)
{
	ID = id;
	Name = n;
	Price_b = stoi(pb);
	Price_s = stoi(ps);
	Origin = ori;
	Specification = spec;
	StockLevel = stoi(sl);
}

bool Smartphone::Sell_Smartphone()
{
	if (StockLevel == 0)
		return false;
	StockLevel--;
	return true;
}

Smartphone& Smartphone::operator=(const Smartphone& p)
{
	Price_b = p.Price_b;
	Price_s = p.Price_s;
	Name = p.Name;
	ID = p.ID;
	Specification = p.Specification;
	StockLevel = p.StockLevel;
	Origin = p.Origin;
	return *this;
}

bool Smartphone::inputFromfile(string fileName)
{
	string Name = fileName + ".txt";
	ifstream fin(Name);
	if (!fin.is_open())
		return false;
	string no;
	getline(fin, no, ',');
	Name = no;
	getline(fin, no, ',');
	ID = no;
	getline(fin, no, ',');
	Price_b = stoi(no);
	getline(fin, no, ',');
	Price_s = stoi(no);
	getline(fin, no, ',');
	Origin=no;
	return true;
}

Smartphone::Smartphone()
{
	Price_b = 10000000;
	Price_s = 10100000;
	ID = "0000001";
	StockLevel = 100;
	Name = "SamSung S8 Plus";
	Specification = "SamSung_S8Plus.txt";
	Origin = "Korean";
	InstanceCount++;
}

Smartphone::Smartphone(const Smartphone& other)
{
	Price_b = other.Price_b;
	Name = other.Name;
	ID = other.ID;
	Price_s = other.Price_s;
	Specification = other.Specification;
	StockLevel = other.StockLevel;
	Origin = other.Origin;
	InstanceCount++;
}

Smartphone::~Smartphone()
{
	
}

ostream& operator<<(ostream& os, const Smartphone& p)
{
	cout << "     product " << p.ID << endl;
	cout << "Name: " << p.Name << endl;
	cout << "ID: " << p.ID << endl;
	cout << "Price : " << p.Price_b << endl;
	cout << "Origin: " << p.Origin << endl;
	cout << " ------------------------- -------------------------------------" << endl;
	return os;
}

istream& operator>>(istream& is, Smartphone& p)
{
	char tmp[1000];
	cout << "ENTER NEW PRODUCT: " << endl;
	cout << "Name: ";
	cin.ignore();
	gets_s(tmp);
	p.Name = string(tmp);

	cout << "ID: ";
	gets_s(tmp);
	p.ID = string(tmp);

	cout << "Price buy: ";
	cin >> p.Price_b;

	cout << "Price sell: ";
	cin >> p.Price_s;
	cin.ignore();

	cout << "Origin: ";
	gets_s(tmp);
	p.Origin = string(tmp);
	return is;
}