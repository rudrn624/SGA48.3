#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	//for (A ; B; C)
	//	D;

	//int i = 0;

	//while (i < 9)
	//{
	//	cout << 2 << " x " << (i+1) << " = " << 2*(i+1) << endl;
	//	i++;
	//}

	// do while.

	cout << "0. Exit " << endl;
	cout << "1. Save " << endl;
	cout << "2. Load " << endl;
	cout << "3. Play " << endl;

	int selectMenu = 0;
	do 
	{
		cout << "메뉴를 선택하세요 : ";
		cin >> selectMenu;
		if (!(selectMenu >= 0 && selectMenu <= 3))
			cout << "메뉴를 잘못 선택했습니다." << endl;

	} while(!(selectMenu >= 0 && selectMenu <= 3));

	//while (!(selectMenu >= 0 && selectMenu <= 3))
	//{
	//	cout << "메뉴를 선택하세요 : ";
	//	cin >> selectMenu;
	//	if (!(selectMenu >= 0 && selectMenu <= 3))
	//		cout << "메뉴를 잘못 선택했습니다." << endl;
	//}

	_getch();
	return 0;
}
