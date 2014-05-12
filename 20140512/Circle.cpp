#include "Shape.h"

Circle::Circle()
: _r(0), dx(1)
{
}
void Circle::SetRadius(const int& r)
{
	_r = r;
}
void Circle::Update()
{
	pos += Point(dx, 0);

	if (pos.getx() > 70)
		dx = -1;
	else if (pos.getx() < 0)
		dx = 1;
}
void Circle::Draw(char *board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((x-pos.getx())*(x-pos.getx()) + 4*(y-pos.gety())*(y-pos.gety()) <= 4*_r*_r)
				board[y*70 + x] = '|';
		}
		//cout << endl;
	}
}
Shape& Circle::operator >> (char* board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((x-pos.getx())*(x-pos.getx()) + 4*(y-pos.gety())*(y-pos.gety()) <= 4*_r*_r)
				board[y*70 + x] = '|';
		}
		//cout << endl;
	}

	return *this;
}
