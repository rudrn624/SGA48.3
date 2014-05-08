#include "func.h"

void Delete(ItemPtr& pInven, int& nCount)
{
	if (nCount == 0)
		return;

	// todo
	List(pInven, nCount);

	int select;
	cout << "Select Item to Delete...";
	cin >> select;

	Item* pItem = new Item[nCount-1];

	for (int i = 0, j = 0; i < nCount; i++)
	{
		if (i == select-1)
			continue;

		ItemCopy(*(pItem+j), *(pInven+i));
		j++;
	}

	SafeDelete(pInven);

	pInven = pItem;

	nCount--;

	return;
}

