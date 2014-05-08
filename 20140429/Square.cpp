#include "define.h"

Square::Square()
: _x(0), _y(0), _width(0), _height(0)
, dy(1)
{
}
void Square::SetCenter(const int& x, const int& y)
{
	_x = x;
	_y = y;
}
void Square::SetSize(const int& w, const int& h)
{
	_width = w;
	_height = h;
}
void Square::Update()
{
	_y += dy;
	if (_y > 20)
		dy = -1;
	else if (_y < 0)
		dy = 1;
}
void Square::Draw(char *board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((_x - _width/2) <= x && x <= (_x + _width/2) &&
				(_y - _height/2) <= y && y <= (_y + _height/2))
			{
				if (board[y*70+x] == ' ')
					board[y*70 + x] = '-';
				else
					board[y*70+x] = '+';
			}
		}
		//cout << endl;
	}
}
