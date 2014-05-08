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

		// �׸���
		system("cls"); // ȭ�� �����
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
