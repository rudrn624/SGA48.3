#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int input;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> input;

	bool A = (input%2 == 0);
	bool B = (input%3 == 0);
	bool C = (input%8 == 0);
	bool D = (input%12 == 0);

	bool E = (A && B && !C && !D);

	cout << ((E)? "�¾ƿ�" : "�ƴѵ���.") << endl;

	_getch();
	return 0;
}