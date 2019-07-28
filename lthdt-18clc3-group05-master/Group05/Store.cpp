#include "Store.h"
double Store::Sum = 0;

//******************************************************* DON'T TOUCH *********************************************************************************************************************************
//____________________________________________________________________________________________________________________________________________________________________________________________________

/*++*/string Store::File_Save_Expand = "Super_Data.txt";

/*++*/string Store::FILE_SAVE_BILL = "purchase_history.txt";

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
	Table_Expand(num);
	for (int i = 0; i < 2 * num; i += 2) {
		arrSmartphones[i / 2].Display_Expand(i);
	}
}
void Store::Display_All_Calc_Cost(int& pos)
{
	pos = 11 + 2 * Bags.size();
	Table_Calc_Cost(Bags.size());
	for (int i = 0; i < 2 * Bags.size(); i += 2) {
		Bags[i / 2].Display_Calc_Cost(i);
	}
	gotoxy(157, pos - 5);
	printf("%10.f", Calc_Total_Cost(Bags));
	gotoxy(140, pos - 5);
	printf("%5d", Calc_Total_Stocklevel(Bags));
}

void Store::Display_All_Basic()
{
	Table_Basic(num);
	for (int i = 0; i < 2 * num; i += 2) {
		arrSmartphones[i / 2].Display_Basic(i);
	}
}


void Calc_StockAnd_TotalPrice(int& stock, int& total, const vector<Smartphone>& arr)
{
	stock = 0, total = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		//
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

/*++*/int Store::findSmartphone(vector<Smartphone>& temp, string ID)
{
	if (temp.empty()) return -1;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].compare_with_id(ID))
			return i;
	}
	return -1;
}

/*++*/bool Store::Sell_A_Smartphone(string ID)
{
	int k = findSmartphone(arrSmartphones, ID);
	if (k < 0) return false;
	bool check = arrSmartphones[k].Sell_Smartphone();
	if (check)
	{
		Add_To_Bags(arrSmartphones[k]);
		arrSmartphones[k].Add_to_Sum(Sum);
	}
	return check;
}

/*++*/void Store::AddNewSmartphone_From_keyboard()
{
	Smartphone tmp;
	cin >> tmp;
	arrSmartphones.push_back(tmp);
}

/*++*/bool Store::Decrease_Quantity(string ID)
{
	int k = findSmartphone(Bags, ID);
	if (k >= 0)
	{
		if (Bags[k].Decrease_StockLevel(1))
		{
			int pos = findSmartphone(arrSmartphones, ID);
			arrSmartphones[pos].Increase_StockLevel(1);
			arrSmartphones[pos].Remove_from_Sum(Sum);
			return true;
		}
	}
	return false;
}

/*++*/void Store::Add_To_Bags(Smartphone& temp)
{
	int k = findSmartphone(Bags, temp.Get_ID());
	if (k < 0 || Bags.empty())
	{
		Bags.push_back(temp);
		Bags[Bags.size() - 1].Set_StockLevel(1);
	}
	else
	{
		Bags[k].Increase_StockLevel(1);
	}
}

/*++*/bool Store::Reset_Bags()
{
	if (Bags.empty()) return true;
	for (auto i = 0; i < Bags.size(); i++)
	{
		int k = findSmartphone(arrSmartphones, Bags[i].Get_ID());
		arrSmartphones[k].Increase_StockLevel(Bags[i].Get_StockLevel());
	}
	Bags.clear();
	Sum = 0;
	return true;
}

/*++*/bool Store::Print_Bill_On_Console()
{
	textcolor(White);
	int x = 84;
	int y = 5;
	for (auto i = 0; i < Bags.size(); i++)
	{
		if (Bags[i].Check_On_Console(x, y))
		{
			y += 1;
		}
	}
	gotoxy(x, y); cout << "---------------------------------";
	textcolor(Red);
	gotoxy(x + 15, y + 1); cout << "Total: "; printf("%.f", Sum);
	return true;
}

void Store::addNewSmartphone(Smartphone tmp)
{
	num++;
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

bool isFile_inSystem(string path)
{
	ifstream fin(path);
	if (!fin.is_open())
	{
		fin.close();
		return false;
	}
	fin.close();
	return true;
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
/*Dont touch*/
bool Store::Input_Storage() // Nhap vao lich su mua ban
{
	Date today;
	string fileName = today.ToStringDMonth() + ".txt";
	ofstream fout(fileName, ios::app);
	if (!fout.is_open())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < Bags.size(); i++)
		{
			fout << today.Day() << "," << Bags[i].ToStringBill() << endl;
		}
	}
	fout.close();
	return true;
}
/*Dont touch*/
bool Store::Output_Bill(string ID,double money)
{
	if (ID == "0") return false;
	Date today;
	string fileName = ID + ".txt";
	ofstream fout(fileName, ios::app);
	if (!fout.is_open())
	{
		return false;
	}
	else
	{
		fout << today.ToString() << ":" << endl;
		for (int i = 0; i < Bags.size(); i++)
		{
			fout << Bags[i].ToStringBill();
			fout << endl;
		}
	}
	fout.close();
	return true;
}

