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
		cout << (i+1) << "��° ������ " << endl;
		cout << "�̸� : ";
		cin >> a[i].name;
		cout << "���� : ";
		cin >> a[i].price;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << (i+1) << "��° ������ " << endl;
		cout << "�̸� : ";
		cout << a[i].name << endl;
		cout << "���� : ";
		cout << a[i].price << endl;

	}

	_getch();
	return 0;
}