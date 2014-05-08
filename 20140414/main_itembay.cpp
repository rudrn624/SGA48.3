#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct ItemInfo
{
	char name[20];
	int price;
};

enum msg_id
{
	WRONG_RANGE,
	INPUT_COMMAND,
	BYE,
	EMPTY_BAY,
	ITEM_NAME,
	ITEM_PRICE,
	SELECT_ITEM,
};

enum command_id
{
	CMD_EXIT,
	CMD_INSERT,
	CMD_DELETE,
	CMD_LIST,
	CMD_MAX,
};

int main(void)
{
	const char* strMenu[] = {
		"0. 종료",
		"1. 아이템추가",
		"2. 아이템삭제",
		"3. 아이템확인"
	};
	const char* msg[] = {
		"잘못된 선택입니다.",
		"메뉴를 선택하세요.",
		"상점을 이용해 주셔서 감사합니다.",
		"등록된 아이템이 없습니다.",
		"아이템이름 : ",
		"아이템가격 : ",
		"삭제할 아이템을 선택하세요.",
	};

	ItemInfo* pBay = NULL;
	int command = 0;
	int ItemCount = 0;

	while (true)
	{
		// 메뉴출력
		system("cls");
		for (int i = 0; i < CMD_MAX; i++)
		{
			cout << strMenu[i] << endl;
		}
		
		// 메뉴를 입력받는다.
		do {
			cout << msg[INPUT_COMMAND];
			cin >> command;
			if (command < 0 || command > 3)
				cout << msg[WRONG_RANGE] << endl;
		} while (command < 0 || command > 3);

		// 메뉴에 따른 처리
		if (command == CMD_EXIT)
		{
			if (pBay != NULL)
			{
				delete [] pBay;
				pBay = NULL;
			}

			cout << msg[BYE] << endl;
			break;
		}
		else if (command == CMD_INSERT)
		{
			ItemInfo* pItem = new ItemInfo[ItemCount+1];

			for (int i = 0; i < ItemCount; i++)
			{
				strcpy_s((pItem+i)->name, 20, (pBay+i)->name);
				(pItem+i)->price = (pBay+i)->price;
			}

			cout << msg[ITEM_NAME];
			cin >> (pItem+ItemCount)->name;
			cout << msg[ITEM_PRICE];
			cin >> (pItem+ItemCount)->price;

			if (pBay != NULL)
			{
				delete [] pBay;
				pBay = NULL;
			}

			pBay = pItem;

			ItemCount++;
		}
		else if (command == CMD_DELETE)
		{
			if (pBay == NULL)
			{
				cout << msg[EMPTY_BAY] << endl;
				_getch();
			}
			else
			{
				for (int i = 0; i < ItemCount; i++)
				{
					cout << (i+1) << (pBay + i)->name << '\t' << (pBay + i)->price << endl;
				}
				int select;
				do {
					cout << msg[SELECT_ITEM];
					cin >> select;
					if (select < 1 || select > ItemCount)
						cout << msg[WRONG_RANGE] << endl;
				} while (select < 1 || select > ItemCount);

				// 제대로 입력받았다면....
				ItemInfo* pItem = new ItemInfo[ItemCount-1];

				for ()
				{
				}

				if (pBay != NULL)
				{
					delete [] pBay;
					pBay = NULL;
				}

				pBay = pItem;

				ItemCount--;
			}
		}
		else if (command == CMD_LIST)
		{
			if (pBay == NULL)
			{
				cout << msg[EMPTY_BAY] << endl;
				_getch();
			}
			else
			{
				for (int i = 0; i < ItemCount; i++)
				{
					cout << (i+1) << (pBay + i)->name << '\t' << (pBay + i)->price << endl;
				}
				_getch();
			}
		}
	}

	_getch();
	return 0;
}