#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int from;
	int to;
	int sum = 0;

	cout << "������ں��� : ";
	cin >> from;
	cout << "������ڱ��� : ";
	cin >> to;


	for (int i = from; i <= to; i++)
	{
		sum = sum + i;
	}

	cout << from << "~" << to << " => " << sum << endl;

	_getch();
	return 0;
}
