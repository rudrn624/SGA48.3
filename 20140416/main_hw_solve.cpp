#include <iostream>
#include <conio.h>

using namespace std;

// 연산틀...
void shuffle(int* arr, int arrsize)
{
	cout << "shuffle func start" << endl;
	cout << arr << endl;
	cout << &arr << endl;

	for (int i = arrsize-1; i > 0; i--)
	{
		int index = rand()%i;

		int tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
	cout << "shuffle func end" << endl;
}

int main(void)
{
	int board[100];
	// int * const 

	cout << sizeof(board)/sizeof(int) << endl;

	for (int i = 0; i < 25; i++)
	{
		board[i] = i;
	}
	//for (int i = 0; i < 25; i++)
	//{
	//	cout << board[i] << '\t';
	//	if (i%5 == 5-1)
	//		cout << endl;
	//}

	cout << board << endl;
	shuffle(board, sizeof(board)/sizeof(int));
	cout << board << endl;

	//for (int i = 0; i < 25; i++)
	//{
	//	cout << board[i] << '\t';
	//	if (i%5 == 5-1)
	//		cout << endl;
	//}

	_getch();
	return 0;
}
