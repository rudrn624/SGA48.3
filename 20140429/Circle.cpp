#include "define.h"

Circle::Circle()
: _x(0), _y(0), _r(0), dx(1)
{
}
void Circle::SetCenter(const int& x, const int& y)
{
	_x = x;
	_y = y;
}
void Circle::SetRadius(const int& r)
{
	_r = r;
}
void Circle::Update()
{
	_x += dx;
	if (_x > 70)
		dx = -1;
	else if (_x < 0)
		dx = 1;
}
void Circle::Draw(char *board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((x-_x)*(x-_x) + 4*(y-_y)*(y-_y) <= 4*_r*_r)
				board[y*70 + x] = '|';
		}
		//cout << endl;
	}
}