#include <iostream>
#include <conio.h>

using namespace std;

int sum(int n)
{
	return n*(n+1)/2;
}

/*
collatz 
f(n) = if (n 짝수) f(n/2);
     = if (n 홀수) f(3*n + 1);
	 = if (n == 1) 종료..
*/

void f(int n)
{
	// 구현...
}


int main(void)
{
	for (int i = 1; i < 1000; i++)
	{
		f(i);
	}

	_getch();
	return 0;
}
