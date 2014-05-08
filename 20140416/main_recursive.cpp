#include <iostream>
#include <conio.h>

using namespace std;

void foo(int n, int depth = 0)
{
	// 종료조건
	if (n == 0)
		return;

	for (int i = 0; i < depth; i++)
	{
		cout << ' ';
	}
	cout << n << endl;
	foo(n-1, depth+1);

	for (int i = 0; i < depth; i++)
	{
		cout << ".";
	}
	cout << endl;
}

int sum(int n)
{
	if (n == 0)
		return 0;
	
	if (n%2 == 1)
		return sum(n-1);

	return sum(n-2) + n;
}

// factorial : 5! = 5*4*3*2*1 = 120
int factorial(int n)
{
	if (n == 1)
		return 1;

	return factorial(n-1)*n;
}

// recursive function : 재귀함수.
int main(void)
{
	cout << sum(10) << endl;

	_getch();
	return 0;
}
