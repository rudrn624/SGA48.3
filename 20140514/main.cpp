#include <iostream>
#include <conio.h>
#include <list> // STL
#include "LinkedList.hpp"

using namespace std;

int main(void)
{
	//std::list<int> sample;

	//for (int i = 0; i < 10; i++)
	//{
	//	sample.push_front(i);
	//}

	//std::list<int>::iterator it;

	//for (it = sample.begin(); it != sample.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	LinkedList<int> test;

	for (int i = 0; i < 10; i++)
	{
		test.insert(i);
	}

	test.print();

	LinkedList<int>::iterator it;

	for (it = test.begin(); it != test.end(); it++)
	{
		cout << *it << endl;
	}

	_getch();
	return 0;
}