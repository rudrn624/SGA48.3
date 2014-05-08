#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int a = 10;

	int* pA = &a;

	cout << "sizeof(int) : " << sizeof(int) << endl;
	cout << "sizeof(int*) : " << sizeof(int*) << endl;
	cout << "sizeof(char*) : " << sizeof(char*) << endl;
	cout << "------------------------" << endl;

	cout << "  a : " << a << endl;
	cout << " &a : " << &a << endl;
	cout << " pA : " << pA << endl;
	cout << "*pA : " << *pA << endl;
	cout << "&pA : " << &pA << endl;

	*pA = 15;

	cout << "  a : " << a << endl;
	cout << "------------------------" << endl;
	cout << "pA : " << pA << endl;
	cout << "pA + 1 : " << (pA + 1) << endl;

	short b = 3;
	short* pB = &b;

	cout << "pB : " << pB << endl;
	cout << "pB + 1 : " << (pB + 1) << endl;

	char c = 'A';
	char* pC = &c;

	cout << "pC : " << (int*)pC << endl;
	cout << "pC + 1 : " << (int*)(pC + 1) << endl;

	cout << "=------------------------" << endl;
	
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "arr[" << i << "]" <<&arr[i] << endl;
	}

	cout << "arr : " << arr << endl;

	_getch();
	return 0;
}
