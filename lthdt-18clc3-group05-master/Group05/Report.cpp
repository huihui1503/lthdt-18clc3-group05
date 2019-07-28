#include "Report.h"

bool Report::Load_Data_from_Storage(const char* path)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		return false;
	}
	else
	{
		string id, name, pb, ps, sl; int day;
		Smartphone tmp2;
		char tmp1[1000];
		while (!fin.eof())
		{
			fin.getline(tmp1, 1000, ','); if (tmp1 == "") { break; }    day = stoi(tmp1);
			fin.getline(tmp1, 1000, ',');                               id = string(tmp1);
			fin.getline(tmp1, 1000, ',');                               name = string(tmp1);
			fin.getline(tmp1, 1000, ',');       	                    pb = string(tmp1);
			fin.getline(tmp1, 1000, ',');       	                    ps = string(tmp1);
			fin.getline(tmp1, 1000, '\n');			                    sl = string(tmp1);
			fin.ignore();
			tmp2.Add_Bill_Attributes(id, name, pb, ps, sl);
			m_s.push_back(tmp2);
			m_day.push_back(day);
		}
	}
	fin.close();
	return true;
}

bool Report::Load_Data_from_Date(int month1, int year1, int month2, int year2)
{
	int count = 0;
	if (month1 >= 1 && month2 >= 1 && month1 <= 12 && month2 <= 12)
	{
		int i1, i2;
		if (month1 <= month2) { i1 = month1; i2 = month2; }
		else if (month2 <= month1) { i1 = month2; i2 = month1; }

		if (year1 != year2)
		{
			int j1, j2; if (year1 < year2) { j1 = year1; j2 = year2; }
			else if (year2 < year1) { j1 = year2; j2 = year1; }

			for (int i = i1; i <= 12; i++) //Year1
			{
				stringstream writer; writer << i << "-" << year1 << ".txt";
				string fileName = writer.str();
				if (Load_Data_from_Storage(fileName.c_str()))
				{
					count++;
				}
			}
			for (int j = j1 + 1; j < j2; j++) //Year2 -> Year(n-1)
			{
				for (int i = 1; i <= 12; i++)
				{
					stringstream writer; writer << i << "-" << j << ".txt"; string fileName = writer.str();
					if (Load_Data_from_Storage(fileName.c_str()))
					{
						count++;
					}
				}
			}
			for (int i = 1; i <= i2; i++) //Year(n)
			{
				stringstream writer; writer << i << "-" << year2 << ".txt";
				string fileName = writer.str();
				if (Load_Data_from_Storage(fileName.c_str()))
				{
					count++;
				}
			}
		}
		else if (year1 == year2)
		{
			for (i1; i1 <= i2; i1++)
			{
				stringstream writer; writer << i1 << "-" << year1 << ".txt";
				string fileName = writer.str();
				if (Load_Data_from_Storage(fileName.c_str()))
				{
					count++;
				}
			}
		}
	}
	else return false;
	if (count == 0)
	{
		return false;
	}
	return true;
}

double Report::Calc_Total_Profit()
{
	double sum = 0;
	for (int i = 0; i < m_s.size(); i++)
	{
		sum += m_s[i].Calc_Profit();
	}
	return sum;
}
double Report::Calc_Total_Stock()
{
	double sum = 0;
	for (int i = 0; i < m_s.size(); i++)
	{
		sum += m_s[i].Get_StockLevel();
	}
	return sum;
}

double Report::Calc_Profit_Follow_Year(int year)
{
	double profit = 0;
	for (int i = 1; i <= 12; i++)
	{
		stringstream writer; writer << i << "-" << year << ".txt"; string fileName = writer.str();
		if (Load_Data_from_Storage(fileName.c_str()))
		{
			profit += Calc_Total_Profit();
		}
		m_s.clear();
		m_day.clear();
	}
	return profit;
}

double Report::Calc_Profit_Follow_2Month_To_2Year(int month1, int year1, int month2, int year2)
{
	double profit = 0;
	if (Load_Data_from_Date(month1, year1, month2, year2))
	{
		profit += Calc_Total_Profit();
	}
	m_s.clear();
	m_day.clear();
	return profit;
}

void Report::find_Best_Seller_In(int month1, int year1, int month2, int year2)
{
	if (Load_Data_from_Date(month1, year1, month2, year2) == true)
	{
		vector<int>temp(m_s.size(), 0);
		//Duyet mang
		for (int i = 0; i < m_s.size(); i++)
		{
			for (int j = i; j < m_s.size(); j++)
			{
				if (m_s[j].compare_id_with(m_s[i]))
				{
					temp[i] += m_s[j].Get_StockLevel(); // {1.2,2,3} -> temp ={1,4,2,1} -> Xet cai nao max thoi
				}
			}
		}
		//Tim max
		int max = temp[0];
		int pos = -1;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] >= max) {
				max = temp[i];
				pos = i;
			}
		}
		system("cls");
		if (pos != -1)
		{
			m_s[pos].Print_BestSeller();
			gotoxy(21, 10);
			cout << "Stock buy: " << max;
		}
		else if(pos == -1)
		{
			cout << "Dont have best seller" << endl;
		}
		m_s.clear();
		m_day.clear();
		temp.clear();
	}
	else { system("cls"); cout << "Dont have best seller" << endl; }
	_getch();
	return;
}

vector<double> Report::Calc_Profit_Follow_Year_DrawChart(int year)
{
	vector<double> months = {0,0,0,0,0,0,0,0,0,0,0,0};
	double profit = 0;
	for (int i = 1; i <= 12; i++)
	{
		stringstream writer;writer << i << "-" << year << ".txt"; string fileName = writer.str();
		if (Load_Data_from_Storage(fileName.c_str()))
		{
			months[i-1] = Calc_Total_Profit();
		}
		m_s.clear();
		m_day.clear();
	}
	return months;
}

vector<double> Report::Calc_Stock_Follow_Year_DrawChart(int year)
{
	vector<double> months(12, 0);
	double stock = 0;
	for (int i = 1; i <= 12; i++)
	{
		stringstream writer;writer << i << "-" << year << ".txt"; string fileName = writer.str();
		if (Load_Data_from_Storage(fileName.c_str()))
		{
			for(int j = 0; j < m_s.size(); j++)
			{
				months[i - 1] = Calc_Total_Stock();
			}
		}
		m_s.clear();
		m_day.clear();
	}
	return months;
}

void Report::Draw_Chart_forA_Year(int year)
{
	if (year <= 0)
		return;
	vector<double> Months = Calc_Profit_Follow_Year_DrawChart(year);
	Table_Draw_Chart(Months, year,1);
}

void Report::Draw_Chart_forA_Year_Stocklevel(int year)
{
	if (year <= 0)
		return;
	vector<double> Months = Calc_Stock_Follow_Year_DrawChart(year);
	Table_Draw_Chart(Months, year,0);
	gotoxy(10, 3);
	cout << "(Stocks)" << endl;

}
