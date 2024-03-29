#include "Smartphone.h"
#include"Dohoa.h"
int Smartphone::InstanceCount = 0;
//******************************************************* DON'T TOUCH *********************************************************************************************************************************
//____________________________________________________________________________________________________________________________________________________________________________________________________
 
/*++*/string Smartphone::ToStringFile()
{
	stringstream writer;
	char priceb[100], prices[100];
	_itoa_s(Price_b, priceb, 10);
	_itoa_s(Price_s, prices, 10);
	writer <<"ID: "<< ID << "\nName: " << Name << "\nPrice buy: " << priceb << "\nPrice sell: " << prices << "\nOrigin: " << Origin;
	return writer.str();
}   

/*++*/string Smartphone::ToStringFile_Expand()
{
	stringstream writer;
	char priceb[100], prices[100];
	_itoa_s(Price_b, priceb, 10);
	_itoa_s(Price_s, prices, 10);
	writer << ID << "," << Name <<","<<Brand<< "," << priceb << "," << prices << "," << Origin << "," << StockLevel << "," << Rom << "," << Ram << "," << Battery << "," << Screen;
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

bool Smartphone::compare_id_with(Smartphone s)
{
	return ID == s.ID;
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

void Smartphone::Add_Bill_Attributes(string id, string name, string pb, string ps, string sl)
{
	ID = id;
	Name = name;
	Price_b = stoi(pb);
	Price_s = stoi(ps);
	StockLevel = stoi(sl);
}

double Calc_Total_Cost(const vector<Smartphone>& p)
{
	double total = 0;
	for (int i = 0; i < p.size(); i++)
		total += p[i].Price_s*p[i].StockLevel;
	return total;
}

int Calc_Total_Stocklevel(const vector<Smartphone>& p)
{
	int total = 0;
	for (int i = 0; i < p.size(); i++)
		total += p[i].StockLevel;
	return total;

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

double Smartphone::Calc_Profit()
{
	return StockLevel*(Price_s-Price_b);
}

vector<Smartphone>& Smartphone::operator-(vector<Smartphone>& p)
{
	for (int i = 0; i < p.size(); i++)
	{
		if (ID == p[i].ID) {
			p[i].StockLevel--;
		}
	}
	return p;
}

/*++*/void Smartphone::output_Basic()
{
	cout << "ID: " << ID << endl;
	cout << "Name:  " << Name << endl;
	cout << "Brand: " << Brand << endl;
	cout << "Price : " << Price_b << endl;
	cout << "Origin: " << Origin << endl;
}

void Smartphone::Display_Expand(int i)
{
	gotoxy(8, 6+i);
	cout <<i/2 +1 ;

	gotoxy(15, 6+i);
	cout << ID;

	gotoxy(35, 6+i);
	cout << Brand;

	gotoxy(50,6+i);
	cout << Name;

	gotoxy(90, 6+i);
	cout << Price_s;

	gotoxy(110, 6+i);
	cout << Origin;

	gotoxy(129, 6+i);
	cout << Ram;

	gotoxy(144, 6+i);
	cout << Rom;

	gotoxy(157, 6+i);
	cout << Battery;

	gotoxy(170, 6+i);
	cout << Screen;

}

void Smartphone::Display_Basic(int i)
{
	gotoxy(8, 6 + i);
	cout << i / 2 + 1;

	gotoxy(15, 6 + i);
	cout << ID;

	gotoxy(35, 6 + i);
	cout << Brand;

	gotoxy(50, 6 + i);
	cout << Name;

	gotoxy(90, 6 + i);
	cout << Price_s;

	gotoxy(110, 6 + i);
	cout << Origin;

}

void Smartphone::Display_Calc_Cost(int i)
{
	gotoxy(8, 6 + i);
	cout << i / 2 + 1;

	gotoxy(15, 6 + i);
	cout << ID;

	gotoxy(35, 6 + i);
	cout << Brand;

	gotoxy(50, 6 + i);
	cout << Name;

	gotoxy(90, 6 + i);
	printf("%10.f", Price_s);

	gotoxy(110, 6 + i);
	cout << Origin;

	gotoxy(129, 6 + i);
	cout << Ram+"/"+Rom;

	gotoxy(144, 6 + i);
	cout << StockLevel;

	gotoxy(157, 6 + i);
	printf("%10.f",StockLevel*Price_s);
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

Smartphone::Smartphone(string id, string name, string origin, double price_b, double price_s, string ram, string rom, string battery, string screen, int stock)
{
	ID = id;
	Name = name;
	Origin = origin;
	Price_b = price_b;
	Price_s = price_s;
	Ram = ram;
	Rom = rom;
	Battery = battery;
	Screen = screen;
	vector<string> tmp = Tokenizer::Parse(name, " ");
	if (tmp.size() == (size_t)0) Brand = name;
	else Brand = tmp[0];
	StockLevel = stock;
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


string Smartphone::ToStringBill()
{
	stringstream writer;
	
	writer << ID << "," << Name << "," << (long)Price_b << "," << (long)Price_s << "," << StockLevel;

	return writer.str();
}

void Smartphone::Print_BestSeller()
{
	gotoxy(50, 1);
	cout << "Best Seller: ";
	Draw_Box(20, 3, 9, 80, White);
	
	gotoxy(21, 4);
	cout << "ID: " << ID;
	gotoxy(21, 5);
	cout << "Name: " << Name;
	gotoxy(21, 6);
	cout << "Brand: " << Brand;
	gotoxy(21, 7);
	cout << "Origin: " << Origin;
	gotoxy(21, 8);
	cout << "Price buy: " << (long long)Price_b;
	gotoxy(21, 9);
	cout << "Price sell: " << (long long)Price_s;
}

string Smartphone::ToString()
{
	stringstream writer;
	char priceb[100], prices[100];
	_itoa_s(Price_b, priceb, 10);
	_itoa_s(Price_s, prices, 10);
	writer << ID << "," << Name << "," << Origin << "," << priceb << "," << prices << ","  << Ram << "," << Rom << "," << Battery << "," << Screen << "," << StockLevel;
	return writer.str();
}
Smartphone::~Smartphone()
{

}

// FUNCTION OF HUI
void Smartphone::COUT_NAME(int y,int left,int right,int color)
{
	textcolor(color);
	int standard = (right - left)/2+left;
	gotoxy(standard - Name.size() / 2, y);
	cout << Name;
	textcolor(White);
	gotoxy(standard - 5, y + 1);
	char  prices[100];
	_itoa_s(Price_s, prices, 10);

	cout << "Price: " << prices;
	gotoxy(standard - 5, y + 2);
	cout << "Quantity: " << StockLevel;
}

bool Smartphone::compare_with_brand(string brand)
{
	return Brand == brand;
}

bool Smartphone::Check_On_Console(int x,int y)
{
	if (StockLevel > 0)
	{
		gotoxy(x, y); cout << ID;
		gotoxy(x + 20, y);  printf("%.f", Price_s);cout << " X " << StockLevel;
		return true;
	}
	return false;
}

bool Smartphone::Check_Condition_Filter(int condition[])
{
	if (condition[1] == 1)
	{
		if (this->Price_b > double(6000000)) return false;
	}
	if (condition[1] == 2)
	{
		if (this->Price_b <= double(6000000)|| this->Price_b >= double(15000000)) return false;
	}
	if (condition[1] == 3)
	{
		if (this->Price_b < double(15000000)) return false;
	}
	//check ram
	int temp=0;
	vector<string> edit;
	if (this->Ram[Ram.size() - 2] == 'G')
	{
		edit = Tokenizer::Parse(Ram, "G");
		temp = stoi(edit[0]);
	}
	else if(this->Ram[Ram.size() - 2] == 'T')
	{
		edit = Tokenizer::Parse(Ram, "T");
		temp = stoi(edit[0])*1000;
	}
	if (condition[2] == 1)
	{
		if (temp > 4) return false;
	}
	if (condition[2] == 2)
	{
		if (temp <= 4||temp>=10) return false;
	}
	if (condition[2] == 3)
	{
		if (temp < 10) return false;

	}
	temp = 0;
	edit.clear();
	if (this->Rom[Rom.size() - 2] == 'G')
	{
		edit = Tokenizer::Parse(Rom, "G");
		temp = stoi(edit[0]);
	}
	else if (this->Rom[Rom.size() - 2] == 'T')
	{
		edit = Tokenizer::Parse(Rom, "T");
		temp = stoi(edit[0]) * 1000;
	}
	if (condition[3] == 1)
	{
		if (temp != 32) return false;
	}
	if (condition[3] == 2)
	{
		if (temp !=64 ) return false;
	}
	if (condition[3]==3)
	{
		if (temp !=128) return false;
	}
	if (condition[3] == 4)
	{
		if (temp <= 128) return false;
	}
	temp = 0;
	edit.clear();
	edit = Tokenizer::Parse(Ram, " ");
	temp = stoi(edit[0]);
	if (condition[4] == 1)
	{
		if (temp > 3500) return false;
	}
	if (condition[4] == 2)
	{
		if (temp <= 3500 || temp >= 5000) return false;
	}
	if (condition[4] == 3)
	{
		if (temp < 5000) return false;
	}
	return true;
}

void Smartphone::Discount_Price_Follow_Point(double point)
{
	if (point<double(300)) return;
	if (point<double(500))
	{
		this->Price_s -= this->Price_s / 100 * 1;
	}
	else
	{
		this->Price_s -= this->Price_s / 100 * 2;
	}
}