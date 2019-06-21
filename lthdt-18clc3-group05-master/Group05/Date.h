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
public:
	static bool isLeapYear(int);
	static bool isValidDate(int, int, int);
	string ToString();
};

