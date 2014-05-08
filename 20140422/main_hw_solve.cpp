#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Date
{
public :
	// default constructor(기본 생성자)
	//Date()
	//{
	//	year = 0;
	//	month = 1;
	//	day = 1;
	//}
	// copy constructor(복사 생성자)
	Date(const Date& other)
	{
		year = other.year;
		month = other.month;
		day = other.day;
	}
	// constructor overloading(생성자 재정의)
	Date(const int& y = 0, const int& m = 1, const int& d = 1)
	{
		year = y;
		month = m;
		day = d;
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
private :
	int year;
	int month;
	int day;
};

int main(void)
{
	Date today;

	today.print();

	//today.SetYear(2014);
	//today.SetMonth(4);
	//today.SetDay(22);

	//today.print();

	//Date tomorrow = today;
	//tomorrow.AddDay(1);

	//tomorrow.print();

	_getch();
	return 0;
}
