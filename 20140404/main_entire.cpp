#include <iostream>
#include <conio.h>
#include <cstdlib> // rand, srand
#include <ctime> // time

using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	const int width = 20;
	const int height = 10;
	const char blank = ' ';
	const char mark = '@';
	char board[width*height];
	int pos[width*height];

	// 초기화
	// 보드판 초기화.
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board[i*width + j] = blank;
		}
	}
	// 위치값 초기화
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pos[i*width + j] = i*width + j;
		}
	}

	// shuffle
	for (int i = width*height-1; i > 0; i--)
	{
		int index = rand()%i;

		int tmp = pos[i];
		pos[i] = pos[index];
		pos[index] = tmp;
	}

	int index = 0;
	// 시작...
	while (true)
	{
		// 업데이트
		if (board[pos[index]] == blank)
			board[pos[index]] = mark;
		else
			board[pos[index]] = blank;
		index++;
		if (index == width*height)
			index = 0;

		// 그리기
		system("cls");
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				cout << board[y*width + x];
			}
			cout << endl;
		}
	}

	_getch();
	return 0;
}