void Store::Save_bill_by_month()
{
	Date a;
}
/*Dont touch*/
bool Store::Sell_Bags(Customer&temp)
{
	int x = 9;
	int y = 8;
	textcolor(Red);
	gotoxy(25, 6); cout << "Customer Information";
	Draw_Box(72, 4, 16, 40, 48);
	textcolor(White);
	if (!temp.check_id_name("temp", "0"))
	{
		gotoxy(x, y); cout << "+ Name: "<<temp.Get_Name();
		gotoxy(x, y + 1); cout << "+ Phone number: "<<temp.Get_ID();
		gotoxy(x, y + 2); cout << "+ Point: "<<temp.Get_Point()<<" - "<<temp.Classify_Member();
	}
	else
	{
		gotoxy(x, y); cout << "+ Name: Unknown";
		gotoxy(x, y + 1); cout << "+ Phone number: Unknown";
		gotoxy(x, y + 2); cout << "+ Point: Unknown";
	}
	gotoxy(x - 3, y + 4); cout << "----------------------------------------------------------";
	textcolor(Red); gotoxy(33, y + 6); cout << "BILL";
	textcolor(White);
	int i = 0;
	double total = Calc_Total_Cost(Bags);
	for (; i < Bags.size(); i++)
	{
		if (Bags[i].Get_StockLevel() > 0)
		{
			gotoxy(x, y + 8 + i); cout << Bags[i].Get_Name();
			gotoxy(x + 35, y + 8 + i); printf("%.f", Bags[i].PriceSell()); cout << " VND x " << Bags[i].Get_StockLevel();
			Bags[i].Discount_Price_Follow_Point(temp.Get_Point());
		}
	}
	double total2 = Calc_Total_Cost(Bags);
	if (total != total2)
	{
		gotoxy(x, y + 8 + i); cout << "Discount";
		gotoxy(x + 35, y + 8 + i); cout << "- "; printf("%.f", total - total2); cout << " VND";
		i++;
	}
	i += 1;
	gotoxy(x + 28, y + 8 + i); cout << "-------------------------";
	i += 1;
	textcolor(Red);
	gotoxy(x + 28, y + 8 + i); cout << "Total: ";
	textcolor(White);
	gotoxy(x + 35, y + 8 + i); printf("%.f", total2); cout << " VND";
	Draw_Box(5, 4, 16+i, 60, 25);// big box

	textcolor(Red);
	gotoxy(77, 6); cout << "Receive";
	Draw_Box(76, 7, 1, 32, White);
	textcolor(Red);
	gotoxy(77, 10); cout << "Charge";
	Draw_Box(76, 11, 1, 32, White);
	string money = "0";
	while (double(stof(money))<total2)
	{
		gotoxy(78, 8);
		textcolor(White);
		money = Enter(78, 8);
		if (money == "") return true;
		if (double(stof(money)) < total2)
		{
			textcolor(Red);
			gotoxy(51, 2); cout << "Money is not sufficient!!!!";
			gotoxy(78, 8); cout << "                      ";
		}
	}
	gotoxy(78, 12); printf("%.f", double(stof(money)) - total2);
	Draw_Box(82, 15, 3, 20, Red);
	textcolor(White);
	gotoxy(90, 17); cout << "SELL";
	char key = '.';
	//string name;
	//long money; int pos=2;

	//display_all_calc_cost(pos);
	while (int(key) != KEY_ESC)
	{
		key = _getch();
		if (int(key) == KEY_ENTER)
		{
			Output_Bill(temp.Get_ID(), double(stof(money)));
			Input_Storage();
			Bags.clear();
			break;
		}
	}
	return true;
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
		if (tmp == "\n")
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
		fin.getline(tmp1, 1000, '\n');			 sl = string(tmp1);
		//fin.ignore();
		vector<string> v = Tokenizer::Parse(name, " ");
		/////  Restricted area ////////
		if (Count_Brand.size() == 0) Count_Brand.push_back(v[0]);
		else
		{
			for (int i = 0; i < Count_Brand.size(); i++)\
			{
				if (v[0] == Count_Brand[i]) break;
				if (i == Count_Brand.size() - 1) Count_Brand.push_back(v[0]);
			}
		}
		//////////////////////////////////////////////////////////
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
		fin2.getline(tmp1, 1000, '\n');       	 screen = string(tmp1);
		fin2.ignore();
		arrSmartphones[i].Add_Advanced_Attributes(rom, ram, battery, screen);
	}
	fin2.close();
	return true;
}

