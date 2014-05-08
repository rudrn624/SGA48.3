#include "func.h"

void Load(ItemPtr& pInven, int& nCount)
{
	fstream file;

	file.open("item.sav", ios_base::binary | ios_base::in);

	file.read((char*)&nCount, sizeof(int));

	pInven = new Item[nCount];

	for (int i = 0; i < nCount; i++)
	{
		file.read((char*)(pInven + i), sizeof(Item));
	}

	file.close();
}
