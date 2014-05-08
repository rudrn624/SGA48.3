#include <iostream>
#include <conio.h>

using namespace std;

struct Item
{
	int price;
	char name[20];
};

int main(void)
{
	Item a[3];

	for (int i = 0; i < 3; i++)
	{
		cout << (i+1) << "번째 아이템 " << endl;
		cout << "이름 : ";
		cin >> a[i].name;
		cout << "가격 : ";
		cin >> a[i].price;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << (i+1) << "번째 아이템 " << endl;
		cout << "이름 : ";
		cout << a[i].name << endl;
		cout << "가격 : ";
		cout << a[i].price << endl;

	}

	_getch();
	return 0;
}