#include <iostream>
#include <conio.h>
#include "LinkedList.hpp"

using namespace std;

int main(void)
{
	LinkedList<int> test;

	for (int i = 0; i < 10; i++)
	{
		test.insert(i);
	}

	test.print();

	_getch();
	return 0;
}