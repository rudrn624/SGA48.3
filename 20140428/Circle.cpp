#include "define.h"

Circle::Circle()
: _x(0), _y(0), _r(0)
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
void Circle::Draw(char *board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((x-_x)*(x-_x) + (y-_y)*(y-_y) < _r*_r)
				board[y*70 + x] = '|';
		}
		//cout << endl;
	}
}