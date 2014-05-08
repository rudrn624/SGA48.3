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
};


int main(void)
{
	Date today(2014,4,30);
	Date tomorrow;

	today.print();

	tomorrow = today;
	tomorrow.AddDay(1);

	tomorrow.print();

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
	month = m;
	day = d;
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
	month = m;
}
void Date::SetDay(const int& d)
{
	day = d;
}
void Date::AddDay(const int& d)
{
	day += d;
}
void Date::print(void)
{
	cout << setw(4) << setfill('0') << year << "/";
	cout << setw(2) << setfill('0') << month << "/";
	cout << setw(2) << setfill('0') << day << endl;
}
