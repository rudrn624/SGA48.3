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
			// 등록된 아이템이 하나도 없다면..
			if (pBay == NULL)
			{
				cout << msg[EMPTY_BAY] << endl;
				_getch();
			}
			// 등록된 아이템이 뭐라도 있다면..
			else
			{
				// 등록된 아이템을 출력해주고...
				for (int i = 0; i < ItemCount; i++)
				{
					cout << (i+1) << (pBay + i)->name << '\t' << (pBay + i)->price << endl;
				}
				// 그 중에서 삭제할 아이템을 선택받는다.
				int select;
				do {
					cout << msg[SELECT_ITEM];
					cin >> select;
					if (select < 1 || select > ItemCount)
						cout << msg[WRONG_RANGE] << endl;
				} while (select < 1 || select > ItemCount);

				// 제대로 입력받았다면....
				// 만약에 등록된 아이템 총수가 1개라면..
				ItemInfo* pItem = NULL;
				if (ItemCount == 1)
				{
					// 기존의 상점에 할당된 메모리만 해제하고 종료.
					if (pBay != NULL)
					{
						delete [] pBay;
						pBay = NULL;
					}

					ItemCount--;

					continue;
				}
				// 그렇지 않으면
				else
				{
					// 하나가 적은 아이템을 저장할 공간을 할당한다.
					pItem = new ItemInfo[ItemCount-1];
				}

				// 삭제할 아이템을 제외하고 나머지 아이템들을
				// 새로운 공간에 복사한다.
				for (int i = 0, j = 0; i < ItemCount; i++)
				{
					if (i+1 == select)
					{
						continue;
					}
					strcpy_s((pItem+j)->name, 20, (pBay+i)->name);
					(pItem+j)->price = (pBay+i)->price;

					j++;
				}

				// 기존의 상점에 할당된 메모리를 해제하고..
				if (pBay != NULL)
				{
					delete [] pBay;
					pBay = NULL;
				}

				// 새롭게 할당한 메모리 주소로 연결시켜준다.
				pBay = pItem;

				// 등록 아이템 갯수는 하나 감소시킨다.
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