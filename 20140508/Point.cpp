#include "Point.h"

Point::Point(const int& _x/*=0*/, const int& _y/*=0*/)
: x(_x), y(_y)
{
}
Point::~Point()
{
}
Point Point::operator + (const Point& obj)
{
	//Point tmp(*this);

	//tmp.x = tmp.x + obj.x;
	//tmp.y = tmp.y + obj.y;
	Point tmp;

	tmp.x = x + obj.x;
	tmp.y = y + obj.y;

	return tmp;
}
float Point::operator - (const Point& obj)
{
	return sqrt(float((x-obj.x)*(x-obj.x) + (y-obj.y)*(y-obj.y)));
}
Point& Point::operator = (const Point& obj)
{
	x = obj.x;
	y = obj.y;

	return *this;
}
void Point::print()
{
	cout << "(" << x << ", ";
	cout << y << ")" << endl;
}