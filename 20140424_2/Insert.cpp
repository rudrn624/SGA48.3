#include "func.h"

void Insert(ItemPtr& pInven, int& nCount)
{
	// todo
	Item* pItem = new Item[nCount+1];

	for (int i = 0; i < nCount; i++)
	{
		ItemCopy(*(pItem+i), *(pInven+i));
	}

	cout << "Enter Item Info" << endl;
	cout << "Name : ";
	cin >> (pItem+nCount)->name;
	cout << "Price : ";
	cin >> (pItem+nCount)->price;

	SafeDelete(pInven);

	pInven = pItem;

	nCount++;

	return;
}
