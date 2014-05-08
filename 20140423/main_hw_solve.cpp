#include <iostream>
#include <conio.h>
#include <iomanip> // io manipulate

using namespace std;

class Date
{
public :
	// copy constructor(복사 생성자)
	Date(const Date& other);
	// constructor overloading(생성자 재정의)
	Date(const int& y = 0, const int& m = 1, const int& d = 1);
	// default destructor(기본 소멸자)
	~Date();
	Date& operator =(const Date& other);
	void SetYear(const int& y);
	void SetMonth(const int& m);
	void SetDay(const int& d);
	void AddYear(const int& y);
	void AddMonth(const int& m);
	void AddDay(const int& d);
	void print(void);
private :
	int year;
	int month;
	int day;
	static const int cMonth; // 정적변수,
	static const int cDay[12];
};

const int Date::cMonth = 12;
const int Date::cDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(void)
{
	Date today(2014,1,30);
	Date tomorrow;

	for (int i = -400; i < 400; i++)
	{
		tomorrow = today;
		tomorrow.AddDay(i);
		tomorrow.print();

		if (i%100 == 0)
			_getch();
	}


	_getch();
	return 0;
}

// copy constructor(복사 생성자)
Date::Date(const Date& other)
{
	*this = other;
	//year = other.year;
	//month = other.month;
	//day = other.day;
}
// constructor overloading(생성자 재정의)
Date::Date(const int& y/*=0*/, const int& m/*=1*/, const int& d/*=1*/)
{
	year = y;
	month = m-1;
	day = d-1;
}
// default destructor(기본 소멸자)
Date::~Date()
{
}
// assignment operator overloading(대입 연산자 재정의)
Date& Date::operator =(const Date& other)
{
	year = other.year;
	month = other.month;
	day = other.day;

	return *this;
}
void Date::SetYear(const int& y)
{
	year = y;
}
void Date::SetMonth(const int& m)
{
	month = m-1;
}
void Date::SetDay(const int& d)
{
	day = d-1;
}
void Date::AddYear(const int& y)
{
	year += y;
}
void Date::AddMonth(const int& m)
{
	if (month + m >= cMonth)
	{
		AddYear(1);
		int temp = month + m - cMonth;
		month = 0;
		AddMonth(temp);
	}
	else if (month + m < 0)
	{
		AddYear(-1);
		int temp = month + m + cMonth;
		month = 0;
		AddMonth(temp);
	}
	else
	{
		month += m;
	}
}
void Date::AddDay(const int& d)
{
	if (day + d >= cDay[month])
	{
		int temp = day + d - cDay[month];
		AddMonth(1);
		day = 0;
		AddDay(temp);
	}
	else if (day + d < 0)
	{
		AddMonth(-1);
		int temp = day + d + cDay[month];
		day = 0;
		AddDay(temp);
	}
	else
	{
		day += d;
	}
}
void Date::print(void)
{
	cout << setw(4) << setfill('0') << year << "/";
	cout << setw(2) << setfill('0') << (month+1) << "/";
	cout << setw(2) << setfill('0') << (day+1) << endl;
}
