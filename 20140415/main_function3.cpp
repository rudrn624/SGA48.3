#include <iostream>
#include <conio.h>

using namespace std;

int foo(int a, int b = 1)
{
	b++;
	a++;
	return (a + b);
}

// error C2668: 'foo' : 오버로드된 함수에 대한 호출이 모호합니다.
int foo(int a)
{
	a--;
	return a;
}

int main(void)
{
	int a = 2;

	a = foo(a, 3);
	cout << a << endl;

	//a = foo(5);
	//cout << a << endl;

	_getch();
	return 0;
}