bool Store::changeDataSmartPhone(string ID) {
	Smartphone tmp;
	cin >> tmp;
	try {
		this->arrSmartphones[this->findSmartphone(arrSmartphones, ID)] = tmp;
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
	ifstream fin1(File_Save_Expand);
	if (!fin1.is_open())
		return false;
	int count = 0;
	string tmp;
	while (!fin1.eof())
	{
		tmp = fin1.get();
		if (tmp == "\n")
			count++;
	}
	fin1.close();
	int k = num;
	num += count;
	fin1.close();
	ifstream fin(File_Save_Expand);
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
		fin.getline(tmp1, 1000, '\n');       	 screen = string(tmp1);
	//	fin.ignore();
		vector<string> v = Tokenizer::Parse(name, " ");
		/////  Restricted area ////////
		if (Count_Brand.size() == 0) Count_Brand.push_back(v[0]);
		else
		{
			for (int i = 0; i < Count_Brand.size(); i++)\
			{
				if (v[0] == Count_Brand[i]) break;
				if (i == Count_Brand.size() - 1) Count_Brand.push_back(v[0]);
			}
		}
		//////////////////////////////////////////////////////////

		a.Add_Basic_Attributes(id, name, brand, pb, ps, ori, sl);
		a.Add_Advanced_Attributes(rom, ram, battery, screen);
		arrSmartphones.push_back(a);
	}

	return true;
}


// Seller Function of Hui
void Store::Draw_Phone_of_Brand(string brand, vector<Smartphone>& temp)
{
	int y = 5;
	for (int i = 0; i < arrSmartphones.size(); i++)
	{
		if (arrSmartphones[i].compare_with_brand(brand))
		{
			arrSmartphones[i].COUT_NAME(y, 1, 80, White);
			temp.push_back(arrSmartphones[i]);
			y += 5;
		}
	}
}

int Store::Draw_Brand_For_Choice()
{
	int x = 8;
	int y = 5;
	for (int i = 1; i <= Count_Brand.size() + 3; i++)
	{
		Draw_Box(x, y, 5, 15, White);
		textcolor(DarkCyan);
		gotoxy(x + 4, y + 3);
		if (i <= Count_Brand.size()) cout << Count_Brand[i - 1];
		else if (i == Count_Brand.size() + 1)
		{
			textcolor(Pink);
			cout << "Filter";
		}
		else if (i == Count_Brand.size() + 2)
		{
			textcolor(Pink);
			cout << "Customer";
		}
		else {
			textcolor(Pink);
			cout << "Find";
		}
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

void Store::Effect_of_Move(int pos, vector<Smartphone>temp)
{
	temp[pos].COUT_NAME(pos * 5 + 5, 1, 80, Cyan);
	textcolor(Cyan);
	gotoxy(1, pos * 5 + 5);
	cout << "   |";
	gotoxy(1, pos * 5 + 6);
	cout << "---+---";
	gotoxy(1, pos * 5 + 7);
	cout << "   |";
	gotoxy(73, pos * 5 + 6);
	cout << "=======";
}

void Store::Draw_Bag()
{
	for (int i = 0; i <= 40; i++)
	{
		gotoxy(80, 1 + i);
		cout << "|$|";
	}
	textcolor(Red);
	gotoxy(97, 2); cout << "Your bag";
	if (Bags.empty()) return;
	textcolor(White);
	int x = 84;
	int y = 5;
	for (auto i = 0; i < Bags.size(); i++)
	{
		if (Bags[i].Check_On_Console(x, y))
		{
			y += 1;
		}
	}
	gotoxy(x, y); cout << "---------------------------------";
	textcolor(Red);
	gotoxy(x + 15, y + 1); cout << "Total: "; printf("%.f", Sum);
}

//Advance Filter
bool Store::Find_Smartphone_Filter(vector<Smartphone>& temp, int condition[])
{
	for (int i = 0; i < arrSmartphones.size(); i++)
	{
		if (arrSmartphones[i].Check_Condition_Filter(condition) && (condition[0] == 0 || arrSmartphones[i].getbrand() == Count_Brand[condition[0] - 1]))
		{
			temp.push_back(arrSmartphones[i]);
		}
	}
	return temp.empty();
}