#include "Store.h"
//******************************************************* DON'T TOUCH *********************************************************************************************************************************
//____________________________________________________________________________________________________________________________________________________________________________________________________

/*++*/string Store::File_Save_Expand = "Super_Data.txt";

/*++*/Store::Store(const Store& p)
{
	num = p.num;
	for (int i = 0; i < num; i++) {
		arrSmartphones[i] = p.arrSmartphones[i];
		Bags[i] = p.Bags[i];
		Count_Brand[i] = p.Count_Brand[i];
	}
}

/*++*/Store::Store()
{
	num = 0;
}

/*++*/void Store::output_Advanced(int i)
{
	cout << arrSmartphones[i];
}

/*++*/void Store::Display_All_Advanced()
{
	for (int i = 0; i < num; i++) {
		cout << arrSmartphones[i] << endl;
	}
}

/*++*/ostream& operator<<(ostream& os, const Store& p)
{
	vector<Smartphone> arr = p.arrSmartphones;
	for (int i = 0; i < p.num; i++)
		arr[i].output_Basic();
	return os;
}

/*++*/void Store::output_Basic(int i)
{
	arrSmartphones[i].output_Basic();
}

/*++*/void Store::AddNewSmartphone_From_keyboard()
{
	Smartphone tmp;
	cin >> tmp;
	arrSmartphones.push_back(tmp);
}

/*++*/istream& operator>>(istream& is, Store& p)
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

//_________________________________________________________________________________________________________________________________________________________________________________________________________
//**********************************************************************************************************************************************************************************************************


Store::~Store()
{
}

Smartphone& Store::operator[](int index)
{
	if (index >= this->num || index < 0) throw "invalid index";
	return this->arrSmartphones[index];
}

//**********************************************************************TRANSACTION**********************************************************************************************************
bool Store::Input_Storage(Smartphone smp) // Nhap vao lich su mua ban
{
	ofstream fout("a");
	Date today;
	string fileName = today.ToString() + ".txt";
	fout.open(fileName);
	if (!fout.is_open())
	{
		return false;
	}
	else
	{
		fout << today.ToString() << "," << smp.ToStringFile() << endl;
	}
	fout.close();
	return true;
}

bool Store::Output_Bill(double money)
{
	Date now;
	double total = Calc_Total_Cost(Bags);
	ofstream fout;
	string name;

	cout << "Input your name: ";
	cin >> name;
	string nameBill = name + "-" + now.ToString() + ".txt";
	fout.open(nameBill);
	if (!fout.is_open())
	{
		return false;
	}
	else
	{
		fout << "Name: " << name << endl;
		fout << "Date: " << now.ToString() << endl;
		for (size_t i = 0; i < Bags.size(); i++)
		{
			fout << Bags[i] << endl;
		}
		fout << "Total cost you have to pay: " << total << endl;
		fout << "Shop receive from you: " << money << endl;
		fout << "Shop give back you change: " << money - total << endl;
		fout << "Thanks for buying from our shop, see you again";
	}
	fout.close();
	return true;
}

void Store::Add_To_Bags(const Smartphone& smp)
{
	Bags.push_back(smp);
}


void Store::Sell_Bags()
{
	Date now;
	double total = Calc_Total_Cost(Bags);
	double moneyReceive;

	cout << "Bill of you: " << endl;
	for (int i = 0; i < Bags.size(); i++)
	{
		Bags[i].output_Basic();
		cout << "------------------------------" << endl;
	}
	cout << "Total cost you have to pay: " << total << endl;

	cout << "Are you sure you want to pay: (Y: yes, N: no)" << endl;
	cin.ignore();
	char c = _getch();
	if (c == 'y' || 'Y') {
		do
		{
			cout << "Money shop receive from you: ";
			cin >> moneyReceive;
			if (moneyReceive < total)
			{
				cout << "Sorry, you do not pay enough, please pay more: ";
			}
		} while (moneyReceive < total);
		cout << "Shop give back you change: " << moneyReceive - total << endl;

		cout << "Do you want to print bill?: (Y: Yes, N: No)";
		cin.ignore();
		char c = _getch();
		if (c == 'y' || 'Y') {
			if (Output_Bill(moneyReceive))
			{
				cout << "Print bill successful" << endl;
			}
			else cout << "Print bill fail" << endl;
		}
	}
	else return;
}

/*++*/int Store::findSmartphone(string ID)
{
	for (int i = 0; i < num; i++)
		if (arrSmartphones[i].compare_with_id(ID))
			return i;
	return -1;
}

/*++*/bool Store::Sell_A_Smartphone(string ID)
{
	int k = findSmartphone(ID);
	if (k < 0)
		return false;
	return arrSmartphones[k].Sell_Smartphone();
}

