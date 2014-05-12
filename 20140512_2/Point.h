#pragma once

class Point
{
public :
	Point(const int& ix = -1, const int& iy = -1);
	int& x();
	int& y();
	void x(const int& ix);
	void y(const int& iy);

	Point operator + (const Point& some);
	Point& operator += (const Point& some);
	Point& operator -= (const Point& some);

private :
	int _x;
	int _y;
};