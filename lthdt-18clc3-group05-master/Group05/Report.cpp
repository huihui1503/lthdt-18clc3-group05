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
			fin.getline(tmp1, 1000, ','); if (tmp1 == "") { break; }    day = int(tmp1);
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
	if (month1 >= 1 && month2 >= 1 && month1 <= 12 && month2 <= 12)
	{
		if (year1 != year2)
		{
			for (int i = month1; i <= 12; i++)
			{
				stringstream writer; writer << i << "-" << year1 << ".txt";
				string fileName = writer.str();
				if (Load_Data_from_Storage(fileName.c_str()))
				{
					//.....
				}
			}

			for (int i = month2; i <= 12; i++)
			{
				stringstream writer; writer << i << "-" << year2 << ".txt";
				string fileName = writer.str();
				if (Load_Data_from_Storage(fileName.c_str()))
				{
					//.....
				}
			}
		}
		else if (year1 == year2)
		{
			int i1, i2;
			if (month1 <= month2) { i1 = month1; i2 = month2; }
			else if (month2 <= month1) { i1 = month2; i2 = month1; }

			for (; i1 <= i2; i1++)
			{
				stringstream writer; writer << i1 << "-" << year1 << ".txt";
				string fileName = writer.str();
				if (Load_Data_from_Storage(fileName.c_str()))
				{
					//.....
				}
			}
		}
	}
	else return false;
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
	vector<int>temp(m_s.size(),0);
	if (Load_Data_from_Date(month1, year1, month2, year2))
	{
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
		int pos;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] >= max) {
				max = temp[i];
				pos = i;
			}
		}
		cout << "Best seller is: " << endl;
		cout << m_s[pos].ToStringBestSeller() << "with" << max << "stocks" << endl;
	}
	m_s.clear();
	m_day.clear();
	return;
}
