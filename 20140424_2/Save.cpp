#include "func.h"

void Save(const ItemPtr& pInven, const int& nCount)
{
	fstream file;

	file.open("item.sav", ios_base::binary | ios_base::out);

	file.write((const char*)&nCount, sizeof(int));

	for (int i = 0; i < nCount; i++)
	{
		file.write((const char*)(pInven + i), sizeof(Item));
	}

	file.close();
}
