#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

// Item �̶�� ����ü Ÿ���� ����.
struct Item
{
	int price;
	char name[20];
};

// ����ü : structure.
int main(void)
{
	// ����ü ���� ����..
	Item myItem;

	// ����ü ������ �� ����..
	myItem.price = 150;
	strcpy_s(myItem.name, 20, "hello");

	// ����ü ������ ���� ���...
	cout << myItem.price << ", " << myItem.name << endl;

	_getch();
	return 0;
}
