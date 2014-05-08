#include "type.h"
#include "func.h"

int main(void)
{

	for (int i = 0; i < 1000; i++)
	{
		cout << i << endl;
		// todo...

	}


	Item* pInventory = NULL;
	int nItemCount = 0;
	bool bExit = false;

	Load(pInventory, nItemCount);

	// todo...
	while (!bExit)
	{
		int select = menu();

		switch (select)
		{
		case EXIT :
			Save(pInventory, nItemCount);
			SafeDelete(pInventory);
			bExit = true;
			break;
		case INSERT :
			Insert(pInventory, nItemCount);
			break;

		case DELETE :
			Delete(pInventory, nItemCount);
			break;

		case LIST :
			List(pInventory, nItemCount);
			break;

		default :
			Error();
			break;
		}
	}

	_getch();
	return 0;
}