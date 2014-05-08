#include <iostream>
#include <conio.h>

using namespace std;

// 함수(function) y = f(x)
/*
// 함수 선언(declaration)
Return_type FunctionName(argument-list);

// 함수 정의(definition)
Return_type FunctionName(argument-list)
{
	// todo...
}
*/

// pointer
// 0. 동적할당
// 1. 함수인자
// 2. 참조
void foo_value(int a);
void foo_addr(int* a);
void foo_ref(int& a);

int main(void)
{
	int a = 1;

	cout << &a << endl;

	// value
	foo_value(a);
	cout << a << endl;

	// addr
	foo_addr(&a);
	cout << a << endl;

	// reference
	foo_ref(a);
	cout << a << endl;



	_getch();
	return 0;
}

// call by value
void foo_value(int a)
{
	cout << "hello world" << endl;
	cout << &a << endl;
	cout << a << endl;
	a++;
}

// call by address(pointer)
void foo_addr(int* a)
{
	cout << "hello world" << endl;
	cout << a << endl;
	cout << *a << endl;
	(*a)++;
}

// call by reference
void foo_ref(int& a)
{
	cout << "hello world" << endl;
	cout << &a << endl;
	cout << a << endl;
	a++;
}
