#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	const int size = 5;
	int board[size*size];
	int com[size*size];

	for (int i = 0; i < size*size; i++)
	{
		board[i] = 0;
	}

	int pos = size*size/2;
	int current = 1;
	bool bExit = false;

	// �� ������ ä���...
	while (!bExit)
	{
		// �Է�ó��
		if (_kbhit())
		{
			int key = _getch();
			if (key == 'W' || key == 'w')
			{
				pos -= size;
			}
			else if (key == 'S' || key == 's')
			{
				pos += size;
			}
			else if (key == 'A' || key == 'a')
			{
				pos -= 1;
			}
			else if (key == 'D' || key == 'd')
			{
				pos += 1;
			}
			else if (key == 0x0D)
			{
				board[pos] = current;
				current++;
				if (current == size*size + 1)
				{
					bExit = true;
				}
			}
			// �ڵ����� ������ ä���Ű
			else if (key == 'P' || key == 'p')
			{
				// �ʱ�ȭ
				for (int i = 0; i < size*size; i++)
				{
					board[i] = i+1;
				}
				// shuffle
				for (int i = size*size-1; i > 0; i--)
				{
					int index = rand()%i;

					int tmp = board[i];
					board[i] = board[index];
					board[index] = tmp;
				}

				bExit = true;
			}
		}

		// �� ������ �׸���
		system("cls");
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (pos == (y*size + x))
					cout << '[' << board[y*size + x] << ']';
				else
					cout << board[y*size + x];
				
				cout << '\t';
			}
			cout << endl;
		}
	}

	cout << "����� ����" << endl;
	cout << "����� �����Ϸ��� �ƹ�Ű�� ��������..";
	_getch();

	// ��ǻ�� �������� ä���
	// �ʱ�ȭ
	for (int i = 0; i < size*size; i++)
	{
		com[i] = i+1;
	}
	// shuffle
	for (int i = size*size-1; i > 0; i--)
	{
		int index = rand()%i;

		int tmp = com[i];
		com[i] = com[index];
		com[index] = tmp;
	}

	int com_order[size*size];
	for (int i = 0; i < size*size; i++)
	{
		com_order[i] = i;
	}
	for (int i = size*size-1; i > 0; i--)
	{
		int index = rand()%i;

		int tmp = com_order[i];
		com_order[i] = com_order[index];
		com_order[index] = tmp;
	}

	int com_order_index = 0;
	const int MY_TURN = 0;
	const int COM_TURN = 1;

	int turn = MY_TURN;
	int com_selected = 0;

	const int SELECTED = 0;

	// ����� ��¥ ����...
	while (true)
	{
		// �Է�ó��
		if (_kbhit())
		{
			int key = _getch();
			if (key == 'W' || key == 'w')
			{
				pos -= size;
			}
			else if (key == 'S' || key == 's')
			{
				pos += size;
			}
			else if (key == 'A' || key == 'a')
			{
				pos -= 1;
			}
			else if (key == 'D' || key == 'd')
			{
				pos += 1;
			}
			else if (key == 0x0D)
			{
				for (int i = 0; i < size*size; i++)
				{
					if (com[i] == board[pos])
					{
						com[i] = SELECTED;
						break;
					}
				}

				board[pos] = SELECTED;

				turn = COM_TURN;
			}
		}

		if (turn == COM_TURN)
		{
			// ��ǻ�� �����ǿ��� üũ�� �� �ִ� ���� ã�´�.
			while (com[com_order[com_order_index]] == SELECTED)
			{
				com_order_index++;
			}

			// �� �������� üũ�Ѵ�.
			for (int i = 0; i < size*size; i++)
			{
				if (com[com_order[com_order_index]] == board[i])
				{
					board[i] = SELECTED;
					break;
				}
			}

			// ��ǻ�� �������� üũ�Ѵ�.
			com_selected = com[com_order[com_order_index]];

			com[com_order[com_order_index]] = SELECTED;

			turn = MY_TURN;
		}

		// �׸���
		// ���� ���� �׸���...
		system("cls");
		cout << "�� ������ : " << endl;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (pos == y*size + x)
					cout << '[';

				if (board[y*size + x] == SELECTED)
					cout << 'X';
				else
					cout << board[y*size + x];
				
				if (pos == y*size + x)
					cout << ']';

				cout << '\t';
			}
			cout << endl;
		}
		cout << endl;

		cout << "��ǻ�Ͱ� " << com_selected << "�� �����߽��ϴ�." << endl;

		// ��ǻ�Ͳ� �׸���...
		cout << "��ǻ�� ������ : " << endl;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (com[y*size + x] == SELECTED)
					cout << 'X';
				else
					cout << com[y*size + x];
				
				cout << '\t';
			}
			cout << endl;
		}
	}


	_getch();
	return 0;
}
