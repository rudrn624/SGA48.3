#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << (9-i) << " x " << (9-j) << " = " << (9-i)*(9-j) << endl;
		}
		cout << "===========================" << endl;
	}

	_getch();
	return 0;
}