#pragma once

#include "Point.h"
#include "Size.h"

class Circle
{
public :
	Circle();
	Circle(const Point& pt, const Size& s);

	void Draw(char* board);
	bool Collide(Circle* other);

private :
	Point center;
	int radius;
};