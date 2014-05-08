#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5 - y - 1; x++)
		{
			cout << ' ';
		}
		for (int x = 0; x < y + 1; x++)
		{
			cout << '#';
		}
		for (int x = 0; x < y + 1; x++)
		{
			cout << '#';
		}
		for (int x = 0; x < 5 - y - 1; x++)
		{
			cout << ' ';
		}
		cout << endl;
	}
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < y; x++)
		{
			cout << ' ';
		}
		for (int x = 0; x < 5 - y; x++)
		{
			cout << '#';
		}
		for (int x = 0; x < 5 - y; x++)
		{
			cout << '#';
		}
		for (int x = 0; x < y; x++)
		{
			cout << ' ';
		}
		cout << endl;
	}

	_getch();
	return 0;
}
