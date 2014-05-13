#pragma once

#include <math.h>

class Point
{
public :
	Point(const int& x = -1, const int& y = -1);
	int& x();
	int& y();
	void x(const int& ix);
	void y(const int& iy);

	Point operator + (const Point& some);
	Point operator - (const Point& some);
	float operator ^ (const Point& some);
	Point& operator += (const Point& some);
	Point& operator -= (const Point& some);

private :
	int _x;
	int _y;
};