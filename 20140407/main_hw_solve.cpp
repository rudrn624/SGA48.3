#include <iostream>
#include <conio.h>
#include <cstdlib> // rand, srand
#include <ctime> // time, clock
#include <windows.h>

using namespace std;

void zero()
{
	HANDLE hCon = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD z = {0,0};
	::SetConsoleCursorPosition(hCon, z);
}

int main(void)
{
	srand((unsigned)time(NULL));

	const int width = 70;
	const int height = 20;
	char prev = ' ';
	char current = 'A';
	char board[width*height];
	int pos[width*height];

	// �ʱ�ȭ
	// ������ �ʱ�ȭ.
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board[i*width + j] = prev;
		}
	}
	// ��ġ�� �ʱ�ȭ
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

	clock_t st = clock();
	clock_t dt = 0;
	clock_t speed = 1400; // 1��/s

	int index = 0;
	// ����...
	while (true)
	{
		// �Է�ó��
		if (_kbhit())
		{
			int key = _getch();
			if (key == 0x1B) // ESC
				break;
		}

		// ������Ʈ
		// 1000ms : 1s = dt(ms) : x(s)
		// 1*dt = 1000*x => x = 1*dt/1000,
		if (speed*dt/1000 >= 1)
		{
			int count = speed*dt/1000;

			dt = 0;

			for (int i = 0; i < count; i++)
			{
				if (board[pos[index]] == prev)
					board[pos[index]] = current;
				else
					board[pos[index]] = prev;
				index++;

				// ȭ���� current ���ڷ� �� á�ٸ�...
				if (index == width*height)
				{
					// ���� ä�� ���ڴ� ���� ���ڷ�...
					prev = current;
					// ���� ä�� ���ڴ� ���ο� ���ڷ�...
					current = char(current + 1);
					// ä�� ���ڰ� 'Z'���... �ٽ� 'A'���� �����Ѵ�.
					if (prev == 'Z')
						current = 'A';

					// �ٲ�� ��ġ�� �Ź� �ٸ��� �ϰ� �ʹٸ�... shuffle.
					for (int i = width*height-1; i > 0; i--)
					{
						int index = rand()%i;

						int tmp = pos[i];
						pos[i] = pos[index];
						pos[index] = tmp;
					}

					index = 0;
				} // if (index == width*height)
			} // for (int i = 0; i < count; i++)
		} // if ()

		// �׸���
		//system("cls");
		zero();
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				cout << board[y*width + x];
			}
			cout << endl;
		}

		dt += clock() - st;
		st = clock();
	}

	cout << "press any key to exit program.." << endl;
	_getch();
	return 0;
}