#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	char name[20];
	int birth;
	char phone[30];

	cout << "이름 : ";
	cin >> name;
	cout << "태어난년도 : ";
	cin >> birth;
	cout << "전화번호 : ";
	cin >> phone;

	cout << name << endl;
	cout << (2014-birth+1) << endl;
	cout << phone << endl;

	_getch();
	return 0;
}
