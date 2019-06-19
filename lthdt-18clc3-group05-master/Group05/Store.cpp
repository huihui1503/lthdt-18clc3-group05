#include "Store.h"

Store::Store(const Store& p)
{
	num = p.num;
	for (int i = 0; i < num; i++)
		arrSmartphones[i] = p.arrSmartphones[i];
}

Store::Store()
{
	num = 0;
}



Store::~Store()
{
}

void Store::output(int i)
{
	cout << arrSmartphones[i];
}

Smartphone & Store::operator[](int index)
{
	if (index > this->num || index < this->num) throw "invalid index";
	return this->arrSmartphones[index];
}

void Store::Input_Storage(Smartphone smp) // Nhap vao lich su mua ban
{
	ofstream fout("a");
	Date today;
	string fileName = today.ToString() + ".txt";
	fout.open(fileName);
	if(!fout.is_open())
	{
		return;
	}
	else
	{
		fout << today.ToString() << "," << smp.ToString();
	}
}

void Store::Output_Bill()
{
	int total = 0;
	cout << "Bill of you: " << endl;
	for(int i = 0; i < Bags.size(); i++)
	{
		cout << Bags[i] << endl;
		total += Bags[i].PriceBuy();
	}
	cout << "Total cost you have to pay: " << total;
}

int Store::findSmartphone(string ID)
{
	for (int i = 0; i < num; i++)
		if (arrSmartphones[i].compare_with_id(ID))
			return i;
	return -1;
}

bool Store::AddNewSmartphone_FromFile(string filename)
{
	Smartphone tmp;
	if (tmp.inputFromfile(filename))
	{
		arrSmartphones.push_back(tmp);
		return true;
	}
	return false;
}

void Store::AddNewSmartphone_From_keyboard()
{
	Smartphone tmp;
	cin >> tmp;
	arrSmartphones.push_back(tmp);
}

void Store::AddNewSmartphone_withAttributes(string id, string n, string pb, string ps, string ori, string spec, string sl)
{
	Smartphone tmp;
	tmp.addNewSmartphone(id, n, pb, ps, ori, spec, sl);
	arrSmartphones.push_back(tmp);
}

bool Store::Sell_A_Smartphone(string ID)
{
	int k = findSmartphone(ID);
	if (k<0)
		return false;
	return arrSmartphones[k].Sell_Smartphone();
}

bool Store::Save_Data()
{
	return false;
}

bool Store::Load_Data_from_file(string Filename)
{
	ifstream fin1(Filename);
	if (!fin1.is_open())
		return false;
	string tmp;
	int count = 0;
	
	while (!fin1.eof())
	{
		tmp = fin1.get();
		if (tmp == ".")
			count++;
	}
	fin1.close();
	num = count;
	char tmp1[1000];
	string name;
	string id;
	string ps;
	string pb;
	string ori;
	string spec;
	string sl;
	Smartphone a;
	ifstream fin(Filename);
	for (int i = 0; i < num; i++) {
		fin.getline(tmp1, 1000, ',');            id = string(tmp1);
		fin.getline(tmp1, 1000, ',');            name = string(tmp1);
		fin.getline(tmp1, 1000, ',');       	 pb = string(tmp1);
		fin.getline(tmp1, 1000, ',');       	 ps = string(tmp1);
		fin.getline(tmp1, 1000, ',');		     ori = string(tmp1);
		fin.getline(tmp1, 1000, ',');			 sl = string(tmp1);
		fin.getline(tmp1, 1000, '.');			 spec = string(tmp1);
		fin.ignore();
		AddNewSmartphone_withAttributes(id, name, pb, ps, ori, spec, sl);
	}
	return true;

}

bool Store::Sell_Bags()
{
	string ID = " ";
	cout << "Enter your Smartphone's ID to add to your bags (0 to end of input): ";
	while (!ID.compare("0")) {
		cin >> ID;
		try {
			Bags.push_back(this->arrSmartphones[this->findSmartphone(ID)]);
		}
		catch (const char tmp) {
			cout << tmp;
		}
	}
	cout << "Your bags include: " << endl;
	for (size_t i = 0; i < Bags.size(); i++) {
		cout << Bags[i] << endl;
	}
	cout << "Are you sure you want to pay: (Y: yes, N: no)";
	cin.ignore();
	char c = _getch();
	if (c == 'y' || 'Y') {
		for (size_t i = 0; i < Bags.size(); i++) {
			this->arrSmartphones[i].Sell_Smartphone();

		}
	}
	cout << endl;
	return true;
}

istream& operator>>(istream& is, Store& p)
{
	int num;
	cout << "How many Smartphones? " << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		p.AddNewSmartphone_From_keyboard();
		cout << endl;
	}
	return is;
}

ostream& operator<<(ostream& os, const Store& p)
{
	cout << "this is a list products: " << endl;
	for (int i = 0; i < p.num; i++)
	//	p.output(i);
	return os;
}


bool Store::changeDataSmartPhone(string ID) {
	Smartphone tmp;
	cin >> tmp;
	try {
		this->arrSmartphones[this->findSmartphone(ID)] = tmp;
	}
	catch (const char fail){
		cout << fail;
		return false;
	}
	return true;
}

