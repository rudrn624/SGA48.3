#include <iostream>
#include <conio.h>

using namespace std;

void shuffle(.......)
{
	/////
}

int main(void)
{
	int board[25];

	for (int i = 0; i < 25; i++)
	{
		board[i] = i;
	}
	for (int i = 0; i < 25; i++)
	{
		cout << board[i] << '\t';
		if (i%5 == 5-1)
			cout << endl;
	}

	shuffle(board);

	for (int i = 0; i < 25; i++)
	{
		cout << board[i] << '\t';
		if (i%5 == 5-1)
			cout << endl;
	}

	_getch();
	return 0;
}
