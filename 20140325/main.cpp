#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{

	int current = 2014;
	int birth;

	cout << "�¾ �⵵�� �Է��ϼ��� : ";
	cin >> birth;
	cout << "����� ���̴� " << (current - birth + 1) << "�Դϴ�." << endl;

	_getch();
	return 0;
}