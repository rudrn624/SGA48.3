#include <iostream>
#include <conio.h>
#include <cstdlib> // rand, srand
#include <ctime> // time

using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	const int size = 3;
	int puzzle[size*size];
	int position = size*size-1;

	// �ʱ�ȭ
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

	// ���ӽ���...
	while (true)
	{
		// �Է�ó��
		if (_kbhit())
		{
			int key = _getch();
			if (key == 'W' || key == 'w')
			{
				int tmp = puzzle[position];
				puzzle[position] = puzzle[position - size];
				puzzle[position - size] = tmp;

				position = position - size;
			}
			else if (key == 'A' || key == 'a')
			{
				int tmp = puzzle[position];
				puzzle[position] = puzzle[position - 1];
				puzzle[position - 1] = tmp;

				position = position - 1;
			}
			else if (key == 'S' || key == 's')
			{
				int tmp = puzzle[position];
				puzzle[position] = puzzle[position + size];
				puzzle[position + size] = tmp;

				position = position + size;
			}
			else if (key == 'D' || key == 'd')
			{
				int tmp = puzzle[position];
				puzzle[position] = puzzle[position + 1];
				puzzle[position + 1] = tmp;

				position = position + 1;
			}
		} // if (_kbhit())

		// �׸���
		system("cls"); // ȭ�� �����
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

		// �ϼ� üũ.
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
			cout << "�����մϴ�. �ϼ��Ǿ����ϴ�." << endl;

			// retry


			break;
		}

	} // while (true)

	_getch();
	return 0;
}
