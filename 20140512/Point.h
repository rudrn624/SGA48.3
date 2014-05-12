#pragma once

class Point
{
public :
	Point(const int& _x = -1, const int& _y = -1);
	int getx() const;
	int gety() const;
	void setx(const int& _x);
	void sety(const int& _y);

	Point operator + (const Point& some);
	Point& operator += (const Point& some);
	Point& operator -= (const Point& some);

private :
	int x;
	int y;
};