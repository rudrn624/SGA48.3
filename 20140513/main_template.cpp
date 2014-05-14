#include <iostream>
#include <conio.h>

using namespace std;

template<typename T>
void SafeDelete(T& pointer)
{
	cout << "in func" << endl;

	cout << pointer << endl;
	cout << &pointer << endl;

	if (pointer)
	{
		delete [] pointer;
		pointer = NULL;
	}

	cout << "out func" << endl;
}

int main(void)
{
	int* pA = NULL;

	if (pA == NULL)
	{
		pA = new int;
	}


	cout << pA << endl;
	cout << &pA << endl;
	SafeDelete(pA);
	cout << pA << endl;
	cout << &pA << endl;


	_getch();
	return 0;
}