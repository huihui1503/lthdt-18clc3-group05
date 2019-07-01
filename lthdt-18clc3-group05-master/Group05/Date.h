#pragma once
#include <string>
#include <time.h>
#include <sstream>
using namespace std;
class Date
{
private:
	int m_year, m_month, m_day;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	~Date();
public:
	int Day() { return m_day; }
	int Month() { return m_month; }
	int Year() { return m_year; }
	bool Is_Date_in_Duaration(string date, string begin, string end);
	bool Compare_Two_Date(string date1, string date2);
public:
	static bool isLeapYear(int);
	static bool isValidDate(int, int, int);
	string ToString();
};

