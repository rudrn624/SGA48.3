#include "func.h"

int menu()
{
	// todo
	system("cls");
	int select = 0;
	do {
		cout << "0. Exit" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Delete" << endl;
		cout << "3. List" << endl;
		cin >> select;
		if (select < EXIT || select > LIST)
			cout << "잘못된 메뉴 선택입니다." << endl;
	} while (select < EXIT || select > LIST);

	return select;
}

void Error()
{
	// todo
	cout << "잘못된 접근입니다." << endl;
}

void ItemCopy(Item& dest, const Item& src)
{
	dest.price = src.price;
	strcpy_s(dest.name, 20, src.name);
}

void SafeDelete(ItemPtr& pItem)
{
	if (pItem)
	{
		delete [] pItem;
		pItem = NULL;
	}
}