#include "define.h"

Rectangle::Rectangle()
: _x(0), _y(0), _width(0), _height(0)
{
}
void Rectangle::SetCenter(const int& x, const int& y)
{
	_x = x;
	_y = y;
}
void Rectangle::SetSize(const int& w, const int& h)
{
	_width = w;
	_height = h;
}
void Rectangle::Draw(char *board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((_x - _width/2) <= x && x <= (_x + _width/2) &&
				(_y - _height/2) <= y && y <= (_y + _height/2))
				board[y*70 + x] = '-';
		}
		//cout << endl;
	}
}
