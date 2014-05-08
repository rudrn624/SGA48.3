#include "Point.h"

int main(void)
{
	Point o;
	Point pt(5,4);
	Point any(3,5);
	Point some;

	pt.print();
	any.print();

	some = pt + any;

	some.print();

	cout << (pt - any) << endl;

	_getch();
	return 0;
}