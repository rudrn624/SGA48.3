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
	const int blank = 0;

	for (int i = 0; i < size*size; i++)
	{
		board[i] = blank;
	}

	int pos = size*size/2;
	int current = 1;
	bool bExit = false;

	// 내 빙고판 채우기...
	while (!bExit)
	{
		// 입력처리
		if (_kbhit())
		{
			int key = _getch();
			if (key == 'W' || key == 'w')
			{
				if (pos < size)
					continue;

				pos -= size;
			}
			else if (key == 'S' || key == 's')
			{
				if (pos >= size*size-size)
					continue;

				pos += size;
			}
			else if (key == 'A' || key == 'a')
			{
				if (pos%size == 0)
					continue;

				pos -= 1;
			}
			else if (key == 'D' || key == 'd')
			{
				if (pos%size == size-1)
					continue;

				pos += 1;
			}
			else if (key == 0x0D)
			{
				if (board[pos] != blank)
					continue;

				board[pos] = current;
				current++;
				if (current == size*size + 1)
				{
					bExit = true;
				}
			}
			// 자동으로 빙고판 채우기키
			else if (key == 'P' || key == 'p')
			{
				int randombox[size*size];
				int count = size*size - current + 1;
				for (int i = 0; i < count; i++)
				{
					randombox[i] = current + i;
				}
				for (int i = count-1; i > 0; i--)
				{
					int index = rand()%i;

					int tmp = randombox[i];
					randombox[i] = randombox[index];
					randombox[index] = tmp;
				}

				int rand_index = 0;

				// 초기화
				for (int i = 0; i < size*size; i++)
				{
					if (board[i] == blank)
					{
						board[i] = randombox[rand_index];
						rand_index++;
					}
				}

				bExit = true;
			}
		}

		// 내 빙고판 그리기
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

	cout << "대결모드 시작" << endl;
	cout << "대결을 시작하려면 아무키나 누르세요..";
	_getch();

	// 컴퓨터 빙고판을 채우기
	// 초기화
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

	// bingocount[MY_TURN] : 내꺼 빙고 카운트
	// bingocount[COM_TURN] : 컴퓨터꺼 빙고 카운트.
	int bingocount[2] = {0};

	pos = size*size/2;

	// 대결모드 진짜 시작...
	while (true)
	{
		// 입력처리
		if (_kbhit())
		{
			int key = _getch();
			if (key == 'W' || key == 'w')
			{
				if (pos < size)
					continue;

				pos -= size;
			}
			else if (key == 'S' || key == 's')
			{
				if (pos >= size*size - size)
					continue;

				pos += size;
			}
			else if (key == 'A' || key == 'a')
			{
				if (pos%size == 0)
					continue;

				pos -= 1;
			}
			else if (key == 'D' || key == 'd')
			{
				if (pos%size == size - 1)
					continue;

				pos += 1;
			}
			else if (key == 0x0D)
			{
				if (board[pos] == SELECTED)
					continue;

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
		} // if (_kbhit())

		if (turn == COM_TURN)
		{
			// 컴퓨터 빙고판에서 체크할 수 있는 것을 찾는다.
			while (com[com_order[com_order_index]] == SELECTED)
			{
				com_order_index++;
			}

			// 내 빙고판을 체크한다.
			for (int i = 0; i < size*size; i++)
			{
				if (com[com_order[com_order_index]] == board[i])
				{
					board[i] = SELECTED;
					break;
				}
			}

			// 컴퓨터 빙고판을 체크한다.
			com_selected = com[com_order[com_order_index]];

			com[com_order[com_order_index]] = SELECTED;

			turn = MY_TURN;
		}

		// 빙고 카운트 체크
		bingocount[MY_TURN] = 0;
		bingocount[COM_TURN] = 0;
		// 가로
		for (int y = 0; y < size; y++)
		{
			bool IsBingo[2] = {true,true};
			for (int x = 0; x < size; x++)
			{
				if (board[x + y*size] != SELECTED)
				{
					IsBingo[MY_TURN] = false;
				}
				if (com[x + y*size] != SELECTED)
				{
					IsBingo[COM_TURN] = false;
				}
			}
			bingocount[MY_TURN] += int(IsBingo[MY_TURN]);
			bingocount[COM_TURN] += int(IsBingo[COM_TURN]);
		}
		// 세로
		for (int x = 0; x < size; x++)
		{
			bool IsBingo[2] = {true,true};
			for (int y = 0; y < size; y++)
			{
				if (board[x + y*size] != SELECTED)
				{
					IsBingo[MY_TURN] = false;
				}
				if (com[x + y*size] != SELECTED)
				{
					IsBingo[COM_TURN] = false;
				}
			}
			bingocount[MY_TURN] += int(IsBingo[MY_TURN]);
			bingocount[COM_TURN] += int(IsBingo[COM_TURN]);
		}
		// 대각선 
		bool IsBingo[2] = {true,true};
		for (int i = 0; i < size; i++)
		{
			if (board[0 + (size+1)*i] != SELECTED)
			{
				IsBingo[MY_TURN] = false;
			}
			if (com[0 + (size+1)*i] != SELECTED)
			{
				IsBingo[COM_TURN] = false;
			}
		}
		bingocount[MY_TURN] += int(IsBingo[MY_TURN]);
		bingocount[COM_TURN] += int(IsBingo[COM_TURN]);

		// 대각선 /
		IsBingo[MY_TURN] = true;
		IsBingo[COM_TURN] = true;
		for (int i = 0; i < size; i++)
		{
			if (board[size-1 + (size-1)*i] != SELECTED)
			{
				IsBingo[MY_TURN] = false;
			}
			if (com[size-1 + (size-1)*i] != SELECTED)
			{
				IsBingo[COM_TURN] = false;
			}
		}
		bingocount[MY_TURN] += int(IsBingo[MY_TURN]);
		bingocount[COM_TURN] += int(IsBingo[COM_TURN]);

		// 그리기
		// 내꺼 먼저 그리고...
		system("cls");
		cout << "내 빙고판 : " << bingocount[MY_TURN] << endl;
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

		cout << "컴퓨터가 " << com_selected << "를 선택했습니다." << endl;

		// 컴퓨터꺼 그리고...
		cout << "컴퓨터 빙고판 : " << bingocount[COM_TURN] << endl;
		//for (int y = 0; y < size; y++)
		//{
		//	for (int x = 0; x < size; x++)
		//	{
		//		if (com[y*size + x] == SELECTED)
		//			cout << 'X';
		//		else
		//			cout << com[y*size + x];
		//		
		//		cout << '\t';
		//	}
		//	cout << endl;
		//}

		// 승리 판단 체크..
		if (bingocount[MY_TURN] >= 3 && bingocount[COM_TURN] >= 3)
		{
			cout << "비김" << endl;
			break;
		}
		else if (bingocount[MY_TURN] >= 3)
		{
			cout << "이김" << endl;
			break;
		}
		else if (bingocount[COM_TURN] >= 3)
		{
			cout << "짐" << endl;
			break;
		}

	} // while (true)


	_getch();
	return 0;
}
