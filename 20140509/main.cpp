#include <iostream>
#include <conio.h>
#include "Matrix.h"

using namespace std;

int main(void)
{
	Matrix a, b;

	cout << "Matrix a : " << endl;
	a.print();
	cout << "Matrix b : " << endl;
	b.print();

	Matrix c;

	cout << "=====================" << endl;
	cout << "c = a + b" << endl;
	c = a + b;

	cout << "Matrix a : " << endl;
	a.print();
	cout << "Matrix b : " << endl;
	b.print();
	cout << "Matrix c : " << endl;
	c.print();

	cout << "=====================" << endl;
	cout << "c = a - b" << endl;
	c = a - b;

	cout << "Matrix a : " << endl;
	a.print();
	cout << "Matrix b : " << endl;
	b.print();
	cout << "Matrix c : " << endl;
	c.print();

	Matrix d(1.f,2.f,3.f,4.f);

	cout << "=====================" << endl;
	d.print();

	cout << "=====================" << endl;
	cout << "c = a * d" << endl;
	c = a * d;

	cout << "Matrix a : " << endl;
	a.print();
	cout << "Matrix d : " << endl;
	d.print();
	cout << "Matrix c : " << endl;
	c.print();


	cout << "=====================" << endl;
	cout << "c = d * 3" << endl;
	c = d * 3;

//	c = d.operator * ( 3 );

	cout << "Matrix d : " << endl;
	d.print();
	cout << "Matrix c : " << endl;
	c.print();

	cout << "=====================" << endl;
	cout << "c = 3 * d" << endl;
	c = 3 * d;

	cout << "Matrix d : " << endl;
	cout << d << endl;
	cout << "Matrix c : " << endl;
	cout << c << endl;

	cout << "=====================" << endl;
	cout << a << b << c << d << endl;

	_getch();
	return 0;
}