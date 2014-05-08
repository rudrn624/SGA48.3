#pragma once

#include <iostream>
#include <conio.h>
#include <cmath> // sqrt
using namespace std;

class Point
{
public :
	Point(const int& _x = 0, const int& _y = 0);
	~Point();

	Point operator + (const Point& obj);
	float operator - (const Point& obj);
	Point& operator = (const Point& obj);
	void print(void);

private :
	int x;
	int y;
};