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
	const int user_count = 3;
	UserInfo user[user_count+1];
	int user_index = 1;
	int current_stat = 0;
	char strStat[MAX_STAT][20] = {{"  힘  "},
						 {" 지능 "},
						 {" 민첩 "},
						 {" 체력 "},
						 {"정신력"}};

	// 초기화
	for (int i = 0; i < user_count+1; i++)
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
				if (user[user_index].stat[current_stat] == 5 ||
					user[user_index].total_stat == 0)
					continue;

				user[0].stat[current_stat] += 1;

				user[user_index].total_stat -= 1;
				user[user_index].stat[current_stat] += 1;
			}
			else if (key == '-')
			{
				if (user[user_index].stat[current_stat] == 0)
					continue;

				user[0].stat[current_stat] -= 1;

				user[user_index].total_stat += 1;
				user[user_index].stat[current_stat] -= 1;
			}
			else if (key == 0x1B) // ESC
			{
				user_index++;
				if (user_index == user_count+1)
					user_index = 0;
			}
		}

		// 출력
		system("cls");
		if (user_index == 0)
		{
			cout << "유저들의 평균 정보 : " << endl;
			for (int i = 0; i < MAX_STAT; i++)
			{
				cout << '\t' << strStat[i] << " : " << (user[user_index].stat[i]/user_count) << endl;
			}
		}
		else
		{
			cout << user_index << "번째 유저 정보 : ";
			cout << user[user_index].total_stat << endl;
			for (int i = 0; i < MAX_STAT; i++)
			{
				if (i == current_stat)
					cout << ">>";

				cout << '\t' << strStat[i] << " : " << user[user_index].stat[i] << endl;
			}
		}
	}

	_getch();
	return 0;
}
