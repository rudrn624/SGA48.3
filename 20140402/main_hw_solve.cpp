#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	char name[20];
	int birth;
	char phone[30];

	cout << "�̸� : ";
	cin >> name;
	cout << "�¾�⵵ : ";
	cin >> birth;
	cout << "��ȭ��ȣ : ";
	cin >> phone;

	cout << name << endl;
	cout << (2014-birth+1) << endl;
	cout << phone << endl;

	_getch();
	return 0;
}
