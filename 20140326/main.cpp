#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	// 연산자(operator)
	// + - * / % (사칙연산자)
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

	//// 부등호 연산자(> , <, >=, <=, ==, !=)
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

	//// 논리 연산자(&&, ||, !)
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
	cout << "숫자를 입력하세요 : ";
	cin >> input;

	// 삼항 연산자.
	// 2의 배수
	bool A = (input%2 == 0);
	// 3의 배수
	bool B = (input%3 == 0);
	// 5의 배수
	bool C = (input%5 == 0);

	cout << ((A && B && !C)? "맞습니다." : "아닙니다.") << endl;

	_getch();
	return 0;
}