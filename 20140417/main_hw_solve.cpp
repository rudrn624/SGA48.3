#include <iostream>
#include <conio.h>

using namespace std;

int f(int n)
{
	if (n == 1)
	{
		cout << n << " => ";
		return 1;
	}

	cout << n << ' ';
	if (n%2 == 0)
	{
		return f(n/2) + 1;
	}
	else
	{
		return f(3*n+1) + 1;
	}
}

// collatz
int main(void)
{
	for (int i = 1; i < 100; i++)
	{
		cout << i << " : ";
		cout << f(i) << endl;
	}

	_getch();
	return 0;
}