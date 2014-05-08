#include <iostream>
#include <conio.h>
#include <cstdlib> // rand, srand
#include <ctime> // time

using namespace std;

int main(void)
{
	//while (true)
	//{
	//	int key = _getch();

	//	cout << hex << key << endl;
	//}

	//return 0;

	srand((unsigned)time(NULL));

	const int size = 3;
	int puzzle[size*size];
	int position = size*size-1;
	bool bExit = false; // 종료조건.

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
	while (!bExit)
	{
		// 입력처리
		if (_kbhit())
		{
			int key = _getch();
			if (key == 0x1B)
			{
				bExit = true;
				continue;
			}
			else if (key == 'W' || key == 'w')
			{
				if (position < size)
					continue;

				int tmp = puzzle[position];
				puzzle[position] = puzzle[position - size];
				puzzle[position - size] = tmp;

				position = position - size;
			}
			else if (key == 'A' || key == 'a')
			{
				if (position%size == 0)
					continue;

				int tmp = puzzle[position];
				puzzle[position] = puzzle[position - 1];
				puzzle[position - 1] = tmp;

				position = position - 1;
			}
			else if (key == 'S' || key == 's')
			{
				if (position >= size*size - size)
					continue;

				int tmp = puzzle[position];
				puzzle[position] = puzzle[position + size];
				puzzle[position + size] = tmp;

				position = position + size;
			}
			else if (key == 'D' || key == 'd')
			{
				if (position%size == size - 1)
					continue;

				int tmp = puzzle[position];
				puzzle[position] = puzzle[position + 1];
				puzzle[position + 1] = tmp;

				position = position + 1;
			}
			else if (key == 'C' || key == 'c')
			{
				// 치트키 사용시 전체 퍼즐을 자동으로 맞춰준다.
				for (int i = 0; i < size*size-1; i++)
				{
					puzzle[i] = i+1;
				}
				puzzle[size*size-1] = 0;
			}
		} // if (_kbhit())

		// 그리기
		system("cls"); // 화면 지우기
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (puzzle[y*size + x] == 0)
					cout << "[ 0 ]\t";
				else
					cout << puzzle[y*size + x] << '\t';
			}
			cout << endl;
		}

		// 완성 체크.
		bool bCompleted = true;
		for (int i = 0; i < size*size-1; i++)
		{
			if (puzzle[i] != i+1)
			{
				bCompleted = false;
				break;
			}
		}

		if (bCompleted)
		{
			cout << "축하합니다. 완성되었습니다." << endl;

			// retry
			cout << "다시하려면 (Y)es, 끝내려면 (N)o" << endl;
			bool bValidInput = false;
			do {
				int key = _getch();
				if (key == 'Y' || key == 'y')
				{
					// 다시 시작하기...
					bValidInput = true;

					// shuffle...
					for (int i = size*size-2; i > 0; i--)
					{
						int index = rand()%i;

						int tmp = puzzle[i];
						puzzle[i] = puzzle[index];
						puzzle[index] = tmp;
					}

					position = size*size - 1;
				}
				else if (key == 'N' || key == 'n')
				{
					// 입력 종료.
					bValidInput = true;
					
					// 전체 게임 종료..
					bExit = true;
				}
			} while (!bValidInput);

		}

	} // while (true)

	cout << "Press any key to exit game.." << endl;
	_getch();
	return 0;
}
