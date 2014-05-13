#include "Circle.h"

Circle::Circle()
: radius(0)
{
}
Circle::Circle(const Point& pt, const int& r)
: center(pt), radius(r)
{
}

void Circle::Draw(char* board)
{
	const char blank = ' ';
	const char mark = '@';
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			Point p(x, y);

			if (radius >= (p ^ center))
				board[y*70 + x] = mark;
		}
	}
}
bool Circle::Collide(Circle* other)
{
	if (radius + other->radius >= (center ^ other->center))
		return true;

	return false;
}
void Circle::Move(const Point& pt)
{
	center = pt;
}
Point Circle::GetPosition() const
{
	return center;
}
