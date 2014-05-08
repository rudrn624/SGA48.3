#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

enum stat_id
{
	STRNG,		// 힘
	INTEL,		// 지능
	DEX,		// 민첩
	HEALTH,		// 체력
	MENTAL,		// 정신력
	MAX_STAT,
};

struct UserInfo
{
	int stat[MAX_STAT];
	int total_stat;	// 총 능력치
};

int main(void)
{
	//while (true)
	//{
	//	int key = _getch();
	//	cout << hex << key << endl;
	//}

	//return 0;

	UserInfo user[3];
	int user_index = 0;
	int current_stat = 0;
	char strStat[MAX_STAT][20] = {{"  힘  "},
						 {" 지능 "},
						 {" 민첩 "},
						 {" 체력 "},
						 {"정신력"}};

	// 초기화
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < MAX_STAT; j++)
		{
			user[i].stat[j] = 0;
		}
		user[i].total_stat = 15;
	}

	while (true)
	{
		// 입력
		if (_kbhit())
		{
			int key = _getch();
			if (key == 0xE0)
			{
				key = _getch();
				if (key == 0x48) // up arrow
				{
					if (current_stat == 0)
						continue;

					current_stat -= 1;
				}
				else if (key == 0x50) // down arrow
				{
					if (current_stat == MAX_STAT - 1)
						continue;

					current_stat += 1;
				}
			}
			else if (key == '+')
			{
				user[user_index].stat[current_stat] += 1;
			}
			else if (key == '-')
			{
				user[user_index].stat[current_stat] -= 1;
			}
			else if (key == 0x1B) // ESC
			{
				user_index++;
			}
		}

		// 출력
		system("cls");
		cout << (user_index + 1) << "번째 유저 정보 : ";
		cout << user[user_index].total_stat << endl;
		for (int i = 0; i < MAX_STAT; i++)
		{
			if (i == current_stat)
				cout << ">>";

			cout << '\t' << strStat[i] << " : " << user[user_index].stat[i] << endl;
		}
	}

	_getch();
	return 0;
}
