#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	for (A ; B; C)
		D;


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << i << ", " << j << endl;

			if (j == 3)
				continue;
				//break;
		}
		cout << "========================" << endl;
	}

	_getch();
	return 0;
}
