#include "define.h"

Triangle::Triangle()
: _x(0), _y(0), _size(0)
{
}
void Triangle::SetSize(const int& size)
{
	_size = size;
}
void Triangle::SetCenter(const int& x, const int& y)
{
	_x = x;
	_y = y;
}
void Triangle::Update()
{
}
void Triangle::Draw(char* board)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < 2*i + 1; j++)
		{
			int pos = (_y + i - _size/2)*70 + _x + j - (2*i + 1)/2;
			if (pos >= 70*20)
				continue;
			else
				board[pos] = '*';
		}
	}
}
void Triangle::Move(const int& dx, const int& dy)
{
	_x = _x + dx;
	_y = _y + dy;
}
void Triangle::GetPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

