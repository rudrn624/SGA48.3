#pragma once

#include "Point.h"
#include "Size.h"

class Circle
{
public :
	Circle();
	Circle(const Point& pt, const int& r);

	Point GetPosition() const;

	void Draw(char* board);
	bool Collide(Circle* other);
	void Move(const Point& pt);

private :
	Point center;
	int radius;
};