bool Store::Input_New_Data_from_file(string Filename, string info)
{
	ifstream fin1(Filename);
	if (!fin1.is_open()) {
		return false;
	}
	string tmp;

	int count = 0;

	while (!fin1.eof())
	{
		tmp = fin1.get();
		if (tmp == ".")
			count++;
	}
	fin1.close();
	int k = num;
	num += count;
	char tmp1[1000];
	string name;
	string id;
	string ps;
	string pb;
	string ori;
	string sl;
	Smartphone a;
	ifstream fin(Filename);
	for (int i = k; i < num; i++) {
		fin.getline(tmp1, 1000, ',');            id = string(tmp1);
		fin.getline(tmp1, 1000, ',');            name = string(tmp1);
		fin.getline(tmp1, 1000, ',');       	 pb = string(tmp1);
		fin.getline(tmp1, 1000, ',');       	 ps = string(tmp1);
		fin.getline(tmp1, 1000, ',');		     ori = string(tmp1);
		fin.getline(tmp1, 1000, '.');			 sl = string(tmp1);
		fin.ignore();
		vector<string> v = Tokenizer::Parse(name, " ");
		a.Add_Basic_Attributes(id, name, v[0], pb, ps, ori, sl);
		arrSmartphones.push_back(a);
	}
	fin.close();
	ifstream fin2(info);
	if (!fin2.is_open())
	{
		throw "load info fail";
		return false;
	}
	string rom;
	string ram;
	string battery;
	string screen;
	for (int i = k; i < num; i++)
	{
		fin2.getline(tmp1, 1000, ',');           name = string(tmp1);
		fin2.getline(tmp1, 1000, ',');           id = string(tmp1);
		fin2.getline(tmp1, 1000, ',');            ram = string(tmp1);
		fin2.getline(tmp1, 1000, ',');            rom = string(tmp1);
		fin2.getline(tmp1, 1000, ',');       	 battery = string(tmp1);
		fin2.getline(tmp1, 1000, '.');       	 screen = string(tmp1);
		fin2.ignore();
		arrSmartphones[i].Add_Advanced_Attributes(ram, rom, battery, screen);
	}
	fin2.close();
	return true;
}

bool Store::changeDataSmartPhone(string ID) {
	Smartphone tmp;
	cin >> tmp;
	try {
		this->arrSmartphones[this->findSmartphone(ID)] = tmp;
	}
	catch (const char fail) {
		cout << fail;
		return false;
	}
	return true;
}

bool Store::Save_All_Data()
{
	ofstream fout(File_Save_Expand);
	for (int i = 0; i < num; i++)
		fout << arrSmartphones[i].ToStringFile_Expand() << endl;
	fout.close();
	return true;

}

bool Store::Load_Data_from_file()
{
	ifstream fin(File_Save_Expand);
	if (!fin.is_open())
		return false;
	string tmp;
	int count = 0;
	while (!fin.eof())
	{
		tmp = fin.get();
		if (tmp == ".")
			count++;
	}
	int k = num;
	num += count;
	fin.beg();
	string name;
	string id;
	string ps;
	string pb;
	string brand;
	string ori;
	string sl;
	string rom;
	string ram;
	string battery;
	string screen;
	Smartphone a;
	char tmp1[1000];
	for (int i = k; i < num; i++)
	{
		fin.getline(tmp1, 1000, ',');            id = string(tmp1);
		fin.getline(tmp1, 1000, ',');            name = string(tmp1);
		fin.getline(tmp1, 1000, ',');       	 brand = string(tmp1);
		fin.getline(tmp1, 1000, ',');       	 pb = string(tmp1);
		fin.getline(tmp1, 1000, ',');       	 ps = string(tmp1);
		fin.getline(tmp1, 1000, ',');		     ori = string(tmp1);
		fin.getline(tmp1, 1000, ',');			 sl = string(tmp1);
		fin.getline(tmp1, 1000, ',');            ram = string(tmp1);
		fin.getline(tmp1, 1000, ',');            rom = string(tmp1);
		fin.getline(tmp1, 1000, ',');       	 battery = string(tmp1);
		fin.getline(tmp1, 1000, '.');       	 screen = string(tmp1);
		fin.ignore();
		a.Add_Basic_Attributes(id, name, brand, pb, ps, ori, sl);
		a.Add_Advanced_Attributes(ram, rom, battery, screen);
		arrSmartphones.push_back(a);
	}

	return true;
}


// Seller Function of Hui
int Store::Draw_Brand_For_Choice()
{
	int x = 8;
	int y = 5;
	for (int i = 1; i <= Count_Brand.size(); i++)
	{
		Draw_Box(x, y, 5, 15, White);
		textcolor(DarkCyan);
		gotoxy(x + 4, y + 3); cout << Count_Brand[i - 1];
		if (i % 3 == 0)
		{
			x = 8;
			y += 10;
		}
		else
		{
			x += 25;
		}
	}
	return Count_Brand.size();
}