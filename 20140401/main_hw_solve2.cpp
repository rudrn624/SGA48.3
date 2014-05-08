#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int r = 10;

	for (int y = 0; y <= 20; y++)
	{
		for (int x = 0; x <= 70; x++)
		{
			bool A = ((x-2*r)*(x-2*r) + 4*(y-r)*(y-r) <= 4*r*r);

			if (A)
				cout << '@';
			else
				cout << ' ';
		}
		cout << endl;
	}


	_getch();
	return 0;
}

