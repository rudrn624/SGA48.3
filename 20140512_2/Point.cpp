#include "Point.h"

Point::Point(const int& ix/*=-1*/, const int& iy/*=-1*/)
: _x(ix), _y(iy)
{
}
int& Point::x()
{
	return _x;
}
int& Point::y()
{
	return _y;
}
void Point::x(const int& ix)
{
	_x = ix;
}
void Point::y(const int& iy)
{
	_y = iy;
}
Point Point::operator + (const Point& some)
{
	return Point(_x + some._x, _y + some._y);
}
Point& Point::operator += (const Point& some)
{
	_x += some._x;
	_y += some._y;

	return *this;
}
Point& Point::operator -= (const Point& some)
{
	_x -= some._x;
	_y -= some._y;

	return *this;
}
