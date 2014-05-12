#include "Point.h"

Point::Point(const int& _x/*=-1*/, const int& _y/*=-1*/)
: x(_x), y(_y)
{
}
int Point::getx() const
{
	return x;
}
int Point::gety() const
{
	return y;
}
void Point::setx(const int& _x)
{
	x = _x;
}
void Point::sety(const int& _y)
{
	y = _y;
}
Point Point::operator + (const Point& some)
{
	return Point(x + some.x, y + some.y);
}
Point& Point::operator += (const Point& some)
{
	x += some.x;
	y += some.y;

	return *this;
}
Point& Point::operator -= (const Point& some)
{
	x -= some.x;
	y -= some.y;

	return *this;
}
