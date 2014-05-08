#include <iostream>
#include <conio.h>

using namespace std;

class Test
{
public :
	// 기본 생성자
	Test()
	{
		cout << "default ctor called." << endl;
	}
	// 복사 생성자
	Test(const Test& o)
	{
		cout << "copy ctor called." << endl;
	}
	// 기본 소멸자
	~Test()
	{
		cout << "default dtor called." << endl;
	}
	// 대입 연산자 재정의.
	Test& operator = (const Test& o)
	{
		cout << "assignment operator called." << endl;

		return *this;
	}
	void bar()
	{
		cout << this << endl;
	}
private :
	int value;
};


void foo(void)
{
	Test a;
	cout << &a << endl;
	a.bar();

	_getch();

	Test b = a;
}

int main(void)
{
	cout << "before foo call." << endl;
	foo();
	cout << "after foo call." << endl;

	_getch();
	return 0;
}
