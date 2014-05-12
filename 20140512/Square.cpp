#include "Shape.h"

Square::Square()
: _width(0), _height(0), dy(1)
{
}
void Square::SetSize(const int& w, const int& h)
{
	_width = w;
	_height = h;
}
void Square::Update()
{
	pos += Point(0, dy);

	if (pos.gety() > 20)
		dy = -1;
	else if (pos.gety() < 0)
		dy = 1;
}
void Square::Draw(char *board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((pos.getx() - _width/2) <= x && x <= (pos.getx() + _width/2) &&
				(pos.gety() - _height/2) <= y && y <= (pos.gety() + _height/2))
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
Shape& Square::operator >> (char* board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((pos.getx() - _width/2) <= x && x <= (pos.getx() + _width/2) &&
				(pos.gety() - _height/2) <= y && y <= (pos.gety() + _height/2))
			{
				if (board[y*70+x] == ' ')
					board[y*70 + x] = '-';
				else
					board[y*70+x] = '+';
			}
		}
		//cout << endl;
	}

	return *this;
}
