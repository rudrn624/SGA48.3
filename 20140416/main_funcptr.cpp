#include <iostream>
#include <conio.h>

using namespace std;

void foo(void)
{
	cout << "foo func called." << endl;
}

int main(void)
{
	typedef void(*funcptr)(void);

	funcptr a = &foo;

	(*a)();
	

	_getch();
	return 0;
}
