#ifndef _REPORT_
#define _REPORT_
#include "Tokenizer.h"
#include "Smartphone.h"
#include "Store.h"
#include"Dohoa.h"
class Report
{
private:
	vector<Smartphone> m_s;
	vector<int> m_day;
public:
	bool Load_Data_from_Storage(const char *path);
	bool Load_Data_from_Date(int month1, int year1, int month2, int year2);
public:
	double Calc_Total_Profit(); //In Vector
	double Calc_Total_Stock(); //In Vector
	double Calc_Profit_Follow_Year(int year); //Tinh loi nhuan theo nam(chon nam de tinh)
	double Calc_Profit_Follow_2Month_To_2Year(int month1, int year1, int month2, int year2); //Tinh loi nhuan tu thang nay qua thang khac nam khac
	void find_Best_Seller_In(int month1, int year1, int month2, int year2);
	vector<double> Calc_Profit_Follow_Year_DrawChart(int year); 
	vector<double> Calc_Stock_Follow_Year_DrawChart(int year);
	void Draw_Chart_forA_Year(int year);
	void Draw_Chart_forA_Year_Stocklevel(int year);
	void Save_report(vector<double> months, string year);
};
#endif

