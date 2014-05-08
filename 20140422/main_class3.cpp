#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Date
{
public :
	// copy constructor(복사 생성자)
	Date(const Date& other)
	{
		year = other.year;
		month = other.month;
		day = other.day;
	}
	// constructor overloading(생성자 재정의)
	Date(const int& y = 0, const int& m = 1, const int& d = 1)
		: year(y), month(m), day(d), cmonth(12)
	{
		//year = y;
		//month = m;
		//day = d;
	}
	// default destructor(기본 소멸자)
	~Date()
	{
	}
	void SetYear(const int& y)
	{
		year = y;
	}
	void SetMonth(const int& m)
	{
		month = m;
	}
	void SetDay(const int& d)
	{
		day = d;
	}
	void AddDay(const int& d)
	{
		day += d;
	}
	void print(void)
	{
		cout << setw(4) << setfill('0') << year << "/";
		cout << setw(2) << setfill('0') << month << "/";
		cout << setw(2) << setfill('0') << day << endl;

		//printf("%04d/%02d/%02d", year, month, day);
	}
	friend ostream& operator << (ostream& os, const Date& obj)
	{
		os << setw(4) << setfill('0') << obj.year << "/";
		os << setw(2) << setfill('0') << obj.month << "/";
		os << setw(2) << setfill('0') << obj.day;

		return os;
	}
private :
	int year;
	int month;
	int day;

	const int cmonth;

	int cday[12];
};

int main(void)
{
	Date today(2014,4,22);

	cout << today << endl;

	_getch();
	return 0;
}
