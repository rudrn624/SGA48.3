#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	Date today;

	today.setYear(2014);
	today.setMonth(4);
	today.setDay(21);

	// 2014/04/21
	today.print();

	_getch();
	return 0;
}
