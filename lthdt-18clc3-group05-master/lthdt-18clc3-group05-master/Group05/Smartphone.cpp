#include "Smartphone.h"
int Smartphone::InstanceCount = 0;
//******************************************************* DON'T TOUCH *********************************************************************************************************************************
//____________________________________________________________________________________________________________________________________________________________________________________________________
 
/*++*/string Smartphone::ToStringFile()
{
	stringstream writer;
	writer << ID << "," << Name << "," << Price_b << "," << Price_s << "," << Origin <<","<<StockLevel<<".";
	return writer.str();
}   

/*++*/string Smartphone::ToStringFile_Expand()
{
	stringstream writer;
	writer << ID << "," << Name << "," << Price_b << "," << Price_s << "," << Origin << "," << StockLevel<<","<<Rom <<","<<Ram<<","<<Battery<<","<<Screen << ".";
	return writer.str();


}

/*++*/bool Smartphone::compare_with_name(string Name1)
{
	return Name1 == Name;
}

/*++*/bool Smartphone::compare_with_id(string id)
{
	return ID == id;
}

/*++*/bool Smartphone::Sell_Smartphone()
{
	if (StockLevel == 0)
		return false;
	StockLevel--;
	return true;
}

void Smartphone::Add_Basic_Attributes(string id, string name, string brand, string pb, string ps, string ori, string sl)
{
	ID = id;
	Name = name;
	Brand = brand;
	Price_b = stoi(pb);
	Price_s = stoi(ps);
	Origin = ori;
	StockLevel = stoi(sl);
}

void Smartphone::Add_Advanced_Attributes(string rom, string ram, string battery, string screen)
{
	Rom = rom;
	Ram = ram;
	Battery = battery;
	Screen = screen;
}

/*++*/Smartphone& Smartphone::operator=(const Smartphone& p)
{
	ID = p.ID;
	Name = p.Name;
	Brand = p.Brand;
	Price_b = p.Price_b;
	Price_s = p.Price_s;
	Origin = p.Origin;
	StockLevel = p.StockLevel;
	//----------------------------//
	Rom = p.Rom;
	Ram = p.Ram;
	Battery = p.Battery;
	Screen = p.Screen;
	return *this;
}

/*++*/void Smartphone::output_Basic()
{
	cout << "ID: " << ID << endl;
	cout << "Name: " << Name << endl;
	cout << "Brand: " << Brand << endl;
	cout << "Price : " << Price_b << endl;
	cout << "Origin: " << Origin << endl;
}

/*++*/Smartphone::Smartphone()
{
	ID = "0000001";
	Name = "SamSung S8 Plus";
	Brand = "Samsung";
	Origin = "Korean";
	StockLevel = 100;
	Price_b = 10000000;
	Price_s = 10100000;
	Ram = "0 GB";
	Rom = "0 GB";
	Battery = "0mAh";
	Screen = "0x0 pixels";
	InstanceCount++;
}

/*++*/Smartphone::Smartphone(const Smartphone& other)
{
	ID = other.ID;
	Name = other.Name;
	Brand = other.Brand;
	Price_b = other.Price_b;
	Price_s = other.Price_s;
	Origin = other.Origin;
	StockLevel = other.StockLevel;
	//----------------------------//
	Ram = other.Ram;
	Rom = other.Rom;
	Battery = other.Battery;
	Screen = other.Screen;
	InstanceCount++;

}

/*++*/istream& operator>>(istream& is, Smartphone& p)
{
	char tmp[1000];

	cout << "ID: ";
	gets_s(tmp);
	p.ID = string(tmp);
	cin.ignore();

	cout << "Name: ";
	gets_s(tmp);
	p.Name = string(tmp);
	cin.ignore();

	cout << "Brand: ";
	gets_s(tmp);
	p.Brand = string(tmp);
	cin.ignore();

	cout << "Price buy: ";
	cin >> p.Price_b;

	cout << "Price sell: ";
	cin >> p.Price_s;
	cin.ignore();

	cout << "Origin: ";
	gets_s(tmp);
	p.Origin = string(tmp);
	cin.ignore();

	cout << "Rom: ";
	gets_s(tmp);
	p.Rom = string(tmp);
	cin.ignore();

	cout << "Ram: ";
	gets_s(tmp);
	p.Ram = string(tmp);

	cout << "Battery: ";
	gets_s(tmp);
	p.Battery = string(tmp);
	cin.ignore();

	cout << "Screen: ";
	gets_s(tmp);
	p.Screen = string(tmp);
	return is;
}

/*++*/ostream& operator<<(ostream& os, const Smartphone& p)
{
	cout << "ID: " << p.ID << endl;
	cout << "Name: " << p.Name << endl;
	cout << "Price : " << p.Price_b << endl;
	cout << "Brand: " << p.Brand << endl;
	cout << "Origin: " << p.Origin << endl;
	cout << "Ram: " << p.Ram << endl;
	cout << "Rom: " << p.Rom << endl;
	cout << "Battery: " << p.Battery << endl;
	cout << "Screen: " << p.Screen << endl;
	cout << " ------------------------- -------------------------------------" << endl;
	return os;
}
//_________________________________________________________________________________________________________________________________________________________________________________________________________
//**********************************************************************************************************************************************************************************************************


string Smartphone::ToString()
{
	stringstream writer;
	writer << Price_b << "," << Price_s << "," << Name << "," << ID << "," << Origin << "" << Ram << "," << Rom << "," << Battery << "," << Screen;
	return writer.str();
}

Smartphone::~Smartphone()
{

}
