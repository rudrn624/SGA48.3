#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void zero()
{
	HANDLE hCon = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD z = {0,0};
	::SetConsoleCursorPosition(hCon, z);
}

enum key_id
{
	ESCAPE = 0x1B,
	SPECIAL = 0xE0,
	UP = 0x48,
	DOWN = 0x50,
	LEFT = 0x4B,
	RIGHT = 0x4D,
};

enum direction_id
{
	UP_DIR,
	DOWN_DIR,
	LEFT_DIR,
	RIGHT_DIR,
};

// 뱀게임
int main(void)
{
	//while (true)
	//{
	//	int key = _getch();
	//	cout << hex << key << endl;
	//
	//}

	//return 0;

	srand((unsigned)time(NULL));

	const int width = 70;
	const int height = 20;
	const char blank = ' ';
	const char mark = '@';
	const char meat = '$';
	const char border = '#';
	char board[width*height];
	int meat_pos[width*height];
	int meat_pos_index = 0;
	int snake_position = (height/2)*width + width/2;
	int eat_count = 0;
	int direction = UP_DIR;

	// 초기화
	for (int i = 0; i < width*height; i++)
	{
		board[i] = blank;
	}

	for (int i = 0; i < width*height; i++)
	{
		meat_pos[i] = i;
	}

	// 먹이 위치 섞기
	for (int i = width*height - 1; i > 0; i--)
	{
		int index = rand()%i;

		int tmp = meat_pos[i];
		meat_pos[i] = meat_pos[index];
		meat_pos[index] = tmp;
	}

	clock_t dt = 0;
	clock_t st = clock();

	// 게임 시작
	while (true)
	{
		// 입력처리
		if (_kbhit())
		{
			int key = _getch();
			if (key == ESCAPE)
			{
				break;
			}
			else if (key == SPECIAL)
			{
				key = _getch();
				if (key == UP)
				{
					if (snake_position - width < width)
						continue;

					snake_position -= width;
				}
				else if (key == DOWN)
				{
					if (snake_position + width >= height*width - width)
						continue;

					snake_position += width;
				}
				else if (key == LEFT)
				{
					if ((snake_position - 1)%width == 0)
						continue;

					snake_position -= 1;
				}
				else if (key == RIGHT)
				{
					if ((snake_position + 1)%width == width-1)
						continue;

					snake_position += 1;
				}
			}
		}

		// 업데이트
		if (dt >= 1000)
		{
			if (direction == UP_DIR)
			{
				snake_position -= width;
			}

			dt -= 1000;
		}

		if (snake_position == meat_pos[meat_pos_index])
		{
			do {
				meat_pos_index++;
				if (meat_pos_index == width*height)
				{
					meat_pos_index = 0;
					for (int i = width*height - 1; i > 0; i--)
					{
						int index = rand()%i;

						int tmp = meat_pos[i];
						meat_pos[i] = meat_pos[index];
						meat_pos[index] = tmp;
					}
				}

				if (meat_pos[meat_pos_index] == snake_position ||
					meat_pos[meat_pos_index] < width ||
					meat_pos[meat_pos_index] >= height*width - width ||
					meat_pos[meat_pos_index]%width == 0 || 
					meat_pos[meat_pos_index]%width == width-1)
				{
					meat_pos_index++;
				}
				else
				{
					break;
				}
			} while (true);
		}

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if ((x + y*width) == snake_position)
					board[(x + y*width)] = mark;
				else if (x == 0 || x == width-1 || y == 0 || y == height-1)
					board[(x + y*width)] = border;
				else if (meat_pos[meat_pos_index] == (x + y*width))
					board[(x + y*width)] = meat;
				else
					board[(x + y*width)] = blank;
			}
		}
		

		// 그리기
		zero();
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				cout << board[x + y*width];
			}
			cout << endl;
		}
		cout << "먹은 갯수 : " << eat_count << endl;

		dt += clock() - st;
		st = clock();
	}

	_getch();
	return 0;
}