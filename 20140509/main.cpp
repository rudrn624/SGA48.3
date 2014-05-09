#include <iostream>
#include <conio.h>
#include "Matrix.h"

using namespace std;

int MyStrCmp(const char* lhs, const char* rhs)
{
	int i = 0;

	while (lhs[i] == rhs[i])
	{
		if (lhs[i] == '\0')
			return 0;
		i++;
	}
	if (lhs[i] > rhs[i])
		return 1;

	return -1;
}

int main(void)
{
	// 주석 추가.
	Matrix a, b;

	a["one"] = 5;

	cout << a << endl;

	a = 5;

	cout << a << endl;

	cout << ++a << endl;

	cout << a++ << endl;
	cout << a << endl;

	_getch();
	return 0;
}