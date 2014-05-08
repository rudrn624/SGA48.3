#include "func.h"

void List(const ItemPtr& pInven, const int& nCount)
{
	if (nCount == 0)
	{
		cout << "No Item." << endl;
		_getch();
		return;
	}

	// todo
	for (int i = 0; i < nCount; i++)
	{
		cout << (i+1) << ".\t";
		cout << (pInven+i)->name << '\t';
		cout << (pInven+i)->price << endl;
	}

	_getch();
	return;
}
