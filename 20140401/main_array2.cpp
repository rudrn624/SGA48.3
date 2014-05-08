#include <iostream>
#include <conio.h>
#include <cstdlib> // rand, srand
#include <ctime> // time

using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	const int size = 5;
	int puzzle[size*size];

	// 초기화
	for (int i = 0; i < size*size-1; i++)
	{
		puzzle[i] = i+1;
	}
	puzzle[size*size-1] = 0;

	// shuffle
	for (int i = size*size-2; i > 0; i--)
	{
		int index = rand()%i;

		int tmp = puzzle[i];
		puzzle[i] = puzzle[index];
		puzzle[index] = tmp;
	}

	// 게임시작...
	while (true)
	{
		// 입력처리

		// 그리기
		system("cls"); // 화면 지우기
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << puzzle[i*size + j] << '\t';
			}
			cout << endl;
		}

	}

	_getch();
	return 0;
}
