#include "Date.h"

Date::Date()
{
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);

	m_day = local.tm_mday;
	m_month = local.tm_mon;
	m_year = local.tm_year + 1900;
}

Date::Date(int day, int month, int year)
{
	m_day = day;
	m_month = month;
	m_year = year;
}

Date::Date(const Date&d)
{
	m_day = d.m_day;
	m_month = d.m_month;
	m_year = d.m_year;
}


Date::~Date()
{
}

bool Date::Is_Date_in_Duaration(string date, string begin, string end)
{
	return false;
}

bool Date::Compare_Two_Date(string date1, string date2)
{
	return false;
}

bool Date::isLeapYear(int year)
{
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

bool Date::isValidDate(int day, int month, int year)
{
	if (month > 12 || month < 1)
		return false;
	if (month == 2)
	{
		if (!isLeapYear(year))
		{
			if (day >= 29)
				return false;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8)
		return (day <= 31);
}

string Date::ToString()
{
	stringstream writer;
	writer << m_day << "/" << m_month << "/" << m_year;
	return writer.str();
}
