#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int a = 0;

	cout << a << endl;
	cout << ++a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << "====================" << endl;

	a = 0;
	cout << a << endl;
	cout << --a << endl;
	cout << a-- << endl;
	cout << a << endl;

	_getch();
	return 0;
}