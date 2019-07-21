#include "Date.h"

Date::Date()
{
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);

	m_day = local.tm_mday;
	m_month = local.tm_mon+1;
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
	int d1, m1, y1, d2, m2, y2;

	vector<string> Date1=Tokenizer::Parse(date1,"/");
	d1 = stoi(Date1[0]); m1 = stoi(Date1[1]); y1 = stoi(Date1[2]);

	vector<string> Date2 = Tokenizer::Parse(date2, "/");
	d2 = stoi(Date2[0]); m2 = stoi(Date2[1]); y2 = stoi(Date2[2]);

	if (y2 > y1) return true;
	else if (y2 < y1) return false;
	else if (y2 == y1 && m1 < m2) return true;
	else if (y2 == y1 && m1 > m2) return false;
	else if (y2 == y1 && m1 == m2 && d2 >= d1) return true;
	else if (y2 == y1 && m1 == m2 && d2 < d1) return false;
	return true;

}

bool Date::Compare_Two_Date(const Date& p)
{
	if (p.m_year > m_year) return true;
	else if (p.m_year < m_year) return false;
	else if (p.m_year == m_year && m_month < p.m_month) return true;
	else if (p.m_year == m_year && m_month > p.m_month) return false;
	else if (p.m_year == m_year && m_month == p.m_month && p.m_day >= m_day) return true;
	else if (p.m_year == m_year && m_month == p.m_month && p.m_day < m_day) return false;
	return true;

}

void Date::TimeNow()
{
	struct tm* ptr;
	time_t lt;
	char str[80];

	lt = time(NULL);
	ptr = localtime(&lt);

	m_month = ptr->tm_mon;
	m_day = ptr->tm_mday;
	m_year = ptr->tm_year;
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
	writer << m_day << "-" << m_month << "-" << m_year;
	return writer.str();
}

string Date::ToStringDMonth()
{
	stringstream writer;
	writer << m_month << "-" << m_year;
	return writer.str();
}
