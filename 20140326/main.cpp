#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	// ������(operator)
	// + - * / % (��Ģ������)
	//int a = 3;
	//int b = 2;

	//cout << "(a + b) : ";
	//cout << (a + b) << endl;
	//cout << "(a - b) : ";
	//cout << (a - b) << endl;
	//cout << "(a * b) : ";
	//cout << (a * b) << endl;
	//cout << "(a / b) : ";
	//cout << (a / b) << endl;
	//cout << "(a % b) : ";
	//cout << (a % b) << endl;

	//// �ε�ȣ ������(> , <, >=, <=, ==, !=)
	//cout << "(a > b) :";
	//cout << (a > b) << endl;
	//cout << "(a < b) :";
	//cout << (a < b) << endl;
	//cout << "(a >= b) :";
	//cout << (a >= b) << endl;
	//cout << "(a <= b) :";
	//cout << (a <= b) << endl;
	//cout << "(a == b) :";
	//cout << (a == b) << endl;
	//cout << "(a != b) :";
	//cout << (a != b) << endl;

	//// �� ������(&&, ||, !)
	//bool c = true;
	//bool d = false;
	//bool e = true;
	//bool f = false;

	//cout << "(c && d) : ";
	//cout << (c && d) << endl;
	//cout << "(c || d) : ";
	//cout << (c || d) << endl;
	//cout << "(c && e) : ";
	//cout << (c && e) << endl;
	//cout << "(f || d) : ";
	//cout << (f || d) << endl;

	int input;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> input;

	// ���� ������.
	// 2�� ���
	bool A = (input%2 == 0);
	// 3�� ���
	bool B = (input%3 == 0);
	// 5�� ���
	bool C = (input%5 == 0);

	cout << ((A && B && !C)? "�½��ϴ�." : "�ƴմϴ�.") << endl;

	_getch();
	return 0;
}